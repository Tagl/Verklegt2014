#pragma once
#include <string>
#include <fstream>

enum Months
{
    Jan = 1,
    Feb,
    Mar,
    Apr,
    May,
    Jun,
    Jul,
    Aug,
    Sept,
    Oct,
    Nov,
    Dec
};

enum Days
{
    Sun = 0,
    Mon,
    Tue,
    Wed,
    Thu,
    Fri,
    Sat
};

class DateTime
{
private:
    static const unsigned long long MICROSECOND = 1000;
    static const unsigned long long MILLISECOND = 1000 * MICROSECOND;
    static const unsigned long long SECOND = 1000 * MILLISECOND;
    static const unsigned long long MINUTE = 60 * SECOND;
    static const unsigned long long HOUR = 60 * MINUTE;
	static const std::string dayNames[7];

    unsigned long long _time;

    int _day;
    int _month;
    int _year;

	
    unsigned long long getRawHours();
	
    unsigned long long getRawMinutes();
	
    unsigned long long getRawSeconds();
	
    unsigned long long getRawMilliseconds();
	
    unsigned long long getRawMicroseconds();

public:
    int getDay();
    void setDay(int value);
	

    int getMonth();
	void setMonth(int value);
	

    int getYear();
	void setYear(const int value);

    bool isLeapYear();

    int DaysInMonth();

    Days getDayOfWeek();

    DateTime Yesterday();

    DateTime Tomorrow();

    bool isValid();

    DateTime(const int y = 0, const int m = 0, const int d = 0, const int h = 0, const int min = 0, const int s = 0, const int ms = 0, const int µs = 0, const int ns = 0);

    static Days getDayOfWeek(const int day, const int month, const int year);

    /// <summary>
    /// Raw time is represented in (nano)seconds
    /// </summary>
    unsigned long long getRawTime();
	
	void setRawTime(const unsigned long long value);

    int getHours();
    int getMinutes();
    int getSeconds();
    int getMilliseconds();
    int getMicroseconds();
    int getNanoseconds();

	friend std::ostream& operator<<(std::ostream& out, Days day);
};