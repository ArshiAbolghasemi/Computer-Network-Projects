#ifndef _STRING_SERVICE_HPP_
#define _STRING_SERVICE_HPP_

#include <string>
#include <vector>
#include <sstream>
#include <cctype>


enum StrFormat
{
    NUM,
    CHAR
};

class StringService
{
    private:

    public:
        static std::vector<std::string> parseStringByDelim(
            std::string inp, char delim);

        static bool isStringAllFlag(std::string inp,
            enum StrFormat flag);
        
        static std::string addStatus(const char* inp,
            std::string status);
};

#endif
