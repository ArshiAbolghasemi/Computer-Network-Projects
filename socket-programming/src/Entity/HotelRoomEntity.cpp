#include "HotelRoomEntity.hpp"

HotelRoomEntity::HotelRoomEntity(
    int _id,
    int _status,
    int _price,
    int _maxCapacity,
    int _capacity,
    vector<HotelRoomUserInfo*> _userInfos = {}
) : Entity(_id),
    status(_status),
    price(_price),
    maxCapacity(_maxCapacity),
    capacity(_capacity) {}

string HotelRoomEntity::getJsonFilePath()
{
    return "../../config/RoomsInfo.json";
}

string HotelRoomEntity::getTableName()
{
    return "rooms";
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

HotelRoomEntity* HotelRoomEntity::setPrice(int _price)
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

vector<HotelRoomUserInfo*> HotelRoomEntity::getAllUser()
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

UserEntity* HotelRoomEntity::getUser(int _userId)
{
    HotelRoomUserInfo* userInfo = this->getUserInfo(_userId);
    return UserEntity::getById(userInfo->userId);
}

HotelRoomEntity* HotelRoomEntity::addUser(HotelRoomUserInfo* userInfo)
{
    this->usersInfo.push_back(userInfo);
    return this;
}