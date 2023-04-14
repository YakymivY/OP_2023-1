#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <iomanip>

using namespace std;

class Text {
    string content;
    unsigned int consonants;
    unsigned int length; 
    float percent;
    public: 
        Text (): content(""), consonants(0), length(0), percent(0) {}
        void createText();
        void generateText();
        void print();
        void countConsonants();
        friend void findBiggest(Text[], int);
};

int askNumber(int, int);
int takeAnswer(string);
int takeAmount();
void createArray(Text[], int);
int count(string);
void addText(Text[], int);
void findBiggest(Text[], int);