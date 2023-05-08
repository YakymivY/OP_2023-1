#include "lib.h"

using namespace std;

int main () {

    // taking number of objects
    int amount = takeAmount();
    int pAmount = takeParalelepipeds(amount);
    int bAmount = amount - pAmount;

    // declaring object array
    TParalelepiped *pArray = new TParalelepiped[pAmount];
    TBall *bArray = new TBall[bAmount];

    // filling arrays with objects and finding their aquares/volumes
    createParalelepipeds(pArray, pAmount);
    createBalls(bArray, bAmount);

    //finding final sum of squares and volumes
    findSquare(pArray, pAmount);
    findVolume(bArray, bAmount);

    //clearing memory
    delete[] pArray;
    delete[] bArray;
 
    return 0;
}