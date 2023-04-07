#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <iomanip>

#define MAX_CITY 20

using namespace std;

struct Route {
    int id;
    char departure[MAX_CITY];
    char destination[MAX_CITY];
    int depTime[2];
    int destTime[2];
};

string inputFilename();
int inputInt(int, int);
char* inputCity();
int* inputTime();
int inputAns(string);
void addRoute(string);
string printMinutes(int);
void printFile(string);
void newSchedule(string);