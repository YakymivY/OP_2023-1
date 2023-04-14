#include "class.h"

using namespace std;

//additional function to get number from certain diapason from user
int askNumber (int min, int max) {
    int ans;
    int error;
    do {
        cin>>ans;
        if (cin.fail()){
            cin.clear();
            fflush(stdin);
            cout<<"You have entered wrong input. Try again:"<<endl;
            error = 1;
        } else {
            if (ans < min) {
                cout<<"The value must be greater than "<<min<<endl;
                error = 1;
            } else if (ans > max) {
                cout<<"The value must be smaller than "<<max<<endl;
                error = 1;
            } else {
                error = 0;
            }    
        }
    } while(error);
    return ans;
}

//additional function to get y/n answer from user
int takeAnswer(string message) {
    char ans;
    int error;
    int returnAns;
    do {
        cout<<message<<" (y/n)"<<endl;
        fflush(stdin);
        cin>>ans;
        if ((ans == 'y') || (ans == 'Y')) {
            error = 0;
            returnAns = 1;
        } else {
            if ((ans == 'n') || (ans == 'N')) {
                error = 0;
                returnAns = 0;
            } else {
                cout<<"Answer must be y or n."<<endl;
                error = 1; 
            }
        }
    } while(error);
    return returnAns;
}

//function to take amount of texts user wants to create
int takeAmount () {
    cout<<"Enter number of texts you want to create (1 to 10):"<<endl;
    int amount = askNumber(1, 10);
    return amount;
}

//function that fills texts with content using generation or user-input
void createArray (Text array[], int amount) {
    int answer;
    for (int i = 0; i < amount; i++) {

        cout<<"\nSelect the way to fill Text №"<<i+1<<endl;
        cout<<"\t1. Generate text"<<endl;
        cout<<"\t2. Input strings"<<endl;

        int choice = askNumber(1, 2);
        //if number 1 is chosen
        if (choice - 1) {
            do {
                array[i].createText(); //taking user-input
                answer = takeAnswer("Do you want to add one more string?");
            } while (answer);
        } else { //if number 2 is chosen
            array[i].generateText(); //generating text
            array[i].countConsonants(); //counting consonants for generated text
        }
        array[i].print();
    }
}

//function that counts consonants of given string (not all the content of object)
int count (string str) {
    int consonants = 0;
    for (int i = 0; i < str.length(); i++) {
        //checking whether character is consonant
        if (str[i] != 'a' && str[i] != 'e' && str[i] != 'u' && str[i] != 'i' && str[i] != 'o' &&
        str[i] != 'A' && str[i] != 'E' && str[i] != 'U' && str[i] != 'I' && str[i] != 'O' &&
        ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))) {
            consonants++;
        }
    }
    return consonants;
}

//function that adds strings to e certain text
void addText (Text array[], int amount) {
    int answer;
    int ans;
    int choice;
    answer = takeAnswer("\nDo you want to add a string to one of the texts?");
    if (answer) {
        do {
            cout<<"Choose number of text to add string to"<<endl;
            choice = askNumber(1, amount); //asking which text user wants to update
            array[choice-1].print();
            do {
                array[choice-1].createText();
                ans = takeAnswer("Do you want to add one more string?");
            } while (ans);
            array[choice-1].print();
            answer = takeAnswer("\nDo you want to add a string to one of the texts?");
        } while (answer);
    }
    array[choice-1].print();
}

//function that finds the greatest percent of consonants among the objects
void findBiggest (Text array[], int amount) {
    int max = 0;
    for (int i = 0; i < amount; i++) {
        if (array[i].percent > array[max].percent) {
            max = i; //setting current element as maximum
        }
    }
    cout<<"\nText №"<<max+1<<" has the highest percent of consonants ("<<array[max].percent<<"%)"<<endl;
}

//method that adds string inputted by user to content of the object
void Text::createText () {
    string str;
    cout<<"Enter string to add to the text:"<<endl;
    fflush(stdin);
    getline(cin, str);
    content.append(str);
    //finding number of letters in string
    for (int i = 0; i < str.length(); i++) {
        if(str[i] != ' ') {
            length++;
        } 
    }
    //finding number of consonants in string
    consonants += count(str);
    percent = (float)consonants / length * 100;
    content.append("\n");
}

//method that generates random pieces of text and adds it to content
void Text::generateText () {
    string mainStr;
    string characters = "abcdefghigklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; //characters to choose from
    srand((unsigned) time(NULL));

    mainStr = "";
    for (int k = 0; k < 40; k++) { //there will be 40 words
        for (int i = 0; i < 10; i++) { //word consists of 10 characters
            int j = rand() % characters.length();
            mainStr += characters[j];
        }
        length += 10; //updating length of content
        mainStr.append(" ");
        if ((rand() % 10) == 1) { //random newline input 10%
            mainStr.append("\n");
        }
    }
    mainStr.append("\n");
    content.append(mainStr);
}

//method that prints content, number of consonants and percents of consonants
void Text::print () {
    cout<<"\nCONTENT:\n"<<endl;
    printf("%s", content.c_str());
    cout<<"\nConsonants: "<<consonants<<endl;
    cout<<"Percentage: "<<percent<<"%"<<endl;
}

//method that counts consonants in full text
void Text::countConsonants () {
    for (int i = 0; i < content.length(); i++) {
        if (content[i] != 'a' && content[i] != 'e' && content[i] != 'u' && content[i] != 'i' && content[i] != 'o' &&
        content[i] != 'A' && content[i] != 'E' && content[i] != 'U' && content[i] != 'I' && content[i] != 'O' &&
        ((content[i] >= 'a' && content[i] <= 'z') || (content[i] >= 'A' && content[i] <= 'Z'))) {
            consonants++;
        }
    }
    percent = (float)consonants / length * 100; //counting percent of consonants
}