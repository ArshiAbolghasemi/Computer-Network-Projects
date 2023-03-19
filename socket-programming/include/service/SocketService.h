#ifndef _SOCKET_SERVICE_H_
#define _SOCKET_SERVICE_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "LogService.h"

const int MAX_BUFFER_LENGTH  = 1024;

const int MAX_CLIENT_LISTEN_TO = 30;

int createSocket(int _domain, int _type, int _protocol);

void setSocketOption(int _fd, int _level, int _optName);

struct sockaddr_in createSocketAddressIn(int port, const char* host);

void bindSocket(int _fd, struct sockaddr_in srv);

void listenToClient(int _fd, int _n);

int acceptClient(int server_fd);

void selectSysCall(int _nfds, fd_set * _readfds);

void connectToSocket(int _fd, struct sockaddr_in srv_addr);

void readSocket(int _fd, char* buffer);

void sendMsg(int _fd, const char* buffer);

#ifdef __cplusplus
}
#endif

#endif