#include "EntityRepository.hpp"

template<class T>
template<typename U>
T* EntityRepository<T>::getByField(string key, U fieldValue)
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

template<class T>
T* EntityRepository<T>::getById(int id)
{
    return this->getByField<int>("id", id);
}