#include "../../include/service/ClientService.hpp"

int main()
{
    int cli_fd = serverConnect(SERVER_PORT, 
        SERVER_ADDRESS);
    runClient(cli_fd);
}