#include "DateTime.h"

int DateTime::getDay()
{
	return _day; 
}
void DateTime::setDay(int value)
{
    _day = (value >= 1 && value <= DaysInMonth()) ? value : -1;
}
	

int DateTime::getMonth()
{
	return _month;
}
void DateTime::setMonth(int value)
{
    _month = ((value >= 1 && value <= 12) ? value : -1);
}
	

int DateTime::getYear()
{
	return _year;
}
void DateTime::setYear(const int value)
{
    _year = value;
}

bool DateTime::isLeapYear()
{
    int y = _year;
	if(y&0x80000000) y=-y;
    return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}

int DateTime::DaysInMonth()
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

Days DateTime::getDayOfWeek()
{
    return getDayOfWeek(_day, _month, _year);
}

DateTime DateTime::Yesterday()
{
    DateTime d = *(this);
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

DateTime DateTime::Tomorrow()
{
    DateTime d = *(this);
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

bool DateTime::isValid()
{
	return !(_month == -1 || _day == -1);
}

DateTime::DateTime(const int y, const int m, const int d, const int h, const int min, const int s, const int ms, const int µs, const int ns)
{
    _year = y;
    _month = m;
    _day = d;
    _time = h * HOUR + min * MINUTE + s * SECOND + ms * MILLISECOND + µs * MICROSECOND + ns;
}

Days DateTime::getDayOfWeek(const int day, const int month, const int year)
{
	int w = day + (int)(2.6*((month+9)%12+1)-0.2) + 5*(year%4) + 4*(year%100) + 6*(year%400);
	return (Days)(w%7);
}

/// <summary>
/// Raw time is represented in (nano)seconds
/// </summary>
unsigned long long DateTime::getRawTime()
{
	return _time; 
}

void DateTime::setRawTime(const unsigned long long value)
{
    _time = value;
}

int DateTime::getHours()
{
    return (int)(getRawTime() / HOUR);
}
int DateTime::getMinutes()
{
    return (int)((getRawTime() - getRawHours()) / MINUTE);
}
int DateTime::getSeconds()
{
    return (int)((getRawTime() - getRawHours() - getRawMinutes()) / SECOND);
}
int DateTime::getMilliseconds()
{
    return (int)((getRawTime() - getRawHours() - getRawMinutes() - getRawSeconds()) / MILLISECOND);
}
int DateTime::getMicroseconds()
{
    return (int)((getRawTime() - getRawHours() - getRawMinutes() - getRawSeconds() - getRawMilliseconds()) / MICROSECOND);
}
int DateTime::getNanoseconds()
{
    return (int)((getRawTime() - getRawHours() - getRawMinutes() - getRawSeconds() - getRawMilliseconds() - getRawMicroseconds()));
}

unsigned long long DateTime::getRawHours()
{
	return getHours() * HOUR;
}
	
unsigned long long DateTime::getRawMinutes()
{
    return getMinutes() * MINUTE;
}
	
unsigned long long DateTime::getRawSeconds()
{
    return getSeconds() * SECOND;
}
	
unsigned long long DateTime::getRawMilliseconds()
{
    return getMilliseconds() * MILLISECOND;
}
	
unsigned long long DateTime::getRawMicroseconds()
{
    return getMicroseconds() * MICROSECOND;
}

const std::string DateTime::dayNames[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};


std::ostream& operator<<(std::ostream& out, Days day)
{
	out << DateTime::dayNames[(int)day];
	return out;
}