#include "../../include/service/ErrorCheckerService.hpp"

bool ErrorChecker::setTimeCheck(std::string inp)
{
    std::vector<std::string> parsedInp = 
        parseStringByDelim(inp, ' ');
    if(parsedInp.size() != 2)
    {
        return false;
    }
    if(parsedInp[0] != ST_SET_TIME)
    {
        return false;
    }
    std::vector<std::string> parsedDate = 
        parseStringByDelim(parsedInp[1], '-');
    if(parsedDate.size() != 3)
    {
        return false;
    }
    for(auto i: parsedDate)
    {
        if(isStringAllFlag(i, NUM) == false)
        {
            return false;
        }
    }
    return true;
}