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
