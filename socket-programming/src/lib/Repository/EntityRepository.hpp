#ifndef __ENTITY_REPOSITORY_HPP
#define __ENTITY_REPOSITORY_HPP

#include "../../../../lib/json/json.hpp"
#include "../../service/SPJsonService.hpp"
#include "../../Entity/UserEntity.hpp"
#include "../../Entity/HotelRoomEntity.hpp"
#include <string>

class EntityRepository
{
protected:

public:

    template<typename U>
    static UserEntity* getByFieldU(string key, U fieldValue);

    static UserEntity* getByIdU(int id);

    template<typename U>
    static HotelRoomEntity* getByFieldH(string key, U fieldValue);

    static HotelRoomEntity* getByIdH(int id);
};


#endif