#include "../../include/service/ServerService.hpp"

int setupServer()
{
    int serverFD = createSocket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in srv = createSocketAddressIn(
        SERVER_PORT, SERVER_ADDRESS);
    setSocketOption(serverFD, SOL_SOCKET, SO_REUSEADDR);
    setSocketOption(serverFD, SOL_SOCKET, SO_REUSEPORT);
    bindSocket(serverFD, srv);
    listenToClient(serverFD, MAX_CLIENT_LISTEN_TO);
    return serverFD;
}

void runServer(int serverFD)
{
    fd_set master, temp;
    FD_ZERO(&master);
    int max_ind = serverFD;
    while(1)
    {
        temp = master;
        selectSysCall(max_ind+1, &temp);
        for(int i = 0; i <= max_ind; i++)
        {
            if(FD_ISSET(i, &temp))
            {
                if(i == serverFD)
                {
                    int cli_fd = newClientHandle(
                        &master, serverFD);
                    if(cli_fd > max_ind)
                    {
                        max_ind = cli_fd;
                    }
                }
                else
                {
                    manageClient();
                }
            }
        }
    }
}

int newClientHandle(fd_set* master, int serverFD)
{
    int client_fd = acceptClient(serverFD);
    FD_SET(client_fd, master);
    sendMsg(client_fd, WELCOME);
}

void manageClient()
{
    // client managing logic
}