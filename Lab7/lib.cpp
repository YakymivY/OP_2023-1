#include "lib.h"

using namespace std;

void Date::findDay () {
    string days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    int intercelary;
    if ((year % 100 != 0 && year % 4 == 0) || (year % 100 == 0 && year % 400 == 0)) {
        intercelary = 1;
    } else {
        intercelary = 0;
    }

    int n = 0;
    if (month > 2) {
        n = 0;
    } else {
        if (intercelary && month <= 2) {
            n = 1;
        } else {
            if (!intercelary && month <= 2) {
                n = 2;
            }
        }
    }

    float year_mod = 365.25 * year;
    float month_mod = 30.56 * month;
    int dayOfWeek = ((int)year_mod + (int)month_mod + day + n) % 7;

    weekDay = days[dayOfWeek];
}


string convert (string str) {
    stringstream ss(str);

    string dayStr, monthStr, yearStr;

    getline(ss, dayStr, '.');
    getline(ss, monthStr, '.');
    getline(ss, yearStr);

    int day = stoi(dayStr);
    int month = stoi(monthStr);
    int year = stoi(yearStr);

    Date date(day, month, year);
    date.findDay();
    string result = date.getWeekDay();

    return result;
}

bool compare (string str1, string str2) {
    if (str1 == str2) {
        return true;
    } else {
        return false;
    }
}



//VALIDATION
bool isValidFormat (const string& date) {
    if (date.length() != 10) {
        return false;
    }

    for (int i = 0; i < 10; i++) {
        if (i == 2 || i==5) {
            if(date[i] != '.') {
                return false;
            }
        }
    }
    return true;
}

bool isDateCorrect(const string & str) {
    stringstream ss(str);

    string dayStr, monthStr, yearStr;

    getline(ss, dayStr, '.');
    getline(ss, monthStr, '.');
    getline(ss, yearStr);

    int day = stoi(dayStr);
    int month = stoi(monthStr);
    int year = stoi(yearStr);

    int intercelary;
    if ((year % 100 != 0 && year % 4 == 0) || (year % 100 == 0 && year % 400 == 0)) {
        intercelary = 1;
    } else {
        intercelary = 0;
    }

    //main part
    if (month <= 12 && day <= 31 && year <= 9999) {
        if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month ==12) && day <= 31) {
            return true;
        } else if (month != 2 && day <= 30) {
            return true;
        } else {
            if (intercelary && day <= 29) {
                return true;
            }
            if (day <= 28) {
                return true;
            }
        }
    }
    return false;
}
