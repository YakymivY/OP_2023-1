#include "lib.h"

using namespace std;

int main () {

    //create hashtable based on file data
    HashTable<string, TS> h = readFile<string, TS>();
    //output
    h.printTable();
    //find size of hashtable
    cout<<"---Number of elements in hashtable: "<<h.getSize()<<endl;
    //find max value of key in the hashtable
    cout<<"---Max key value in the hashtable: "<<h.getMax()<<endl;
    //create iterator pointing to the start of table
    Iterator<string> it(h.begin());
    //print value iterator is pointing to
    cout<<it.getNode()->data<<endl;
    //move iterator to the next value
    cout<<it.next(h.getTable())->data<<endl;
    //clear hashtable
    h.clear();
    h.printTable();
    
    return 0;
}