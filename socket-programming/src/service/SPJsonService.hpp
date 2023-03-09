#ifndef __SP_JSON_SERVICE
#define __SP_JSON_SERVICE

#include "../../../service/JsonService.hpp"
#include "../lib/HotelRoomUserInfo.hpp"

class SPJsonService
{
private:
    static SPJsonService* service;

    SPJsonService();
public:

    const string CONFIGS_PATH_PREFIX = "../socket-programming/config/";

    static SPJsonService* getInstance();

    static JsonService* getJsonServiceInstance();

    SPJsonService(SPJsonService &service) = delete;

    void operator=(const SPJsonService &) = delete;

    json readfile(string filePath);

    void writeToFile(json document, string filePath);

    HotelRoomUserInfo* getHotelRommUserInfoFormJson(json userInfo);

    vector<HotelRoomUserInfo*> getHotelRommAllUsersInfoFormJson(json* usersInfo);
};

SPJsonService* SPJsonService::service = nullptr;

#endif