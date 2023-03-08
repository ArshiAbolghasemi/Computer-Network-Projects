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

template<typename T>
Entity* Entity::getByField(string key, T value)
{
    JsonService* service = JsonService::getInstance();
    jsonData = service->readFile(this->getJsonFilePath);
    
    return service->getDocByKeyValue<T>(
        jsonData[this->getTableName()],
        key,
        value
    );
}

Entity* Entity::getById(int id)
{
    return Entity::getByField<int>("id", id);
}