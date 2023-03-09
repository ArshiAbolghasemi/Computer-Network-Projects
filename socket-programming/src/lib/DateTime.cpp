#include "DateTime.hpp"

DateTime::DateTime(int _day, int _month, int _year) : 
        day(_day),
        month(_month), 
        year(_year) {}
DateTime::DateTime() {}
std::string DateTime::dateToString(DateTime& d)
{
        std::stringstream ss;
        ss << d.day << "-" << d.month << "-" 
            << d.year;
        std::string result;
        std::getline(ss, result);
        return result;
}
DateTime* DateTime::stringToDate(std::string s)
{
        std::stringstream ss;
        ss << s;
        std::string temp;
        std::vector<std::string> dateVec;
        while(std::getline(ss, temp, '-'))
        {
            dateVec.push_back(temp);
        }
        DateTime* returnClass = new(DateTime);
        returnClass->day = std::stoi(dateVec[0]);
        returnClass->month = std::stoi(dateVec[1]);
        returnClass->year = std::stoi(dateVec[2]);
        return returnClass;
}

bool DateTime::operator<(const DateTime& dt2)
{
        tm* t1 = new(tm);
        t1->tm_year = this->year;
        t1->tm_mon = this->month;
        t1->tm_mday = this->day;
        tm* t2 = new(tm);
        t2->tm_year = dt2.year;
        t2->tm_mon = dt2.month;
        t2->tm_mday = dt2.day;
        time_t left = mktime(t1);
        time_t right = mktime(t2);
        if(left < right)
        {
            return true;
        }
        return false;
}