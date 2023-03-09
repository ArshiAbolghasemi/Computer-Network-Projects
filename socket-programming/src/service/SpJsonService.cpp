#include "SPJsonService.hpp"

SPJsonService* SPJsonService::getInstance()
{
    if(service == nullptr){
        service = new SPJsonService();
    }

    return service;
}

static JsonService* getJsonServiceInstance()
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
        nullptr,
        nullptr
    };

    return &hotelRoomUserInfo;
}

vector<HotelRoomUserInfo*> SPJsonService::getHotelRommAllUsersInfoFormJson(json *usersInfo)
{
    vector<HotelRoomUserInfo*> allUsersInfo = {};

    for(auto it = usersInfo->begin(); it != usersInfo->end(); ++it){
        allUsersInfo.push_back(this->getHotelRommUserInfoFormJson(*it));
    }

    return allUsersInfo;
}