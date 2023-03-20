#include <vector>
#include <string>

#define ST_SET_TIME "setTime"


#include "StringService.hpp"
#include "../Entity/UserEntity.hpp"
#include "../lib/EntityRepository.hpp"

class ErrorChecker
{
    public:
        static bool setTimeCheck(std::string inp);

        static UserEntity* signInCheck(std::string inp);    
};