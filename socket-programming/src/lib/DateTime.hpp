#ifndef __DATETIME_HPP
#define __DATETIME_HPP
#include <string>
#include <sstream>
#include <vector>
class DateTime
{
private:
    int day;
    int month;
    int year;
public:

    const char DEFAULT_DELIMITER = '-';

    DateTime(int _day, int _month, int _year);
    DateTime();
    static std::string dateToString(DateTime& d);
    static DateTime* stringToDate(std::string s);
    bool operator<(const DateTime& dt2);
};

#endif