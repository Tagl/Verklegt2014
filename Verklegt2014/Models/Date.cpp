#include "Date.h"

// Day get and set
int Date::getDay()
{
	return _day; 
}
void Date::setDay(int value)
{
    _day = value;
}
	
// Month get and set
int Date::getMonth()
{
	return _month;
}
void Date::setMonth(int value)
{
    _month = value;
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
// http://cmcenroe.me/2014/12/05/days-in-month-formula.html
int Date::DaysInMonth()
{
    int x = _month;
    return 28 + (x + x/8) % 2 + 2 % x + 2 * (1/x) + (_month == 2 ? isLeapYear() : 0);
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

QDate Date::toQDate()
{
    return QDate(_year, _month, _day);
}

bool Date::isValid()
{
    if(_day < 1 || _day > DaysInMonth() || _month < 1 || _month > 12) return false;
    return true;
}

Date::Date(const int y, const int m, const int d)
{
    setYear(y);
    setMonth(m);
    setDay(d);
}

Date::Date(QDate d)
{
    setYear(d.year());
    setMonth(d.month());
    setDay(d.day());
}

Days Date::getDayOfWeek(const int day, const int month, const int year)
{
	int w = day + (int)(2.6*((month+9)%12+1)-0.2) + 5*(year%4) + 4*(year%100) + 6*(year%400); // Gaussian method
	return (Days)(w%7);
}

Date Date::fromString(const QString s)
{
    Date d;
    int i = s.indexOf('/');
    if(i == -1) d = Date();
    else
    {
        int k = s.mid(0,i).toInt();
        int j = s.indexOf('/', i+1);
        if(j == -1) d = Date();
        else
        {
            d.setMonth(s.mid(i+1, j-i-1).toInt());
            d.setYear(s.mid(j+1, s.length()-j-1).toInt());
            d.setDay(k);
        }
    }

    return d;
}

std::string Date::toString()
{
    return (QString(_day < 10 ? "0" : "") + QString::number(_day) + QString("/") + QString(_month < 10 ? "0" : "") + QString::number(_month) + QString("/") + QString::number(_year)).toStdString();
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
    out << (QString(date._day < 10 ? "0" : "") + QString::number(date._day) + QString("/") + QString(date._month < 10 ? "0" : "") + QString::number(date._month) + QString("/") + QString::number(date._year)).toStdString();
	return out;
}

std::istream& operator>>(std::istream& in, Date& date)
{
	std::string s;
	in >> s;
    QString qs = QString::fromStdString(s);
    date = Date::fromString(qs);

	return in;
}
