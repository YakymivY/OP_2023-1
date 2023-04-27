#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <iomanip>

using namespace std;

class MultiSet {
    string name;
    string content;
    public:
        //constructors
        MultiSet(): content(""), name("") {}
        MultiSet(string);
        MultiSet(int, string);
        MultiSet(string, string);
        MultiSet(MultiSet&);
        MultiSet(const MultiSet&);
        ~MultiSet() {}
        //getters & setters
        string getName();
        string getContent();
        void setName(string);
        void setContent(string);
        //methods
        void print();
        bool findElement(char);
        //overloading
        MultiSet operator+ (const MultiSet);
        MultiSet operator* (const MultiSet);
        MultiSet operator- (MultiSet);
};

//additional functions
string inputString(string);
int inputNumber(string);