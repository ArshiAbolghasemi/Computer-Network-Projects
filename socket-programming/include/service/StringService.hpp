#include <string>
#include <vector>
#include <sstream>
#include <cctype>

enum StrFormat
{
    NUM,
    CHAR
};

std::vector<std::string> parseStringByDelim(
    std::string inp, char delim);

bool isStringAllFlag(std::string inp,
    enum StrFormat flag);
