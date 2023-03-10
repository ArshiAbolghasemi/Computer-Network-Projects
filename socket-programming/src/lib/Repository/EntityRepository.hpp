#ifndef __ENTITY_REPOSITORY_HPP
#define __ENTITY_REPOSITORY_HPP

#include "../../../../lib/json/json.hpp"
#include "../../service/SPJsonService.hpp"
#include "../../Entity/UserEntity.hpp"
#include "../../Entity/HotelRoomEntity.hpp"
#include "../../../../service/JsonService.hpp"
#include <string>

template<class T>
class EntityRepository
{
protected:

public:

    template<typename U>
    T* getByField(std::string key, U fieldValue);

    T* getById(int id);
};

#endif