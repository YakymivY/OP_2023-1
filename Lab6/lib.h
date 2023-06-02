#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <math.h>

#define TS 20 //defined tablesize

using namespace std;

int hashh(int, int);

//node class
template <typename T> 
struct Node {
    T data;
    int key;
    Node *next;

    //node constructor
    Node(const T &d, const int &k): data(d), key(k), next(nullptr) {} 
};

//iterator class
template <typename T> 
class Iterator {
    Node<T>* node;
public: 
    //basic constructor
    Iterator(): node(nullptr) {}
    //copy constructor
    Iterator(Node<T>* nod): node(nod) {}
    //method that increments iterator in hashtable
    Node<T>* next (Node<T>** table) {
        if (node->next == nullptr) {
            int ind = hashh(node->key, TS);
            ind++;
            while (ind < TS && table[ind] == nullptr) {
               ind++; 
            }
            if (ind < TS) {
                node = table[ind];
            } else {
                cout<<"Index out of range"<<endl;
                node = nullptr;
            }
        } else {
            node = node->next;
        }
        if (node == nullptr) {
            cout<<"There are no more elements"<<endl;
        }
        return node;
    }
    Iterator operator=(const Iterator& it) {
        node = it.node;
        return *this;
    }
    //setter for node
    void setNode (Node<T>* nod) {
        node = nod;
    }
    //getter for node
    Node<T>* getNode() {
        return node;
    }
};

//hashtable class
template <typename T, int ts>
class HashTable {
    Node<T>* table[ts];
    size_t counter; //counter for number of elements in hashtable
    int max_key; // value of max key
public: 
    //default constructor
    HashTable(): counter(0), max_key(0) {
        for (int i = 0; i < ts; i++) {
            table[i] = nullptr;
        }
    }

    // multiply hash function
    int hashFunction(int key) {
        const double A = 0.6180339887; //special constant
        double product = static_cast<double>(key) * A;
        product -= static_cast<int>(product);
        return static_cast<int>(product * ts);
    }

    //method installing iterator to begin of hashtable
    Iterator<T> begin () {
        int ind = 0;
        while (table[ind] == nullptr) { //when first element found
            ind++;
        }
        Iterator<T> it(table[ind]);
        return it;
    }

    //method to insert value into hashtable
    void insert(const int &key, const T value) {
        int index = hashFunction(key);
        Node<T>* newNode = new Node<T>(value, key);
        if (key > max_key) max_key = key; //updating max key value
        if (table[index] == nullptr) { //if line is clear
            table[index] = newNode;
        } else {
            Node<T>* curr = table[index];
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
        counter++; //+1 element in a table
    }

    //method to remove element from hashtable
    void remove(const int& key) {
        int index = hashFunction(key);
        Node<T>* curr = table[index];
        Node<T>* prev = nullptr;
        while (curr != nullptr) { 
            if (curr->key == key) {
                if (prev == nullptr) {
                    table[index] = curr->next;
                } else {
                    prev->next = curr->next;
                }
                delete curr;
                counter--;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    //method to get value of certai key
    T get(const int& key) {
        int index = hashFunction(key); //find index in the table
        Node<T>* curr = table[index];
        while (curr != nullptr) { //search in linked list
            if (curr->key == key) {
                return curr->data;
            }
            curr = curr->next;
        }
        cout<<"There is no value with that key in the table"<<endl;//throwing error
        return curr->data;
    }

    //table getter from class
    Node<T>** getTable() {
        return table;
    }

    //method to output the table
    void printTable() {
        cout<<"\n----------CONTENT OF HASHTABLE----------"<<endl;
        for (int i = 0; i < ts; i++) {
            if (table[i] == nullptr) {
                cout<<i+1<<". -"<<endl;
            } else {
                cout<<i+1<<". ";
                Node<T>* curr = table[i];
                while (curr != nullptr) {
                    cout<<curr->data<<" ";
                    curr = curr->next;
                }
                cout<<endl;
            }
        }
    }

    //size getter
    int getSize() {
        return counter;
    }

    //max key getter
    int getMax() {
        return max_key;
    }
    //method to delete all elements from a table
    void clear() {
        for (int i = 0; i < ts; i++) {
            table[i] = nullptr;
        }
        counter = 0;
        max_key = 0;
    }
};

//function to get data from file and insert it into hashtable
template <typename T, int ts>
HashTable<T, ts> readFile () {
    ifstream file("list.txt");
    
    string str;
    int key;
    HashTable<string, TS> h;

    while (!file.eof()) {
        file>>key; file>>str;
        h.insert(key, str);
    }
    file.close();
    return h;
}