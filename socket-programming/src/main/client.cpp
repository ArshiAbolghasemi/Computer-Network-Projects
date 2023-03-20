#include "../../include/Entity/ClientEntity.hpp"

int main()
{
   ClientEntity client;
   int cli_fd = client.serverConnect(SERVER_PORT,
    SERVER_ADDRESS);
   client.runClient(cli_fd); 
}