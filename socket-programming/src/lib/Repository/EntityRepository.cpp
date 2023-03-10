#include "EntityRepository.hpp"

template<typename U>
UserEntity* EntityRepository::getByFieldU(string key, U fieldValue)
{
    nlohmann::json jsonData = (new SPJsonService())->readfile(UserEntity::getJsonFilePath());
    nlohmann::json doc = (new JsonService())->getDocByKeyValue<U>(
        jsonData[UserEntity::getTableName()],
        key, 
        fieldValue);
        
    if(doc.is_null()){
        return nullptr;
    }

    return UserEntity::getInstance(doc);
}

UserEntity* EntityRepository::getByIdU(int id)
{
    return EntityRepository::getByFieldU<int>("id", id);
}

template<typename U>
HotelRoomEntity* EntityRepository::getByFieldH(string key, U fieldValue)
{
    nlohmann::json jsonData = (new SPJsonService())->readfile(HotelRoomEntity::getJsonFilePath());
    nlohmann::json doc = (new JsonService())->getDocByKeyValue<U>(
        jsonData[HotelRoomEntity::getTableName()],
        key, 
        fieldValue);
        
    if(doc.is_null()){
        return nullptr;
    }

    return HotelRoomEntity::getInstance(doc);
}

HotelRoomEntity* EntityRepository::getByIdH(int id)
{
    return EntityRepository::getByFieldH<int>("id", id);
}