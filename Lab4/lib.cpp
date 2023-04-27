#include "lib.h"

using namespace std;

//constructor that takes obj name as parameter
MultiSet::MultiSet(string sname) {
    name = sname;
    cout<<"Enter sequence of symbols for "<<name<<" (without spaces)"<<endl;
    fflush(stdin); //clear buffer
    cin>>content;
}

//constructor that takes set length and name as parameter
MultiSet::MultiSet(int num, string sname) {
    name = sname;
    string list = "abcdefghijklmnopqrstuvwxyz1234567890";
    string input;
    char character;
    for (int i = 0; i < num; i++) {
        character = list[rand() % list.length()];
        if (input.find(character) != string::npos) {
            num++;
        } else {
            input += character;
        }
    }
    content = input;
    cout<<"Here is a content of set "<<name<<":\n"<<content<<endl;
}

//constructor that takes obj name and set as parameter
MultiSet::MultiSet(string sname, string scontent) {
    name = sname;
    content = scontent;
}

//copy constructor
MultiSet::MultiSet(MultiSet &Obj) {
    content = Obj.content;
    name = Obj.name;
}

//const copy constructor
MultiSet::MultiSet(const MultiSet &Obj) {
    content = Obj.content;
    name = Obj.name;
}

//name getter
string MultiSet::getName() {
    return name;
}

//content getter
string MultiSet::getContent() {
    return content;
}

//name setter
void MultiSet::setName (string str) {
    name = str;
}

//content setter
void MultiSet::setContent (string str) {
    content = str;
}

//methods that prints content of object
void MultiSet::print () {
    cout<<"Here is a content of set "<<name<<":\n"<<content<<endl;
}

//method that finds character in set
bool MultiSet::findElement(char elem) {
    bool answer;
    size_t found = content.find(elem);
    found != string::npos ? answer = true : answer = false;
    return answer;
}

//plus sign overloading
MultiSet MultiSet::operator+ (const MultiSet obj) {
    MultiSet tmp;
    string newStr = content;
    for (int i = 0; i < obj.content.length(); i++) {
        if (!this->findElement(obj.content[i])) { //if there is no [i] element in left object
            newStr += obj.content[i];
        }
    }
    tmp.content = newStr;
    return tmp;
}

//multiply sign overloading
MultiSet MultiSet::operator* (const MultiSet obj) {
    MultiSet tmp;
    string newStr = "";
    for (int i = 0; i < obj.content.length(); i++) {
        if (this->findElement(obj.content[i])) { //if there is [i] element in left object
            newStr += obj.content[i];
        }
    }
    tmp.content = newStr;
    return tmp;
}

//minus sign overloading
MultiSet MultiSet::operator- (MultiSet obj) {
    MultiSet tmp;
    string newStr = "";
    for (int i = 0; i < content.length(); i++) {
        if (!obj.findElement(content[i])) {
            newStr += content[i]; //adding all unique elements from left object
        }
    }
    for (int j = 0; j < obj.content.length(); j++) {
        if (!this->findElement(obj.content[j])) {
            newStr += obj.content[j]; //adding all unique elements from right object
        }
    }
    tmp.content = newStr;
    return tmp;
}


//function that takes string from user
string inputString (string name) {
    string str;
    cout<<"Enter sequence of symbols for "<<name<<" (without spaces)"<<endl;
    fflush(stdin);
    cin>>str;
    return str;
}

//function that takes int number from user (1-36)
int inputNumber(string name) {
    int num;
    int error;
    do {
        cout<<"Enter number of symbols in set "<<name<<": (1-36)"<<endl;
        fflush(stdin);
        cin>>num; 
        if (num < 1 || num > 36) {
            cout<<"Incorrect input. Value mist be from 1 to 36"<<endl;
            error = 1;
        } else {
            error = 0;
        }
    } while(error);
    return num;
}