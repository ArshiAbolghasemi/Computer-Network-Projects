#include "../../include/service/SocketService.h"

int createSocket(int _domain, int _type, int _protocol)
{
    int fd = socket(_domain, _type, _protocol);

    if(fd < 0){
        logErrorToConsole("failed to create socket");
        logErrorToFile("failed to create socket");
        exit(EXIT_FAILURE);
    }

    logInfoToConsole("create socket successfully, fd: %d", fd);

    return fd;
}

void setSocketOption(int _fd, int _level,int _optName)
{
    int opt = 1;
    
    if(setsockopt(_fd, _level, _optName, &opt, sizeof(opt))){
        logErrorToConsole("failed to set option for socket, fd: %d", _fd);
        logErrorToFile("failed to set option for socket, fd: %d", _fd);
        exit(EXIT_FAILURE);
    }

    logInfoToFile("set option for socket successfully, fd: %d", _fd);

    return;
}

struct sockaddr_in createSocketAddressIn(int port, const char* host)
{
    struct sockaddr_in srv;
    
    srv.sin_family = AF_INET;
    srv.sin_addr.s_addr = inet_addr(host);
    srv.sin_port = htons(port);

    return srv;
}

void bindSocket(int _fd, struct sockaddr_in srv)
{
    if(bind(_fd, (struct sockaddr *) &srv, sizeof(srv)) < 0){
        logErrorToConsole("failed to bind socket, fd: %d", _fd);
        logErrorToFile("failed to bind socket, fd: %d", _fd);
        exit(EXIT_FAILURE);
    }

    logInfoToConsole("bind socket successfully, fd: %d", _fd);

    return;
}

void listenToClient(int _fd, int _n)
{
    if(_n > MAX_CLIENT_LISTEN_TO){
        logErrorToConsole("reached max client cnt, we're fucked up!");
        logErrorToFile("reached max client cnt, we're fucked up!");
        exit(EXIT_FAILURE);
    }

    if(listen(_fd, _n) < 0){
        logErrorToConsole("server failed to listen, fd: %d, cnt_of_client: %d", _fd, _n);
        logErrorToFile("server failed to listen, fd: %d, cnt_of_client: %d", _fd, _n);
        exit(EXIT_FAILURE);
    }

    logInfoToConsole("server is listening, fd: %d, client_cnt: %d", _fd, _n);

    return;
}

int acceptClient(int server_fd)
{
    struct sockaddr_in cli;
    int cli_len = sizeof(cli);
    int client_fd = accept(server_fd, (struct sockaddr *) &cli, (socklen_t*) &cli_len);

    if(client_fd < 0){
        logErrorToConsole("failed to accept client");
        logErrorToFile("failed to accept client");
        exit(EXIT_FAILURE);
    }

    logInfoToConsole("accept client successfully, client_fd: %d", client_fd);

    return client_fd;
}

void selectSysCall(int _nfds, fd_set * _readfds)
{    
    if(select(_nfds, _readfds, NULL, NULL, NULL) < 0){
        logErrorToConsole("failed to call select syscall");
        logErrorToFile("failed to call select syscall");
        exit(EXIT_FAILURE);
    }

    logInfoToFile("call select syscall");

    return;
}

void connectToSocket(int _fd, struct sockaddr_in srv_addr)
{
    if(connect(_fd, (struct  sockaddr *) &srv_addr, sizeof(srv_addr)) < 0){
        logErrorToConsole("failed to connect to socket, socket_fd: %d", _fd);
        logErrorToFile("failed to connect to socket, socket_fd: %d", _fd);
        exit(EXIT_FAILURE);
    }

    logInfoToFile("connect successfully, socket_fd: %d", _fd);

    return;
}

void readSocket(int _fd, char* buffer)
{
    if(read(_fd, buffer, MAX_BUFFER_LENGTH) < 0){
        logErrorToConsole("failed to read socket, socket_fd: %d", _fd);
        logErrorToFile("failed to read socket, socket_fd: %d", _fd);
    }

    logInfoToConsole("read socket successfully, socket_fd: %d", _fd);

    return;
}

void sendMsg(int _fd, const char* buffer)
{
    if(send(_fd, buffer, strlen(buffer), 0) < 0){
        logErrorToConsole("failed to send message to socket, socket_fd: %d", _fd);
        logErrorToFile("failed to send message to socket, socket_fd: %d", _fd);
    }

    logInfoToFile("send message successfully to socket, socket_fd: %d", _fd);

    return;
}