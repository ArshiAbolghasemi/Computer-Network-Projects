#include "../../include/lib/EntityRepository.hpp"

template<class T>
template<typename U>
T* EntityRepository<T>::getByField(std::string key, U fieldValue)
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

template<class T>
T* EntityRepository<T>::getById(int id)
{
    return this->getByField<int>("id", id);
}

template class EntityRepository<UserEntity>;
template class EntityRepository<HotelRoomEntity>;