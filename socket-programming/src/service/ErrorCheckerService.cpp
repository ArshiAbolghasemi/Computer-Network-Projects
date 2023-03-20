#include "../../include/service/ErrorCheckerService.hpp"

bool ErrorChecker::setTimeCheck(std::string inp)
{
    std::vector<std::string> parsedInp = 
        StringService::parseStringByDelim(inp, ' ');
    if(parsedInp.size() != 2)
    {
        return false;
    }
    if(parsedInp[0] != ST_SET_TIME)
    {
        return false;
    }
    std::vector<std::string> parsedDate = 
        StringService::parseStringByDelim(parsedInp[1], '-');
    if(parsedDate.size() != 3)
    {
        return false;
    }
    for(auto i: parsedDate)
    {
        if(StringService::isStringAllFlag(i, NUM) == false)
        {
            return false;
        }
    }
    return true;
}

UserEntity* ErrorChecker::signInCheck(std::string inp)
{
    std::vector<std::string> test = 
        StringService::parseStringByDelim(inp, ' ');
    if(test.size() != 3)
    {
        return nullptr;
    }
    if(test[0] != "signin")
    {
        return nullptr;
    }
    UserEntity* userInCheck = 
        EntityRepository<UserEntity>::getByField<std::string>(
        "name", test[1]);
    if(userInCheck == nullptr)
    {
        return nullptr;
    }
    if(userInCheck->getPassword() != test[2])
    {
        return nullptr;
    }
    return userInCheck;
}