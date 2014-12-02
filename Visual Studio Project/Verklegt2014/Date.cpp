#include "Date.h"
#include <iomanip>

// Day get and set
int Date::getDay()
{
	return _day; 
}
void Date::setDay(int value)
{
    _day = (value >= 1 && value <= DaysInMonth()) ? value : -1;
}
	
// Month get and set
int Date::getMonth()
{
	return _month;
}
void Date::setMonth(int value)
{
    _month = ((value >= 1 && value <= 12) ? value : -1);
}
	
// Year get and set
int Date::getYear()
{
	return _year;
}
void Date::setYear(const int value)
{
    _year = value;
}


bool Date::isLeapYear()
{
    int y = _year;
	if(y&0x80000000) y=-y;
    return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}

// helper function for boundary checks
int Date::DaysInMonth()
{
    switch (_month)
    {
        case 2:
            return isLeapYear() ? 29 : 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        default:
            return -1;
    }
}

Days Date::getDayOfWeek()
{
    return getDayOfWeek(_day, _month, _year);
}

Date Date::Yesterday()
{
    Date d = *(this);
    if (d._day == 1)
    {
        if (d._month == 1)
        {
            d._month = 12;
            d._year--;
        }
		else d._month--;
        d._day = d.DaysInMonth();
    }
	else d._day--;
    return d;
}

Date Date::Tomorrow()
{
    Date d = *(this);
    if (d._day == DaysInMonth())
    {
        d._day = 1;
        if (d._month == 12)
        {
            d._month = 1;
            d._year++;
        }
        else d._month++;
    }
	else d._day++;
    return d;
}

bool Date::isValid()
{
	return !(_month == -1 || _day == -1);
}

Date::Date(const int y, const int m, const int d)
{
    setDay(d);
    setMonth(m);
    setYear(y);
}

Days Date::getDayOfWeek(const int day, const int month, const int year)
{
	int w = day + (int)(2.6*((month+9)%12+1)-0.2) + 5*(year%4) + 4*(year%100) + 6*(year%400); // Gaussian method
	return (Days)(w%7);
}

const std::string Date::dayNames[] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
const std::string Date::monthNames[] = {"January","February","March","April","May","July","June","August","September","October","November","December"};


bool operator<(const Date a, const Date b)
{
	if(a._year < b._year) return true;
	else if(a._year > b._year) return false;
	else
	{
		if(a._month < b._month) return true;
		else if(a._month > b._month) return false;
		else
		{
			return a._day < b._day;
		}
	}
}
bool operator==(const Date a, const Date b)
{
	return a._year == b._year && a._month == b._month && a._day == b._day;
}
bool operator>(const Date a, const Date b)
{
	if(a._year < b._year) return false;
	else if(a._year > b._year) return true;
	else
	{
		if(a._month < b._month) return false;
		else if(a._month > b._month) return true;
		else
		{
			return a._day > b._day;
		}
	}
}

std::ostream& operator<<(std::ostream& out, Days day)
{
	out << Date::dayNames[(int)day];
	return out;
}

std::ostream& operator<<(std::ostream& out, Months month)
{
	out << Date::monthNames[(int)month];
	return out;
}

std::ostream& operator<<(std::ostream& out, Date date)
{
	out << ((date._day < 10 ? "0" : "") + std::to_string(date._day) + "/" + (date._month < 10 ? "0" : "") + std::to_string(date._month) + "/" + std::to_string(date._year));
	return out;
}

std::istream& operator>>(std::istream& in, Date& date)
{
	std::string s;
	in >> s;
	int i = s.find('/');
	if(i == -1) date = Date();
	else
	{
		int k = stoi(s.substr(0, i));
		int j = s.find('/', i+1);
		if(j == -1) date = Date();
		else
		{
			date.setMonth(stoi(s.substr(i+1, j-i-1)));
			date.setYear(stoi(s.substr(j+1, s.length()-j-1)));
			date.setDay(k);
		}
	}

	return in;
}