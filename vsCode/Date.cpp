#include <string>
#include <iostream>
class Date
{
private:
    int month;
    int day;
    int totalday;
public:
    Date(int m, int d) : month(m), day(d)
    {
        if(m<8)
        {
            if(m%2==1)
                totalday = 31;
            else
                totalday = 30;
            if(m==2)
                totalday = 28;
        }
        else if(m >7)
        {
             if(m%2==1)
                totalday = 30;
            else
                totalday = 31;
        }
    }
    int daysInMonth()
    {
        return totalday;
    }
    int getDay()
    {
        return day;
    }
    int getMonth()
    {
        return month;
    }
    void nextDay()
    {
        if(totalday == day)
        {
            month++;
            if(month>12)
                month = 1;
            day = 1;
        }
        else
            day++;

    }
    std::string toString()
    {
        std::string date;
        if(month<10)
            date = "0"+std::to_string(month);
        else
            date = std::to_string(month);
        date +="/";
        if(day<10)
            date += "0"+ std::to_string(day);
        else
            date += std::to_string(day);
        return date;
    }

};