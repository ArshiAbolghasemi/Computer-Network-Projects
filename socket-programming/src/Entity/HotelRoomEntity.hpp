#ifndef __HOTEL_ROOM_ENTITY_HPP
#define __HOTEL_ROOM_ENTITY_HPP

#include "Entity.hpp"
#include "UserEntity.hpp"
#include "../lib/HotelRoomUserInfo.hpp"

class HotelRoomEntity : public Entity
{
private:
    int status;
    
    int price;

    int maxCapacity;

    int capacity;

    vector<HotelRoomUserInfo*> usersInfo;
public:

    const int FULL_STATUS = 1;
    const int EMPTY_STATUS = 0;

    HotelRoomEntity(
        int _id,
        int _status,
        int _price,
        int _maxCapacity,
        int _capacity,
        vector<HotelRoomUserInfo*> _userInfos = {}
    );

    static string getJsonFilePath();

    static string getTableName();

    int getStatus();

    HotelRoomEntity* setStatus(int _status);

    int getPrice();

    HotelRoomEntity* setPrice(int _price);

    int getCapacity();

    HotelRoomEntity* setCapacity(int _capacity);

    int getMaxCapacity();

    HotelRoomEntity* setMaxCapacity(int _maxCapacity);

    vector<HotelRoomUserInfo*> getAllUser();

    HotelRoomUserInfo* getUserInfo(int _userId);

    HotelRoomEntity* addUser(HotelRoomUserInfo* userInfo);
};

#endif