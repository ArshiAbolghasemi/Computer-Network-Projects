#include "../../include/service/ServerService.hpp"

int setupServer()
{
    int serverFD = createSocket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in srv = createSocketAddressIn(
        SERVER_PORT, SERVER_ADDRESS);
    setSocketOption(serverFD, SOL_SOCKET, SO_REUSEADDR);
    setSocketOption(serverFD, SOL_SOCKET, SO_REUSEPORT);
    bindSocket(serverFD, srv);
    listenToClient(serverFD, MAX_CLIENT_LISTEN_TO);
    return serverFD;
}

void setTime()
{
    std::cout << COMMAND << SET_TIME;
    std::cout << HELP << SET_TIME_HELP;
    std::cout << INDICATOR;
    std::string line;
    std::getline(std::cin, line, '\0');
    if(ErrorChecker::setTimeCheck(line) == false)
    {
        // ErrorHandler::
    }
}

void runServer(int serverFD)
{
    setTime();
    std::vector<UserEntity*> uVec = initClientsFromJson();
    std::vector<HotelRoomEntity*> hVec =
         initHotelRoomsFromJson();
    fd_set master, temp;
    FD_ZERO(&master);
    int max_ind = serverFD;
    while(1)
    {
        temp = master;
        selectSysCall(max_ind+1, &temp);
        for(int i = 0; i <= max_ind; i++)
        {
            if(FD_ISSET(i, &temp))
            {
                if(i == serverFD)
                {
                    int cli_fd = newClientHandle(
                        &master, serverFD);
                    if(cli_fd > max_ind)
                    {
                        max_ind = cli_fd;
                    }
                }
                else
                {
                    manageClient(i);
                }
            }
        }
    }
}

int newClientHandle(fd_set* master, int serverFD)
{
    int client_fd = acceptClient(serverFD);
    FD_SET(client_fd, master);
    sendMsg(client_fd, WELCOME);
    return client_fd;
}

void manageClient(int d)
{
    // client managing logic
}

std::vector<UserEntity*> initClientsFromJson()
{
    std::string conf = "../../config";
    std::ifstream file(conf + 
        UserEntity::getJsonFilePath());
    std::vector<UserEntity*> res;
    if(file.good())
    {
        nlohmann::json j;
        file >> j;
        for(auto us: j["users"])
        {
            res.push_back(UserEntity::getInstance(us));
        }
        return res;
    }
    perror("file not open");
}

std::vector<HotelRoomEntity*> initHotelRoomsFromJson()
{
    std::string conf = "../../config";
    std::ifstream file(conf + 
        UserEntity::getJsonFilePath());
    std::vector<HotelRoomEntity*> res;
    if(file.good())
    {
        nlohmann::json j;
        file >> j;
        for(auto us: j["users"])
        {
            res.push_back(HotelRoomEntity::getInstance(us));
        }
        return res;
    }
    perror("file not open");
}
