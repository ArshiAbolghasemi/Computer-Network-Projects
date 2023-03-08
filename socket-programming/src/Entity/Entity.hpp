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

    virtual string getJsonFilePath() = 0;

    virtual string getTableName() = 0;

    template<typename T>
    static Entity* getByField(string key, T value);

    static Entity* getById(int id);

};


#endif