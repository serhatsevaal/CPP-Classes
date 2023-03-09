#include <iostream>
using namespace std;
#include <iomanip>
#include "date.h"

const int M = 12;	//number of months
static int dl[M] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
const char* months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "June", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };



bool Date::ifLeep() const {
    if(this->year%100==0){
        if(this->year%400==0){
            return 1;
        }
        return 0;
    }
    else if (this->year % 4 == 0) {
		return 1;
	}
    else{
        return 0;}
}

bool checkDate(Date date){
    if(!(2001 <= date.year)&&(date.year<=2021)){
        std::cout<<"Invalid entry";
        return 0;
    }
    if(date.month<0||date.month>12){
        std::cout<<"Invalid entry";
        return 0;
    }
    if(date.ifLeep()==1&&date.month==2&&date.day==29){
        return 1;
    }
    if(date.day>dl[date.month-1]){
        std::cout<<"Invalid entry";
        return 0;
    }
    else{
        return 1;
    }
    
}

int char_to_int(char c) {
	return c - '0';
}



Date::Date(int day, int month, int year) : day(day), month(month), year(year), format(Date::Format::CHAR_MONTH) {}

Date::Date(const char* date) : format(Date::Format::CHAR_MONTH) {
	this->day = char_to_int(date[0]) * 10 + char_to_int(date[1]);
	this->month = char_to_int(date[3]) * 10 + char_to_int(date[4]);
	this->year = char_to_int(date[6]) * 1000 + char_to_int(date[7] *100) + char_to_int(date[8] * 10)  + char_to_int(date[9] * 1);
}

void Date::SetFormat(Date::Format format) {
    this->format = format;
}

void Date::NextDay() {
	if ((this->day + 1) > dl[this->month - 1]) {
		this->day = 1;
		if (this->month + 1 > 12) {
			this->month = 1;
			this->year += 1;
		}
		else this->month += 1;
	}
	else {
		this->day += 1;
	}
}

void Date::PrevDay() {
	this->day -= 1;

	if ((this->day - 1) < 1) {
		this->month--;
		if (this->month < 1) 
		{
			this->year--;
			this->month = 12;

	    }
        if(this->ifLeep()==1&&this->month==2){
            this->day = 29;
        }
        else{
            this->day = dl[this->month-1];
        }
    
	}
}
	
bool Date::isEqual(const Date& date) {
	return this->day == date.day && this->month == date.month && this->year == date.year;
}

bool isLess(const Date& date1, const Date& date2) {
	if (date1.year == date2.year) {

		if (date1.month == date2.month) {

			if (date1.day == date2.day) {
				return 0;
			}
			return date1.day < date2.day;
		}
		return date1.month < date2.month;
	}
	return date1.year < date2.year;
}



void Date::SelectedDay(int days) {
	if (days < 0) {
		for (int i = 0; i < (days*-1); i++) {
			this->PrevDay();
		}
	}
	if (days > 0) {
		for (int i = 0; i < days; i++) {
			this->NextDay();
		}
	}
}

ostream& operator<<(ostream& out, Date date){
	if (date.format == Date::Format::NUMERICAL) {
		out << date.day << " ." << date.month << "." << date.year;
	}
	else {
		out << months[date.month - 1] << " " << date.day << " " << date.year;
	}
	return out;
}

istream& operator>>(istream& in, Date& date){
    
    do{
        std::cout << "Enter year : ";
        in >> date.year;
        
        std::cout << "Enter month: ";
        in >> date.month;
    
        std::cout << "Enter day: ";
        in >> date.day;}

    while(checkDate(date)==0);
    
	return in;
    
}


int NumberOfDays(Date d1, Date d2){
    int result = 0;
    
    if(isLess(d1, d2)){
        while(!(d1.isEqual(d2))){
            result++;
            d1.NextDay();
        }
    }
    
    else{
        while(!(d1.isEqual(d2))){
            result++;
            d2.NextDay();
        }
    }
    
    return result;
}
