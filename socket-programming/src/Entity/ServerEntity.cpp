#include "../../include/Entity/ServerEntity.hpp"



int ServerEntity::setupServer(const char* add, int port)
{
    int serverFD = createSocket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in srv = createSocketAddressIn(
        port, add);
    setSocketOption(serverFD, SOL_SOCKET, SO_REUSEADDR);
    setSocketOption(serverFD, SOL_SOCKET, SO_REUSEPORT);
    bindSocket(serverFD, srv);
    listenToClient(serverFD, MAX_CLIENT_LISTEN_TO);
    return serverFD;
}

void ServerEntity::setTime()
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
    this->serverDate = DateTime::toDate(
        StringService::parseStringByDelim(line, '-')[1]);
}

void ServerEntity::runServer(int serverFD)
{
    this->setTime();
    fd_set temp;
    FD_ZERO(&(this->master));
    int max_ind = serverFD;
    while(1)
    {
        temp = this->master;
        selectSysCall(max_ind+1, &temp);
        for(int i = 0; i <= max_ind; i++)
        {
            if(FD_ISSET(i, &temp))
            {
                if(i == serverFD)
                {
                    int cli_fd = newClientHandle(
                        &(this->master), serverFD);
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

int ServerEntity::newClientHandle(fd_set* fs, int serverFD)
{
    int client_fd = acceptClient(serverFD);
    FD_SET(client_fd, fs);
    sendMsg(client_fd, WELCOME);
    return client_fd;
}

std::vector<UserEntity*> ServerEntity::initClientsFromJson()
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
    return res;
}

std::vector<HotelRoomEntity*> ServerEntity::initHotelRoomsFromJson()
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
    return res;
}

void ServerEntity::manageClient(int fd)
{

}