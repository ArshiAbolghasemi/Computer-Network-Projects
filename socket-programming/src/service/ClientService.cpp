#include "../../include/service/ClientService.hpp"

int serverConnect(int port, const char* host)
{
    int cli_fd = createSocket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in cli = createSocketAddressIn(
        SERVER_PORT, SERVER_ADDRESS);
    setSocketOption(cli_fd, SOL_SOCKET, SO_REUSEADDR);
    setSocketOption(cli_fd, SOL_SOCKET, SO_REUSEPORT);
    connectToSocket(cli_fd, cli);
}

void runClient(int cli_fd)
{
    fd_set master, temp;
    FD_ZERO(&master);
    FD_SET(0, &master);
    FD_SET(cli_fd, &master);
    while(1)
    {
        temp = master;
        selectSysCall(cli_fd+1, &temp);
        if(FD_ISSET(0, &temp))
        {
            clientRecieveHandle(); // Rcv Msg logic
        }
        else if(FD_ISSET(cli_fd, &temp))
        {
            clientSendHandle(); // Send Msg logic
        }
    }
}