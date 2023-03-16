#ifndef __DATETIME_HPP
#define __DATETIME_HPP

#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

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

    std::string toString();

    static DateTime* toDate(std::string str);
};

#endif