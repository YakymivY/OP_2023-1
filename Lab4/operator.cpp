#include "lib.h"

using namespace std;

int main () {

    srand(time(NULL));

    // object A
    string contentA = inputString("A");
    MultiSet objA("A", contentA);

    //object B
    int numB = inputNumber("B");
    MultiSet objB(numB, "B");

    //object C
    MultiSet objC("C");

    //object D
    MultiSet objD;
    objD = (objA + objB) - objC * objB;
    objD.setName("D");
    objD.print();

    return 0;
}