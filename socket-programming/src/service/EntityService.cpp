#include "EntityService.hpp"

EntityService::EntityService() {}

HotelRoomUserInfo* EntityService::getHotelRommUserInfoFormJson(nlohmann::json userInfo)
{
    HotelRoomUserInfo *hotelRoomUserInfo = new HotelRoomUserInfo;

    hotelRoomUserInfo->userId = userInfo["user_id"];
    hotelRoomUserInfo->numOfBeds = userInfo["numOfBeds"];
    hotelRoomUserInfo->reserveDate = DateTime::toDate(userInfo["reserveDate"]);
    hotelRoomUserInfo->checkoutDate = DateTime::toDate(userInfo["checkoutDate"]);

    return hotelRoomUserInfo;
}

std::vector<HotelRoomUserInfo*> EntityService::getHotelRommAllUsersInfoFormJson(nlohmann::json usersInfo)
{
    std::vector<HotelRoomUserInfo*> allUsersInfo = {};

    for(auto userInfo : usersInfo){
        allUsersInfo.push_back(this->getHotelRommUserInfoFormJson(userInfo));
    }

    return allUsersInfo;
}