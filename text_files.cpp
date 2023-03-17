#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdio>

using namespace std;

int findSubstring (string sub, string file, string fileOut) {
    //variables
    int subl = sub.length();
    string fString;

    //open file
    ifstream myFile(file);
    if (!myFile) {
        cout<<"\nERROR. Cannot open the file"<<endl;
        return 0;
    }
    
    //output file
    ofstream myOutput(fileOut);
    if (!myOutput) {
        cout<<"\nERROR. Could not create output file"<<endl;
        return 0;
    }

    //main func
    while(!myFile.eof()){
        getline(myFile, fString);

        int index = 0;
        int subCounter = 0;
        while((index = fString.find(sub, index)) != string::npos) {
            subCounter++;
            fString.insert(index, "[");
            fString.insert(index + subl + 1, "-" + to_string(subCounter) + "]");
            index += subl;
        }
        
        //output
        myOutput<<fString<<endl;
    }

    //return
    myFile.close();
    myOutput.close();
    return 0;
}


string inputFilename () {
    string fileName;
    cout<<"Enter the name of the file to open(create):"<<endl;
    cin>>fileName;
    return fileName;
}

string  formInput (string file) {
    string newFile; 
    newFile = file + ".txt";
    return newFile;
}

string formOutput (string file) {
    string newFile;
    newFile = file + "_out.txt";
    return newFile;
}


void swapSubstring (string sub, string fileOut) {
    string firstName = fileOut;
    string secondName = "sup.txt";

    ifstream swapFile(firstName);
    if (!swapFile) {
        cout<<"\nERROR. Cannot open the file"<<endl;
        return;
    }

    ofstream inputFile(secondName);
    if (!inputFile) {
        cout<<"\nERROR. Could not create output file"<<endl;
        return;
    }

    string swapStr;
    size_t start, middle, end, rest;
    string sub1, sub2;
    int index;
    while(!swapFile.eof()){
        index = 0;
        getline(swapFile, swapStr);

        while((index = swapStr.find('[', index)) != string::npos) {
            start = index;
            middle = start + sub.length() + 1;
            end = swapStr.find(']', index);

            rest = end - middle;

            sub1 = sub;
            sub2 = swapStr.substr(middle+1, rest-1);

            swapStr.replace(start+1, sub.size(), sub2);
            middle = swapStr.find('-', index);
            end = swapStr.find(']', index);
            swapStr.replace(middle+1, rest-1, sub1);
            index += sub.length() + 2;
        }

        inputFile<<swapStr<<endl;
    }
    swapFile.close();
    inputFile.close();

    remove(firstName.c_str());
    rename(secondName.c_str(), firstName.c_str());
}


string askSub() {
    string sub;
    cout<<"Enter substring you want to search in the text"<<endl;
    cin>>sub;
    return sub;
}

void printFile(string name) {
    ifstream myFile(name);
    string str;
    cout<<'\n'<<endl;
    while(!myFile.eof()){
        getline(myFile, str);
        cout<<str<<endl;
    }
    myFile.close();
}

void fillFile(int (*takeAnswer)(), string file) {
    string mainStr;
    int answer;

    ofstream theFile;
    theFile.open(file, ios::app);
    if (!theFile) {
        cout<<"\nERROR. Could not open output file"<<endl;
        return;
    }

    do {
        cout<<"Enter string to put into a file:"<<endl;
        fflush(stdin);
        getline(cin, mainStr);
        theFile<<mainStr<<endl;
        answer = takeAnswer();
    } while(answer);

    theFile.close();
}

int takeAnswer() {
    char ans;
    int error;
    int returnAns;
    do {
        cout<<"Do you want to add one more string? (y/n)"<<endl;
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

void randomStrings (int num, string file) {
    ofstream randomFile;
    randomFile.open(file, ios::app);
    if (!randomFile) {
        cout<<"\nERROR. Could not open output file"<<endl;
        return;
    }

    string mainStr;
    string characters = "abcdefghigkl";
    srand((unsigned) time(NULL));

    for (int k = 0; k < num; k++) {
        mainStr = "";
        for (int i = 0; i < 10; i++) {
            int j = rand() % 12;
            mainStr += characters[j];
        }
        randomFile<<mainStr<<' ';
        if ((rand() % 20) == 10) {
            randomFile<<'\n';
        }
    }
    randomFile<<'\n';

    randomFile.close();
}

int askNumber () {
    int error;
    int value;
    do {
        cout<<"Enter number of words to generate into the file(1 to 500):"<<endl;
        cin>>value;
        if (value < 1 || value > 500) {
            error = 1;
            cout<<"Number must be between 1 and 500"<<endl;
        } else {
            error = 0;
        }
    } while (error);
    return value;
}

int askType() {
    int error;
    int value;
    do {
        cout<<"Choose the way to fill the file(1 or 2):"<<endl;
        cout<<"\t1. Generate random words"<<endl;
        cout<<"\t2. Input words from the keyboard"<<endl;

        cin>>value;
        if (value == 1 || value == 2) {
            error = 0;
        } else {
            error = 1;
            cout<<"You should enter 1 or 2"<<endl;
        }
    } while(error);
    return (value - 1);
}



//POINTER MODE
//POINTER MODE
//POINTER MODE
//POINTER MODE
//POINTER MODE


char* inputString (FILE* fp, size_t size) {
    char *str;
    int ch;
    size_t len = 0;
    str = (char*)realloc(NULL, sizeof(*str)*size);
    if(!str) return str;
    fflush(stdin);
    while(EOF != (ch=fgetc(fp)) && ch != '\n'){
        str[len++] = ch;
        if (len == size) {
            str = (char*)realloc(str, sizeof(*str)*(size+=16));
            if (!str) return str;
        }
    }
    str[len++] = '\0';

    return (char*)realloc(str, sizeof(*str)*len);
}


char* PinputFilename () {
    char* filename;
    cout<<"Enter the name of the file to open(create) without extension:"<<endl;
    filename = inputString(stdin, 15);
    return filename;
}

char* PformIn (char* file) {
    char* fileIn;
    fileIn = strcat(file, ".txt");
    return fileIn;
}

char* PformOut (char* file) {
    char* fileOut;
    fileOut = strcat(file, "_out.txt");
    return fileOut;
}

void PrandomStrings (int num, char* file) {
    FILE *fp;
    fp = fopen(file, "a+");
    if (fp == NULL) {
        cout<<"\nERROR. Could not open output file"<<endl;
        return;
    }
    char mainStr[11];
    char characters[] = "abcdefghijkl";
    srand((unsigned) time(NULL));

    for (int k = 0; k < num; k++) {
        strncpy(mainStr, "", sizeof(mainStr));
        for (int i = 0; i < 10; i++) {
            int j = rand() % 12;
            mainStr[i] = characters[j];
        }
        mainStr[10] = '\0';
        //write mainStr into file
        fprintf(fp, "%s ", mainStr);
        if ((rand() % 20) == 10) {
            //write \n into file
            fputc('\n', fp);
        }
    }
    fputc('\n', fp);
    fclose(fp);
}

void PfillFile (char* file) {
    char* myStr;
    int answer;

    FILE *fp;
    fp = fopen(file, "a+");
    if (fp == NULL) {
        cout<<"\nERROR. Could not open output file"<<endl;
        return;
    }

    do{
        cout<<"Enter string to put into a file:"<<endl;
        fflush(stdin);
        myStr = inputString(stdin, 10);
        fprintf(fp, "%s\n", myStr);
        fflush(stdin);
        answer = takeAnswer();
        free(myStr);
    } while(answer);
    
    fclose(fp);
}

char* PaskSub () {
    char* sub;
    cout<<"\nEnter substring you want to search in the text:"<<endl;
    fflush(stdin);
    sub = inputString(stdin, 5);
    return sub;
}

void PprintFile(char* file) {
    FILE* fp;
    char ch;
    fp = fopen(file, "r");
    if (NULL == fp) {
        cout<<"\nERROR. Could not open output file"<<endl;
        return;
    }
    cout<<'\n'<<endl;
    fflush(stdin);
    ch = fgetc(fp);
    while(ch != EOF){
        printf("%c", ch);
        ch = fgetc(fp);
    }
    fclose(fp);
}








char* substring(char* string, int position, int length) {
    char *pointer; 
    int c;

    pointer = (char*)malloc(length+1);
    if (pointer == NULL) {
        exit(EXIT_FAILURE);
    }
    for (c = 0; c < length; c++) {
        *(pointer+c) = *((string+position-1)+c);
    }
    *(pointer+c) = '\0';

    return pointer;
}

void insertSubstring (char* a, char* b, int position, int num) {
    char *f, *e;
    int lengthA;
    int lengthB;
    
    lengthA = strlen(a);
    lengthB = strlen(b);

    f = substring(a, 1, position);
    e = substring(a, position+lengthB-num, lengthA-position);

    strcpy(a, "");
    strcat(a, f);
    strcat(a, b);
    strcat(a, e);
}

char* PfindSub (char* string, char* sub) {
    int l, i, j;
    int counter = 0;

    size_t sLength = strlen(sub); 
    int s = 0;
    for (l = 0; sub[l] != '\0'; l++);
    for (i =  0, j = 0; string[i] != '\0'; i++) {
        if(string[i] == sub[j]) {
            j++; 
            if (j == l) {
                counter++;
                char subReady[sLength+4];
                sprintf(subReady, "[%s-%d]", sub, counter);
                int pos = i - j + 1;
                insertSubstring(string, subReady, pos, 3);
            }
        } else {
            j = 0;
        }
    }
    return string;
}

int PfindSubstring (char* sub, char* file, char* fileOut) {
    int subl = strlen(sub);
    char* fString;

    FILE* myFile;
    myFile = fopen(file, "r");
    if (NULL == myFile) {
        cout<<"\nERROR. Could not open output file"<<endl;
        return 0;
    }

    FILE* outputFile;
    outputFile = fopen(fileOut, "w");
    if (NULL == outputFile) {
        cout<<"\nERROR. Could not open output file"<<endl;
        return 0;
    }

    fflush(stdin);
    while(!feof(myFile)) {
        fString = inputString(myFile, 20);
        fprintf(outputFile, "%s\n", PfindSub(fString, sub));
    }

    fclose(myFile);
    fclose(outputFile);
    return 0;
}







char* PfindSubOut (char* string, char* sub) {
    int l, i, j;
    int counter = 0;
    char newSub[strlen(sub)+2];
    sprintf(newSub, "[%s-", sub);

    size_t sLength = strlen(newSub); 
    int s = 0;
    for (l = 0; newSub[l] != '\0'; l++);
    for (i =  0, j = 0; string[i] != '\0'; i++) {
        if(string[i] == newSub[j]) {
            j++; 
            if (j == l) {
                counter++;
                char subReady[sLength+3];
                sprintf(subReady, "[%d-%s]", counter, sub);
                int pos = i - j + 1;
                insertSubstring(string, subReady, pos, -1);
            }
        } else {
            j = 0;
        }
    }
    return string;
}


void PswapSubstring (char* sub, char* firstName) {
    char secondName[] = "sup.txt";
    char* fString;

    FILE* myFile;
    myFile = fopen(firstName, "r");
    if (NULL == myFile) {
        cout<<"\nERROR. Could not open output file"<<endl;
        return;
    }

    FILE* outputFile;
    outputFile = fopen(secondName, "w");
    if (NULL == outputFile) {
        cout<<"\nERROR. Could not open output file"<<endl;
        return;
    }

    while(!feof(myFile)) {
        fString = inputString(myFile, 20);
        fprintf(outputFile, "%s\n", PfindSubOut(fString, sub));
    }

    remove(firstName);
    rename(secondName, firstName);

    fclose(myFile);
    fclose(outputFile);
}