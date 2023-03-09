#ifndef __ENTITY_HPP
#define __ENTITY_HPP

#include <string>
#include "../../../service/JsonService.hpp"

using namespace std;

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