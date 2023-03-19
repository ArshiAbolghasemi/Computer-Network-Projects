#ifndef __CLIENT_SERVICE_HPP_
#define __CLIENT_SERVICE_HPP_


#include "SocketService.h"
// port should be read from json
const int SERVER_PORT = 11000; // defined port for testing purposes
const char* SERVER_ADDRESS = "127.0.0.1";

int serverConnect(int port, const char* host);

void runClient(int cli_fd);

// void clientRecieveHandle();

// void clientSendHandle();

#endif