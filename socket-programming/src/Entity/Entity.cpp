#include "Entity.hpp"

Entity::Entity(int _id) : id(_id) {}

int Entity::getId()
{
    return this->id;
}

Entity* Entity::setId(int _id)
{
    this->id = _id;
    return this;
}

template<typename T, typename U>
T* Entity::getByField(string key, U fieldValue)
{
    SPJsonService* service = SPJsonService::getInstance();
    json jsonData = service->readfile(T::getJsonFilePath());
    json doc = JsonService::getInstance()->getDocByKeyValue<U>(
        jsonData[T::getTableName()],
        key, 
        fieldValue);
        
    if(doc.is_null()){
        return nullptr;
    }

    return T::getInstance(doc);
}

template<typename T>
T* Entity::getById(int id)
{
    return getByField<T, int>("id", id);
}