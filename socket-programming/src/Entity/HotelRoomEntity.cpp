#include "../../include/Entity/HotelRoomEntity.hpp"

HotelRoomEntity::HotelRoomEntity(
    int _id,
    int _status,
    double _price,
    int _maxCapacity,
    int _capacity,
    vector<HotelRoomUserInfo*> _userInfos
) : Entity(_id),
    status(_status),
    price(_price),
    maxCapacity(_maxCapacity),
    capacity(_capacity) {}

std::string HotelRoomEntity::getJsonFilePath()
{
    return "RoomsInfo.json";
}

std::string HotelRoomEntity::getTableName()
{
    return "rooms";
}

HotelRoomEntity* HotelRoomEntity::getInstance(nlohmann::json jsonData)
{
    return (new HotelRoomEntity(
        jsonData.at("id"),
        jsonData.at("stauts"),
        jsonData.at("price"),
        jsonData.at("maxCapacity"),
        jsonData.at("capacity"),
        (new EntityService())->getHotelRommAllUsersInfoFormJson(jsonData["users"])
    ));
}

int HotelRoomEntity::getStatus()
{
    return this->status;
}

HotelRoomEntity* HotelRoomEntity::setStatus(int _status)
{
    this->status = _status;
    return this;
}

int HotelRoomEntity::getPrice()
{
    return this->price;
}

HotelRoomEntity* HotelRoomEntity::setPrice(double _price)
{
    this->price = _price;
    return this;
}

int HotelRoomEntity::getCapacity()
{
    return this->capacity;
}

HotelRoomEntity* HotelRoomEntity::setCapacity(int _capacity)
{
    this->capacity = _capacity;
    return this;
}

int HotelRoomEntity::getMaxCapacity()
{
    return this->maxCapacity;
}

HotelRoomEntity* HotelRoomEntity::setMaxCapacity(int _maxCapacity)
{
    this->maxCapacity = _maxCapacity;
    return this;
}

std::vector<HotelRoomUserInfo*> HotelRoomEntity::getAllUser()
{
    return this->usersInfo;
}

HotelRoomUserInfo* HotelRoomEntity::getUserInfo(int _userId)
{
    for(auto it = this->usersInfo.begin(); it != this->usersInfo.end(); ++it){
        if((*it)->userId == _userId){
            return *it;
        }
    }

    return nullptr;
}

HotelRoomEntity* HotelRoomEntity::addUser(HotelRoomUserInfo* userInfo)
{
    this->usersInfo.push_back(userInfo);
    return this;
}