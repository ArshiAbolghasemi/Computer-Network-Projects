#include "../../include/lib/DateTime.hpp"

DateTime::DateTime(int _day, int _month, int _year) : 
        day(_day),
        month(_month), 
        year(_year) {}

std::string DateTime::toString()
{
        std::stringstream ss;
        ss << std::setfill('0') << std::setw(2) << this->day
           << DEFAULT_DELIMITER 
           << std::setfill('0') << std::setw(2) << this->month 
           << DEFAULT_DELIMITER 
           << this->year;

        std::string res;
        std::getline(ss, res);

        return res;
}

DateTime* DateTime::toDate(std::string str)
{
        std::vector<std::string> dateVec =
        StringService::parseStringByDelim(str,
                DEFAULT_DELIMITER);
        return (new DateTime(
                std::stoi(dateVec[0]),
                std::stoi(dateVec[1]),
                std::stoi(dateVec[2])));
}
