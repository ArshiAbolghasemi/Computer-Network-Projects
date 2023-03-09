#include "SPJsonService.hpp"

SPJsonService::SPJsonService() {}

SPJsonService* SPJsonService::getInstance()
{
    if(SPJsonService::service == nullptr){
        SPJsonService::service = new SPJsonService();
    }

    return SPJsonService::service;
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
    HotelRoomUserInfo *hotelRoomUserInfo = new HotelRoomUserInfo;

    hotelRoomUserInfo->userId = userInfo["user_id"];
    hotelRoomUserInfo->numOfBeds = userInfo["numOfBeds"];
    hotelRoomUserInfo->reserveDate = DateTime::toDate(userInfo["reserveDate"]);
    hotelRoomUserInfo->checkoutDate = DateTime::toDate(userInfo["checkoutDate"]);

    return hotelRoomUserInfo;
}

vector<HotelRoomUserInfo*> SPJsonService::getHotelRommAllUsersInfoFormJson(json usersInfo)
{
    vector<HotelRoomUserInfo*> allUsersInfo = {};

    for(auto userInfo : usersInfo){
        allUsersInfo.push_back(this->getHotelRommUserInfoFormJson(userInfo));
    }

    return allUsersInfo;
}