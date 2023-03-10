#include "EntityRepository.hpp"

template<class T>
template<typename U>
T* EntityRepository<T>::getByField(std::string key, U fieldValue)
{
    nlohmann::json jsonData = (new SPJsonService())->readfile(T::getJsonFilePath());
    nlohmann::json doc = (new JsonService())->getDocByKeyValue<U>(
        jsonData[T::getTableName()],
        key, 
        fieldValue);
        
    if(doc.is_null()){
        return nullptr;
    }

    return T::getInstance(doc);
}

template<class T>
T* EntityRepository<T>::getById(int id)
{
    return this->getByField<int>("id", id);
}

template class EntityRepository<UserEntity>;
template class EntityRepository<HotelRoomEntity>;