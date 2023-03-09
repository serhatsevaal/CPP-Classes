#pragma once

#include <iostream>
using namespace std;

class Date
{
public:
    enum class Format {
            NUMERICAL,
            CHAR_MONTH,
        };
    
private:
	int day = 9;
	int month = 3;
	int year = 2021;

	Format format;

	bool ifLeep() const;

public:
	Date(int day = 9, int month = 3, int year =2021);
	Date(const char* date);

	void NextDay();
	void PrevDay();
	void SelectedDay(int days = 7);
	bool isEqual(const Date& date);
	friend bool isLess(const Date& date1, const Date& date2);
	void SetFormat(Date::Format format);

	friend ostream& operator<<(ostream& out, Date date) ;
	friend istream& operator>>(istream& in, Date& date);
	friend int NumberOfDays(Date d1, Date d2);
    friend bool checkDate(Date date);
};

int NumberOfDays(Date d1, Date d2);
