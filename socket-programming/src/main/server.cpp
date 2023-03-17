#include "../../include/service/ServerService.hpp"


int main()
{
    int serverFD = setupServer();
    runServer(serverFD);
}
