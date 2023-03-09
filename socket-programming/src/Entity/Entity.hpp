#ifndef __ENTITY_HPP
#define __ENTITY_HPP

#include <string>
#include "../service/SPJsonService.hpp"

using namespace std;

class Entity
{
protected:
    int id;

    Entity* setId(int _id);
public:
    Entity(int _id);

    int getId();

    template<typename T, typename U>
    static T* getByField(string key, U fieldValue);

    template<typename T>
    static T* getById(int id);
};

#endif