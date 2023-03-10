#ifndef __ENTITY_SERVICE_HPP
#define __ENTITY_SERVICE_HPP

#include "../../../lib/json/json.hpp"
#include "../lib/HotelRoomUserInfo.hpp"
#include "../lib/DateTime.hpp"

class EntityService
{
private:
    
public:
    EntityService();

    HotelRoomUserInfo* getHotelRommUserInfoFormJson(nlohmann::json userInfo);

    std::vector<HotelRoomUserInfo*> getHotelRommAllUsersInfoFormJson(nlohmann::json usersInfo);
};

#endif