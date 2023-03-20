#ifndef __ENTITY_REPOSITORY_HPP
#define __ENTITY_REPOSITORY_HPP

#include "../lib/json.hpp"
#include "../service/SPJsonService.hpp"
#include "../Entity/UserEntity.hpp"
#include "../Entity/HotelRoomEntity.hpp"
#include <string>

template<class T>
class EntityRepository
{
protected:

public:

    template<typename U>
    static T* getByField(std::string key, U fieldValue)
    {
        SPJsonService* service = new SPJsonService();
        nlohmann::json jsonData = service->readfile(T::getJsonFilePath());
        nlohmann::json doc = service->getDocByKeyValue<U>(
            jsonData[T::getTableName()],
            key, 
            fieldValue);

        if(doc.is_null()){
            return nullptr;
        }

        return T::getInstance(doc); 
    }

    T* getById(int id);
};

#endif