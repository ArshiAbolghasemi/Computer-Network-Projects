#include "../../include/Entity/ServerEntity.hpp"

int main()
{
    ServerEntity server;
    int serverFD = 
        server.setupServer((const char*)SERVER_ADDRESS, (int)SERVER_PORT);
    server.runServer(serverFD);
}
