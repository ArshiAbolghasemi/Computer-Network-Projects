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
