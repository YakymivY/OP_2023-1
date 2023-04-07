#include "binary.h"

using namespace std;

int main () {

    string filename = inputFilename();
    cout<<'\n';
    printFile(filename + ".bin");
    cout<<'\n';
    
    addRoute(filename);
    cout<<"YOUR SCHEDULE:"<<endl;
    printFile(filename + ".bin");

    newSchedule(filename);
    cout<<"\nWINTER SCHEDULE:"<<endl;
    printFile(filename + "_winter.bin");

    return 0;
}