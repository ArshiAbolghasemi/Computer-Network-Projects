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
    FD_ZERO(&(this->master));
    FD_SET(0, &(this->master));
    FD_SET(cli_fd, &(this->master));
    while(1)
    {
        temp = this->master;
        selectSysCall(cli_fd+1, &temp);
        if(FD_ISSET(0, &temp))
        {
            // clientRecieveHandle(); // Rcv Msg logic
        }
        else if(FD_ISSET(cli_fd, &temp))
        {
            // clientSendHandle(); // Send Msg logic
        }
    }    
}