#ifndef __ENTITY_HPP
#define __ENTITY_HPP

class Entity
{
protected:
    int id;

    Entity* setId(int _id);
public:
    Entity(int _id);

    int getId();
};

#endif