#include "../../include/Entity/ServerEntity.hpp"



int ServerEntity::setupServer(const char* add, int port)
{
    int serverFD = createSocket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in srv = createSocketAddressIn(
        port, add);
    setSocketOption(serverFD, SOL_SOCKET, SO_REUSEADDR);
    setSocketOption(serverFD, SOL_SOCKET, SO_REUSEPORT);
    bindSocket(serverFD, srv);
    listenToClient(serverFD, MAX_CLIENT_LISTEN_TO);
    return serverFD;
}

void ServerEntity::setTime()
{
    std::cout << COMMAND << SET_TIME;
    std::cout << HELP << SET_TIME_HELP;
    std::cout << INDICATOR;
    std::string line;
    std::getline(std::cin, line, '\n');
    if(ErrorChecker::setTimeCheck(line) == false)
    {
        // ErrorHandler::
        perror("bad Time");
        return;
    }
    _serverDate = DateTime::toDate(
        StringService::parseStringByDelim(line, ' ')[1]);
}

void ServerEntity::runServer(int serverFD)
{
    setTime();
    fd_set temp;
    FD_ZERO(&_master);
    FD_SET(serverFD, &_master);
    int max_ind = serverFD;
    while(1)
    {
        temp = _master;
        select(max_ind+1, &temp, NULL, NULL, NULL);
        for(int i = 0; i <= max_ind; i++)
        {
            if(FD_ISSET(i, &temp))
            {
                if(i == serverFD)
                {
                    int cli_fd = newClientHandle(
                        serverFD);
                    if(cli_fd > max_ind)
                    {
                        max_ind = cli_fd;
                    }
                }
                else
                {
                    manageClient(i);
                }
            }
        }
    }
}

int ServerEntity::newClientHandle(int serverFD)
{
    int client_fd = acceptClient(serverFD);
    FD_SET(client_fd, &_master);
    sendMsg(client_fd, (const char*) FIRST_MENU_PAT);
    return client_fd;
}

std::vector<UserEntity*> ServerEntity::initClientsFromJson()
{
    std::string conf = "../../config";
    std::ifstream file(conf + 
        UserEntity::getJsonFilePath());
    std::vector<UserEntity*> res;
    if(file.good())
    {
        nlohmann::json j;
        file >> j;
        for(auto us: j["users"])
        {
            res.push_back(UserEntity::getInstance(us));
        }
        return res;
    }
    perror("file not open");
    return res;
}

std::vector<HotelRoomEntity*> ServerEntity::initHotelRoomsFromJson()
{
    std::string conf = "../../config";
    std::ifstream file(conf + 
        UserEntity::getJsonFilePath());
    std::vector<HotelRoomEntity*> res;
    if(file.good())
    {
        nlohmann::json j;
        file >> j;
        for(auto us: j["users"])
        {
            res.push_back(HotelRoomEntity::getInstance(us));
        }
        return res;
    }
    perror("file not open");
    return res;
}

void ServerEntity::manageClient(int fd)
{
    char buffer[MAX_BUFFER_LENGTH];
    memset(buffer, 0, MAX_BUFFER_LENGTH);
    readSocket(fd, buffer);
    if(strncmp(buffer, (const char*)FIRST_MENU_PAT,
        strlen(FIRST_MENU_PAT)) == 0)
    {
        FMenuHandle(buffer, fd);
    }
    else if(strncmp(buffer, (const char*)SIGNIN_PAT,
        strlen(SIGNIN_PAT)) == 0)
    {
        SInHandle(buffer, fd);
    }
    else if(strncmp(buffer, (const char*)SIGNUP_PAT,
        strlen(SIGNUP_PAT)) == 0)
    {

    }
    else
    {

    }
}

void ServerEntity::FMenuHandle(const char* buf, int fd)
{
    std::string data = StringService::deTokenize(
        FIRST_MENU_PAT, buf);
    if(data == "1\n")
    {
        sendMsg(fd, (const char*)SIGNUP_PAT);
    }
    else if(data == "2\n")
    {
        sendMsg(fd, (const char*)SIGNIN_PAT);
    }
    else
    {
        sendMsg(fd, (const char*)ERR_PAT);
    }
}

void ServerEntity::SInHandle(const char* buf, int fd)
{
    std::string data = StringService::deTokenize(SIGNIN_PAT, buf);
    data.pop_back(); // for \n in the end
    UserEntity* cur_usr = ErrorChecker::signInCheck(data); 
    if(cur_usr == nullptr)
    {
        sendStatus(INVALID_CRED, ERR_PAT, fd);
        return;
    }
    else
    {
        for(auto usr : uVec)
        {
            if(cur_usr->usrAuth(usr->getName(), 
                usr->getPassword()))
            {
                usr->setFileDescriptor(fd);
                sendStatus(GOOD_SIGNIN, SUC_PAT, fd);
                sleep(0.3);
                sendStatus(0, MAIN_MENU, fd);
                return;
            }
        }
        perror("Undefined by user Auth");
        return;
    }
}

void ServerEntity::sendStatus(int stNum, 
    std::string status, int fd)
{
    std::string s_buf;
    if(stNum != 0)
    {
    s_buf = 
    StringService::addStatus(std::to_string(stNum).c_str(),
        status);
    }
    else
    {
        s_buf = status;
    }
    send(fd, s_buf.c_str(), s_buf.size(), 0);
}