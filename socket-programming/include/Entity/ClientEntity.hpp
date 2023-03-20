#ifndef _CLIENT_ENTITY_HPP_
#define _CLIENT_ENTITY_HPP_

#include <string>
#include <cstring>
#include <iostream>
#include <unordered_map>

extern "C"{
    #include "../service/SocketService.h"
}
#include "../service/StringService.hpp"

// server constants
#define SERVER_ADDRESS "127.0.0.1"
#define SERVER_PORT 12120

// pattern constants
#define NO_PAT "$$$$"
#define FIRST_MENU_PAT "$FMENU$"
#define SIGNUP_PAT "$SUPAT$"
#define SIGNIN_PAT "$SIPAT$"
#define ERR_PAT "$ERROR$"
#define SUC_PAT "$SUCCESS$"
#define MAIN_MENU "$MAIN$"

// error constants
#define BAD_COMMAND 503
#define BAD_VALUE_FORMAT 401
#define INVALID_CRED 430

// success constants
#define GOOD_SIGNIN 230


// error message constants
#define BAD_COM_MSG "Your Command is not valid\n"
#define BAD_VAL_MSG "Format of the inputed value after command is not correct\n"
#define INV_CRED_MSG "Invalid username or password\n"

// success message constants
#define GOOD_SIN_MSG "You Have been signed in successfuly\n"

// text constants
#define INDICATOR ">> "
#define COMMAND "Command -> "
#define HELP "Help -> "
#define WELCOME "Welcome...! Press:\n1)To sign up\n2)To sign in\n"
#define SIGNIN_OPTION "signin <username> <password>\n"
#define SIGNIN_HELP "username: User name, password: user password\n"
#define ERR_MSG "Err -> "
#define MAIN "1. View user information\n2. View all users\n3. View rooms information\n4. Booking\n5. Canceling\n6. pass day\n7. Edit information\n8. Leving room\n9. Rooms\n0. Logout\n"

class ClientEntity
{
    private:
        fd_set _master;
        
        void receiveHandle(int fd);

        void sendHandle(int srv_fd);

        std::string _status = (std::string)FIRST_MENU_PAT;

        void FMenuProtocol();

        void SignInProtocol();

        void ErrorProtocol(const char* buf);

        void MainMenuProtocol();

        void printByLookup(int lookup);

        std::unordered_map<int, std::string> errLookup = {
            {BAD_COMMAND, BAD_COM_MSG},
            {BAD_VALUE_FORMAT, BAD_VAL_MSG},
            {GOOD_SIGNIN, GOOD_SIN_MSG},
            {INVALID_CRED, INV_CRED_MSG}
        };

    public:
        int serverConnect(int port, const char* host);

        void runClient(int cli_fd);
};

#endif