#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdio>

#include "text_files.h"

using namespace std;

int main (int argc, char *argv[]) {
    if (argc != 3 || strcmp(argv[1], "-mode")){
        cout<<"WRONG ARGUMENTS"<<endl;
    } else if (!strcmp(argv[2], "FileStream")){
        cout<<"---YOU ENTERED STREAM MODE---"<<endl;
        string fileToOpen = inputFilename();
        string fileIn = formInput(fileToOpen);
        string fileOut = formOutput(fileToOpen);
        if (!askType()) {
            int quantity = askNumber();
            randomStrings(quantity, fileIn);
        } else {
            fillFile(&takeAnswer, fileIn);
        }

        cout<<"\n\n-------INPUT FILE-------"<<endl;
        printFile(fileIn);
        string sub = askSub();
        findSubstring(sub, fileIn, fileOut);
        cout<<"\n\n-------OUTPUT FILE-------"<<endl;
        printFile(fileOut);
        swapSubstring(sub, fileOut);
        cout<<"-------OUTPUT FILE CHANGED-------"<<endl;
        printFile(fileOut);
    } else if (!strcmp(argv[2], "FilePointer")) {
        cout<<"---YOU ENTERED POINTER MODE---"<<endl;

        char* PfileToOpen = PinputFilename();
        char* add = new char[strlen(PfileToOpen) + 5];
        strcpy(add, PfileToOpen);
        
        char* PfileIn = PformIn(add);
        char* PfileOut = PformOut(PfileToOpen);
        delete[] add;

        if (!askType()) {
            int Pquantity = askNumber();
            PrandomStrings(Pquantity, PfileIn);
        } else {
            PfillFile(PfileIn); 
        }

        cout<<"\n\n-------INPUT FILE-------"<<endl;
        PprintFile(PfileIn);
        char* Psub = PaskSub();
        PfindSubstring(Psub, PfileIn, PfileOut);
        cout<<"\n\n-------OUTPUT FILE-------"<<endl;
        printFile(PfileOut);
        PswapSubstring(Psub, PfileOut);
        cout<<"-------OUTPUT FILE CHANGED-------"<<endl;
        printFile(PfileOut);
    }
    

    return 0;
}