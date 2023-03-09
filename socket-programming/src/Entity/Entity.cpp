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