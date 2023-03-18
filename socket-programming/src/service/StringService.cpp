#include "../../include/service/StringService.hpp"


std::vector<std::string> parseStringByDelim(
    std::string inp, char delim)
{
    std::stringstream ss;
    ss << inp;
    std::string temp;
    std::vector<std::string> res;
    while(std::getline(ss, temp, delim))
    {
        res.push_back(temp);
    }
    return res;
}

bool isStringAllFlag(std::string inp,
    enum StrFormat flag)
{
    if(flag == NUM)
    {
        for(char i: inp)
        {
            if(isdigit(i) == 0)
            {
                return false;
            }
        }
    }
    else if(flag == CHAR)
    {
        for(char i: inp)
        {
            if(isalpha(i) == 0)
            {
                return false;
            }
        }
    }
}