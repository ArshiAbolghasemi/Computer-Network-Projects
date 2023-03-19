extern "C"{
    #include "../service/SocketService.h"
}

#include <iostream>
#include <fstream>
#include "../lib/DateTime.hpp"
#include "../service/ErrorCheckerService.hpp"
#include "UserEntity.hpp"
#include "HotelRoomEntity.hpp"

const char* SERVER_ADDRESS = "127.0.0.1";
const int SERVER_PORT  = 11000;
const char* WELCOME = "Welcome...!\n1)To sign up\n2)To sign in\n";
const char* SERVER_ADDRESS = "127.0.0.1";
const char* COMMAND = "Command -> ";
const char* HELP = "Help -> ";
const char* SET_TIME = "setTime <Date Time>\n";
const char* SET_TIME_HELP = "Date time format: 25-02-2023\n";
const char* INDICATOR = ">> ";


class ServerEntity
{
    private:
        DateTime* serverDate;

        fd_set master;

        int newClientHandle(fd_set* fs, int serverFD);

        void manageClient(int fd);

    public:
        int setupServer(const char* add, int port);
        
        void setTime();

        void runServer(int serverFD);

        ServerEntity(){}

        
std::vector<UserEntity*>initClientsFromJson();

std::vector<HotelRoomEntity*> ServerEntity::initHotelRoomsFromJson();

};