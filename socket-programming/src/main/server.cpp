#include "../../include/service/ServerService.hpp"
#include "../../include/Entity/ServerEntity.hpp"

int main()
{
    ServerEntity server;
    int serverFD = 
        server.setupServer(SERVER_ADDRESS, SERVER_PORT);
    server.runServer(serverFD);
}
