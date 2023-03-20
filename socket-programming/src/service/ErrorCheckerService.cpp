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