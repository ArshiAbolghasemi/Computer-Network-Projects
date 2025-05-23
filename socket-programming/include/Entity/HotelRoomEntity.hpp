#ifndef __HOTEL_ROOM_ENTITY_HPP
#define __HOTEL_ROOM_ENTITY_HPP

#include "Entity.hpp"
#include "../lib/json.hpp"
#include <vector>
#include <string>
#include "../lib/DateTime.hpp"
#include "../service/EntityService.hpp"

class HotelRoomEntity : public Entity
{
private:
    int status;
    
    double price;

    int maxCapacity;

    int capacity;

    std::vector<HotelRoomUserInfo*> usersInfo;
public:

    const int FULL_STATUS = 1;
    const int EMPTY_STATUS = 0;

    HotelRoomEntity(
        int _id,
        int _status,
        double _price,
        int _maxCapacity,
        int _capacity,
        std::vector<HotelRoomUserInfo*> _userInfos
    );

    static std::string getJsonFilePath();

    static std::string getTableName();

    static HotelRoomEntity* getInstance(nlohmann::json jsonData);

    int getStatus();

    HotelRoomEntity* setStatus(int _status);

    int getPrice();

    HotelRoomEntity* setPrice(double _price);

    int getCapacity();

    HotelRoomEntity* setCapacity(int _capacity);

    int getMaxCapacity();

    HotelRoomEntity* setMaxCapacity(int _maxCapacity);

    std::vector<HotelRoomUserInfo*> getAllUser();

    HotelRoomUserInfo* getUserInfo(int _userId);

    HotelRoomEntity* addUser(HotelRoomUserInfo* userInfo);
};

#endif