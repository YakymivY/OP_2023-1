#include "class.h"

using namespace std;

int main () {
    //getting amount of objects user wants to create
    int amount = takeAmount();
    //dynamically creating array of objects
    Text *array = new Text[amount];
    //filling all objects with content
    createArray(array, amount);
    //adding additional strings to text
    addText(array, amount);
    //finding the text with biggest percent of consonants
    findBiggest(array, amount);

    //free memory
    delete[] array;

    return 0; 
}