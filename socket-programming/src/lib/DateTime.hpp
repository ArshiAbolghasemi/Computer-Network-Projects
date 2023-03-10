#ifndef __DATETIME_HPP
#define __DATETIME_HPP

#include <string>
#include <sstream>
#include <vector>

using namespace std;

class DateTime
{
private:
    int day;
    int month;
    int year;
public:

    static const char DEFAULT_DELIMITER = '-';

    DateTime(int _day, int _month, int _year);

    string toString();

    static DateTime* toDate(string str);

    bool operator<(const DateTime& dt2);

    bool isStringValidDate(std::string date);
};

bool isStringVectorNumber(const std::vector<std::string> dateVec);

std::vector<std::string> parseStringByDelim(std::string,
    const char delim);

#endif