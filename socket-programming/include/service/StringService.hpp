#ifndef _STRING_SERVICE_HPP_
#define _STRING_SERVICE_HPP_

#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <cstring>

#define MAX_BUFFER_LENGTH 1024 

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
        
        static std::string deTokenize(const char* token, 
            const char* buf);
};

#endif
