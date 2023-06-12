#ifndef LIB_H
#define LIB_H

#endif // LIB_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <math.h>
#include <sstream>

using namespace std;

class Date {
    int day;
    int month;
    int year;
    string weekDay;
public:
    Date() {}
    Date(int d, int m, int y): day(d), month(m), year(y) {}
    Date(Date& obj) {day=obj.day; month=obj.month; year=obj.year;}
    void setDay(int d) {day=d;}
    void setMonth(int m) {month=m;}
    void setYear(int y) {year = y;}
    int getDay() {return day;}
    int getMonth() {return month;}
    int getYear() {return year;}
    string getWeekDay() {return weekDay;}

    void findDay();
};

string convert(string);
bool compare(string, string);

//VALIDATION
bool isValidFormat(const string&);
bool isDateCorrect(const string&);
