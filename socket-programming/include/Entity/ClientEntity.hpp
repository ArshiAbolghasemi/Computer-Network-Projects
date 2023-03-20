#ifndef _CLIENT_ENTITY_HPP_
#define _CLIENT_ENTITY_HPP_

extern "C"{
    #include "../service/SocketService.h"
}

#define SERVER_ADDRESS "127.0.0.1"
#define SERVER_PORT 11000

class ClientEntity
{
    private:
        fd_set master;

    public:
        int serverConnect(int port, const char* host);

        void runClient(int cli_fd);
};

#endif