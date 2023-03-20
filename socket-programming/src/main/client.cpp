#include "../../include/Entity/ClientEntity.hpp"

int main()
{
   ClientEntity client;
   int cli_fd = client.serverConnect((int)SERVER_PORT,
    (const char*)SERVER_ADDRESS);
   client.runClient(cli_fd); 
}