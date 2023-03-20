#ifndef _CLIENT_ENTITY_HPP_
#define _CLIENT_ENTITY_HPP_

#include <string>
#include <cstring>
#include <iostream>

extern "C"{
    #include "../service/SocketService.h"
}
#include "../service/StringService.hpp"

#define SERVER_ADDRESS "127.0.0.1"
#define SERVER_PORT 12120

#define NO_PAT "$$$$"
#define FIRST_MENU_PAT "$FMENU$"
#define SIGNUP_PAT "$SUPAT$"
#define SIGNIN_PAT "$SIPAT$"
#define ERR_PAT "$ERROR$"

#define WELCOME "Welcome...! Press:\n1)To sign up\n2)To sign in\n>> "
#define SIGNIN_OPTION 

class ClientEntity
{
    private:
        fd_set _master;
        
        void receiveHandle(int fd);

        void sendHandle(int srv_fd);

        std::string _status = (std::string)FIRST_MENU_PAT;

        void FMenuProtocol();

        void SignInProtocol();

    public:
        int serverConnect(int port, const char* host);

        void runClient(int cli_fd);
};

#endif