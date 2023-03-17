#ifndef __SERVER_SERVICE_HPP_
#define __SERVER_SERVICE_HPP_

#include "SocketService.h"

#define SERVER_ADDRESS "127.0.0.1"
#define SERVER_PORT 11000
#define WELCOME "Welcome...!\n1)To sign up\n2)To sign in\n"

int setupServer();

void runServer(int serverFD);

int newClientHandle(fd_set* master, int serverFD);

void manageClient();

#endif