#include "../../include/service/StringService.hpp"

std::vector<std::string>StringService::parseStringByDelim(
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

bool StringService::isStringAllFlag(std::string inp,
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
        return true;
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
        return true;
    }
    perror("Undefined use of the function isStringAllFlag");
    return false;
}

std::string StringService::addStatus(const char* inp,
    std::string status)
{
    std::string temp = inp;
    std::string res = status + temp;
    return res;
}

std::string StringService::deTokenize(const char* token, 
    const char* buf)
{
    char temp[MAX_BUFFER_LENGTH];
    memset(temp, 0, MAX_BUFFER_LENGTH);
    strcpy(temp, buf);
    char* detoken = strtok(temp, token);
    std::string res = detoken;
    return res;
}