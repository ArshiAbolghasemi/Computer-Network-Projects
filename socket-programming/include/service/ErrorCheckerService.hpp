#include "StringService.hpp"

const std::string ST_SET_TIME = "setTime";

#include <vector>
#include <string>

class ErrorChecker
{
    public:
        static bool setTimeCheck(std::string inp);    
};