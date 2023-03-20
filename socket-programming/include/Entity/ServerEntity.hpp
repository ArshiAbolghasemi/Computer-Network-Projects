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
#define SERVER_PORT 11000
#define WELCOME "Welcome...!\n1)To sign up\n2)To sign in\n"
#define COMMAND "Command -> "
#define HELP "Help -> "
#define SET_TIME "setTime <Date Time>\n"
#define SET_TIME_HELP "Date time format: 25-02-2023\n"
#define INDICATOR ">> "


class ServerEntity
{
    private:
        DateTime* serverDate;

        fd_set master;

        int newClientHandle(fd_set* fs, int serverFD);

        void manageClient(int fd);

        std::vector<UserEntity*> uVec;
        
        std::vector<HotelRoomEntity*> hVec;

    public:
        int setupServer(const char* add, int port);
        
        void setTime();

        void runServer(int serverFD);

        ServerEntity(){}

        std::vector<UserEntity*>initClientsFromJson();

        std::vector<HotelRoomEntity*> initHotelRoomsFromJson();

};

#endif