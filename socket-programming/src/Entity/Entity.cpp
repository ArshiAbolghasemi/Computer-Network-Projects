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
    jsonData = service->readfile(T::getJsonFilePath());
    json doc = SPJsonService::getJsonServiceInstance()
                        ->getDocByKeyValue<U>(json[T::getTableName()], key, fieldValue);
    if(doc == nullptr){
        return nullptr;
    }

    return T::getInstance(doc);
}

template<typename T>
T* Entity::getById(int id)
{
    return getByField<T, int>("id", id);
}