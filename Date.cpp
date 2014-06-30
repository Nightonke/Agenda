#include "Date.h"
#include <sstream>

bool isLeafYear(int year) {return (year % 4 == 0 && year % 100 != 0) ||(year % 400 == 0);}

int maxMday[2][12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
                      31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

std::string numToStr(int num) {
    std::stringstream ss;
    ss << num;
    std::string str = ss.str(); 
    if (num < 10) str = "0" + str;
    return str;
}

Date::Date() {}
Date::Date(int y, int m, int d, int h, int mi) {
    year_ = y;
    month_ = m;
    day_ = d;
    hour_ = h;
    minute_ = mi;
}

int Date::getYear(void) const {
    return year_;
}
void Date::setYear(int year) {
    year_ = year;
}

int Date::getMonth() const {
    return month_;
}
void Date::setMonth(int month) {
    month_ = month;
}

int Date::getDay() const {
    return day_;
}
void Date::setDay(int day) {
    day_ = day;
}

int Date::getHour() const {
    return hour_;
}
void Date::setHour(int hour) {
    hour_ = hour;
}

int Date::getMinute() const {
    return minute_;
}
void Date::setMinute(int minute) {
    minute_ = minute;
}

bool Date::isValid(Date date) {
    bool isLeaf = isLeafYear(date.getYear());
    if (date.getYear() < 1000 || 9999 < date.getYear()) return false;
    else if (date.getMonth() < 1 || date.getMonth() > 12) return false;
    else if (date.getDay() < maxMday[isLeaf][date.getMonth()] ||
             maxMday[isLeaf][date.getMonth()] < date.getDay()) return false;
    else if (date.getHour() < 0 || 23 < date.getHour()) return false;
    else if (date.getMinute() < 0 || 59 < date.getMinute()) return false;
    else return true;
}

Date Date::stringToDate(std::string dateString) {
    Date tempDate;
    std::stringstream ss;
    int tempNum;
    ss << dateString.substr(0, 4);
    ss >> tempNum;
    tempDate.setYear(tempNum);
    ss << dateString.substr(5, 2);
    ss >> tempNum;
    tempDate.setMonth(tempNum);
    ss << dateString.substr(8, 2);
    ss >> tempNum;
    tempDate.setDay(tempNum);
    ss << dateString.substr(11, 2);
    ss >> tempNum;
    tempDate.setHour(tempNum);
    ss << dateString.substr(14, 2);
    ss >> tempNum;
    tempDate.setMinute(tempNum);
    return tempDate;
}

std::string Date::dateToString(Date date) {
    std::string tempStr;
    tempStr += numToStr(date.getYear()) + "-";
    tempStr += numToStr(date.getMonth()) + "-";
    tempStr += numToStr(date.getDay()) + "/";
    tempStr += numToStr(date.getHour()) + ":";
    tempStr += numToStr(date.getMinute());
    return tempStr;
}

Date & Date::operator=(const Date & date) {
    this->year_ = date.getYear();
    this->month_ = date.getMonth();
    this->day_ = date.getDay();
    this->hour_ = date.getHour();
    this->minute_ = date.getMinute();
    return *this;
}

bool Date::operator==(const Date & date) const {
    return (this->year_ == date.getYear()
         && this->month_ == date.getMonth()
         && this->day_ == date.getDay()
         && this->hour_ == date.getHour()
         && this->minute_ == date.getMinute());
}

bool Date::operator>(const Date & date) const {
    if (this->year_ != date.getYear())
        return this->year_ > date.getYear();
    else if (this->month_ != date.getMonth())
        return this->month_ > date.getMonth();
    else if (this->day_ != date.getDay())
        return this->day_ > date.getDay();
    else if (this->hour_ > date.getDay())
        return this->hour_ > date.getHour();
    else
        return this->minute_ > date.getMinute();
}

bool Date::operator<(const Date & date) const {
    return !(*this > date) && !(*this == date);
}

bool Date::operator>=(const Date & date) const {
    return !(*this < date);
}

bool Date::operator<=(const Date & date) const {
    return !(*this > date);
}

