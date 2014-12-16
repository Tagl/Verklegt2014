#pragma once
#include <Qstring>
#include <QDate>
#include <string>
#include <fstream>

#define ALIVE Date(0,0,0)

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

class Date
{
private:
	static const std::string dayNames[];
	static const std::string monthNames[];


    int _day;
    int _month;
    int _year;

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

    Date Yesterday();

    Date Tomorrow();

    QDate toQDate();

    bool isValid();

    Date(const int y = 0, const int m = 0, const int d = 0);
    Date(QDate d);

    static Date fromString(const QString s);
    static Days getDayOfWeek(const int day, const int month, const int year);


	friend bool operator<(const Date a, const Date b);
	friend bool operator==(const Date a, const Date b);
	friend bool operator>(const Date a, const Date b);
	friend std::ostream& operator<<(std::ostream& out, Days day);
	friend std::ostream& operator<<(std::ostream& out, Months month);
	friend std::ostream& operator<<(std::ostream& out, Date date);
	friend std::istream& operator>>(std::istream& in, Date& date);
};
