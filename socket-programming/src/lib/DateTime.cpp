#include "../../include/lib/DateTime.hpp"

DateTime::DateTime(int _day, int _month, int _year) : 
        day(_day),
        month(_month), 
        year(_year) {}

std::string DateTime::toString()
{
        std::stringstream ss;
        ss << this->day << DEFAULT_DELIMITER << this->month << DEFAULT_DELIMITER << this->year;

        std::string res;
        std::getline(ss, res);

        return res;
}

DateTime* DateTime::toDate(std::string str)
{
        std::stringstream ss;
        ss << str;
        std::string temp;
        std::vector<string> dateVec;

        while(std::getline(ss, temp, DEFAULT_DELIMITER))
        {
            dateVec.push_back(temp);
        }

        return (new DateTime(
                std::stoi(dateVec[0]),
                std::stoi(dateVec[1]),
                std::stoi(dateVec[2])
        ));
}
