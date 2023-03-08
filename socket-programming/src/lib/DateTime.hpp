#ifndef __DATETIME_HPP
#define __DATETIME_HPP

class DateTime
{
private:
    int day;
    int month;
    int year;
public:

    const char DEFAULT_DELIMITER = '-';

    DateTime(int _day, int _month, int _year);
};

#endif