#ifndef __HOTEL_ROOM_USERS_INFO_HPP
#define __HOTEL_ROOM_USERS_INFO_HPP

#include "DateTime.hpp"

struct HotelRoomUserInfo {
    int userId;
    int numOfBeds;
    DateTime reserveDate;
    DateTime checkoutDate;
};

typedef struct HotelRoomUserInfo HotelRoomUserInfo;

#endif