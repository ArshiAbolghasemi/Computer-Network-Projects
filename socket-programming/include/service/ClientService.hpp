#ifndef __CLIENT_SERVICE_HPP_
#define __CLIENT_SERVICE_HPP_

#include "SocketService.h"

#define SERVER_ADDRESS "127.0.0.1"
#define SERVER_PORT 11000

int serverConnect(int port, char* host);

void runClient(int cli_fd);

void clientRecieveHandle();

void clientSendHandle();

#endif