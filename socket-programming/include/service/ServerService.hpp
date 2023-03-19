#ifndef __SERVER_SERVICE_HPP_
#define __SERVER_SERVICE_HPP_

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "SocketService.h"
#include "../Entity/UserEntity.hpp"
#include "../Entity/HotelRoomEntity.hpp"
#include "ErrorCheckerService.hpp"

// port should be read from json
#define SERVER_PORT 11000 // defined port for testing purposes
const char* WELCOME = "Welcome...!\n1)To sign up\n2)To sign in\n";
const char* SERVER_ADDRESS = "127.0.0.1";
const char* COMMAND = "Command -> ";
const char* HELP = "Help -> ";
const char* SET_TIME = "setTime <Date Time>\n";
const char* SET_TIME_HELP = "Date time format: 25-02-2023\n";
const char* INDICATOR = ">> ";

int setupServer();

void runServer(int serverFD);

int newClientHandle(fd_set* master, int serverFD);

void manageClient(int fd);

void setTime();

std::vector<UserEntity*> initClientsFromJson();

std::vector<HotelRoomEntity*> initHotelRoomsFromJson();

#endif