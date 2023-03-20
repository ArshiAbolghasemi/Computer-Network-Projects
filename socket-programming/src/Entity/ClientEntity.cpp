#include "../../include/Entity/ClientEntity.hpp"

int ClientEntity::serverConnect(int port,
    const char* host)
{
    int cli_fd = createSocket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in cli = createSocketAddressIn(
        port, host);
    setSocketOption(cli_fd, SOL_SOCKET, SO_REUSEADDR);
    setSocketOption(cli_fd, SOL_SOCKET, SO_REUSEPORT);
    connectToSocket(cli_fd, cli);
    return cli_fd; 
}

void ClientEntity::runClient(int cli_fd)
{
    fd_set temp;
    FD_ZERO(&_master);
    FD_SET(0, &_master);
    FD_SET(cli_fd, &_master);
    while(1)
    {
        temp = _master;
        select(cli_fd+1, &temp, NULL, NULL, NULL);
        if(FD_ISSET(0, &temp))
        {
            sendHandle(cli_fd); // Send Msg logic
        }
        else if(FD_ISSET(cli_fd, &temp))
        {
            receiveHandle(cli_fd); // Rcv Msg logic
        }
    }    
}

void ClientEntity::receiveHandle(int fd)
{
    char buffer[MAX_BUFFER_LENGTH];
    memset(buffer, 0, MAX_BUFFER_LENGTH);
    readSocket(fd, buffer);
    if(strncmp(buffer, (const char*)NO_PAT, 
        strlen(NO_PAT)) == 0)
    {
        // NOTHING
        return;
    }
    else if(strncmp(buffer, (const char*)
        FIRST_MENU_PAT, strlen(FIRST_MENU_PAT)) == 0)
    {
        _status = FIRST_MENU_PAT;
        // FIRST MENU HANDLE
        FMenuProtocol();
        return;
    }
    else if(strncmp(buffer, (const char*)
        SIGNIN_PAT, strlen(SIGNIN_PAT)) == 0)
    {
        _status = SIGNIN_PAT;
        SignInProtocol();
        return;
    }
    else if(strncmp(buffer, (const char*)
        SIGNUP_PAT, strlen(SIGNUP_PAT)) == 0)
    {
        _status = SIGNUP_PAT;
        // protocol
    }
    else if(strncmp(buffer, (const char*)
        ERR_PAT, strlen(ERR_PAT)) == 0)
    {
        ErrorProtocol(buffer);
        return;
    }
    else if(strncmp(buffer, SUC_PAT, strlen(SUC_PAT)) == 0)
    {
        std::string s = StringService::deTokenize(
            SUC_PAT, buffer);
        printByLookup(std::stoi(s));
    }
    else if(strncmp(buffer, MAIN_MENU, strlen(MAIN_MENU)))
    {
        MainMenuProtocol();
    }
}

void ClientEntity::sendHandle(int srv_fd)
{
    char buffer[MAX_BUFFER_LENGTH];
    char send_buf[MAX_BUFFER_LENGTH];
    memset(buffer, 0, MAX_BUFFER_LENGTH);
    memset(send_buf, 0, MAX_BUFFER_LENGTH);
    readSocket(0, buffer);
    strcpy(send_buf, 
    StringService::addStatus(buffer, _status).c_str());
    sendMsg(srv_fd, send_buf);
}

void ClientEntity::FMenuProtocol()
{
    std::cout << WELCOME;
    std::cout << INDICATOR;
}

void ClientEntity::SignInProtocol()
{
    std::cout << COMMAND << SIGNIN_OPTION
        << HELP << SIGNIN_HELP << INDICATOR;
}

void ClientEntity::ErrorProtocol(const char* buf)
{
    // error handler
    std::string errNum = 
        StringService::deTokenize(ERR_PAT, buf);
    printByLookup(std::stoi(errNum));
    if(_status == FIRST_MENU_PAT)
    {
        FMenuProtocol();
    }
    else if(_status == SIGNIN_PAT)
    {
        SignInProtocol();
    }
    else if(_status == SIGNUP_PAT)
    {
        // SignUpProtocol();
    }
}

void ClientEntity::printByLookup(int lookup)
{
    std::cout << ERR_MSG << lookup << ": ";
    std::cout << errLookup[lookup];
}

void ClientEntity::MainMenuProtocol()
{
    std::cout << MAIN;
}