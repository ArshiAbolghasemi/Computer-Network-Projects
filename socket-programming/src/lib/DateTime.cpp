#include "DateTime.hpp"

DateTime::DateTime(int _day, int _month, int _year) : 
        day(_day),
        month(_month), 
        year(_year) {}

string DateTime::toString()
{
        stringstream ss;
        ss << this->day << DEFAULT_DELIMITER << this->month << DEFAULT_DELIMITER << this->year;

        string res;
        getline(ss, res);

        return res;
}

DateTime* DateTime::toDate(string str)
{
        stringstream ss;
        ss << str;
        string temp;
        vector<string> dateVec;

        while(getline(ss, temp, DEFAULT_DELIMITER))
        {
            dateVec.push_back(temp);
        }

        return (new DateTime(
                stoi(dateVec[0]),
                stoi(dateVec[1]),
                stoi(dateVec[2])
        ));
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

bool DateTime::isStringValidDate(std::string date)
{
        std::vector<std::string> strVec = parseStringByDelim(date, '-');
        if(strVec.size() != 3)
        {
                return false;
        }
        else if(isStringVectorNumber(strVec) == false)
        {
                return false;
        }
        else if(std::stoi(strVec[0]) > 31 || std::stoi(strVec[0]) == 0 ||
                std::stoi(strVec[1]) > 12 || std::stoi(strVec[1]) == 0 || 
                std::stoi(strVec[2]) == 0)
        {
                return false;
        }
        else 
        {
                return true;
        }
}

bool isStringVectorNumber(const std::vector<std::string> dateVec)
{
    for(auto vec: dateVec)
        {
            auto strit = vec.begin();
            while(strit != vec.end() && std::isdigit(*strit))
            {
                strit++;
            }
            if (!vec.empty() && strit != vec.end())
            {
                return false;
            }
        }
    return true;
}

std::vector<std::string> parseStringByDelim(std::string s,
    const char delim)
{
        std::stringstream ss; 
        ss << s;
        std::vector<std::string> strVec;
        std::string temp;
        while (std::getline(ss, temp, '-'))
        {
                strVec.push_back(temp);
        }
    return strVec;
}