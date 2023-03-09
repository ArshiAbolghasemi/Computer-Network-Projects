#include "SPJsonService.hpp"

SPJsonService* SPJsonService::getInstance()
{
    if(service == nullptr){
        service = new SPJsonService();
    }

    return service;
}

JsonService* SPJsonService::getJsonServiceInstance()
{
    return JsonService::getInstance();
}

json SPJsonService::readfile(string filePath)
{
    return JsonService::getInstance()->readFile(CONFIGS_PATH_PREFIX + filePath);
}

void SPJsonService::writeToFile(json document, string filePath)
{
    JsonService::getInstance()->writeToFile(document, CONFIGS_PATH_PREFIX + filePath);
}

HotelRoomUserInfo* SPJsonService::getHotelRommUserInfoFormJson(json userInfo)
{
    HotelRoomUserInfo hotelRoomUserInfo {
        userInfo["user_id"],
        userInfo["numOfBeds"],
        DateTime::toDate(userInfo["reserveDate"]),
        DateTime::toDate(userInfo["checkoutDate"])
    };

    return &hotelRoomUserInfo;
}

vector<HotelRoomUserInfo*> SPJsonService::getHotelRommAllUsersInfoFormJson(json usersInfo)
{
    vector<HotelRoomUserInfo*> allUsersInfo = {};

    for(auto userInfo : usersInfo){
        allUsersInfo.push_back(this->getHotelRommUserInfoFormJson(userInfo));
    }

    return allUsersInfo;
}