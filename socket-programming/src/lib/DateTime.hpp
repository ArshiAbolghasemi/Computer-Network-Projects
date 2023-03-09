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
    static void stringToDate(std::string s, DateTime& d);

};

#endif