#ifndef _SERVER_ENTITY_HPP_
#define _SERVER_ENTITY_HPP_


#include "../service/SocketService.h"

#include <iostream>
#include <fstream>

#include "../lib/DateTime.hpp"
#include "../service/ErrorCheckerService.hpp"
#include "UserEntity.hpp"
#include "HotelRoomEntity.hpp"
#include "../service/StringService.hpp"

#define SERVER_ADDRESS "127.0.0.1"
#define SERVER_PORT 12120
#define WELCOME "Welcome...! Press:\n1)To sign up\n2)To sign in\n"
#define COMMAND "Command -> "
#define HELP "Help -> "
#define SET_TIME "setTime <Date Time>\n"
#define SET_TIME_HELP "Date time format: 25-02-2023\n"
#define INDICATOR ">> "

#define NO_PAT "$$$$"
#define FIRST_MENU_PAT "$FMENU$"
#define SIGNUP_PAT "$SUPAT$"
#define SIGNIN_PAT "$SIPAT$"
#define ERR_PAT "$ERROR$"

class ServerEntity
{
    private:
        DateTime* _serverDate;

        fd_set _master;

        int newClientHandle(int serverFD);

        void manageClient(int fd);

        std::vector<UserEntity*> uVec;
        
        std::vector<HotelRoomEntity*> hVec;

        std::string deTokenize(const char* token, 
            const char* buf);

        void FMenuHandle(const char* buf, int fd);

    public:
        int setupServer(const char* add, int port);
        
        void setTime();

        void runServer(int serverFD);

        ServerEntity(){}

        std::vector<UserEntity*>initClientsFromJson();

        std::vector<HotelRoomEntity*> initHotelRoomsFromJson();

};

#endif