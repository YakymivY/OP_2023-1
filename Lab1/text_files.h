#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdio>

#include "text_files.cpp"

using namespace std;


int findSubstring(string, string, string);
void createFile(string);
string inputFilename();
string formInput(string);
string formOutput(string);
string askSub();
void swapSubstring(string, string);
void printFile(string);
void fillFile(int (*func)(), string);
int takeAnswer();
void randomStrings(int, string);
int askNumber();
int askType();


//POINTER MODE

char* PinputFilename();
char* PformIn(char*);
char* PformOut(char*);
void PrandomStrings(int, char*);
void PfillFile(char*);
char* inputString(FILE*, size_t);
char* PaskSub();
void PprintFile(char*);
int PfindSubstring(char*, char*, char*);
char* PfindSub(char*, char*);
void insertSubstring(char*, char*, int, int);
char* substring(char*, int, int);
void PswapSubstring(char*, char*);
char* PfindSubOut(char*, char*);