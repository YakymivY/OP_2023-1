#include "lib.h"

using namespace std;

//methoed that calculates square for paralelepiped 
float TParalelepiped::calcSquare () {
    square = 2*(x*y + x*z + y*z);
    return square;
}

//method that calculates volume for paralelepiped
float TParalelepiped::calcVolume () {
    volume = x*y*z;
    return volume;
}

// method that calculates square for ball
float TBall::calcSquare () {
    square = 4*M_PI*x*x;
    return square;
}

//method that calculates volume for ball
float TBall::calcVolume () {
    volume = 4/3*M_PI*x*x*x;
    return volume;
}

//additional function to ask int number from user with validation
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
                cout<<"The value must be greater or equal than "<<min<<endl;
                error = 1;
            } else if (ans > max) {
                cout<<"The value must be smaller or equal than "<<max<<endl;
                error = 1;
            } else {
                error = 0;
            }    
        }
    } while(error);
    return ans;
}

//function to ask user for number of shapes to create
int takeAmount() {
    cout<<"Enter number of shapes you want to create (1 to 10):"<<endl;
    int amount = askNumber(1, 10);
    return amount;
}

//function to ask user for number of paralelepipeds to create
int takeParalelepipeds(int n) {
    cout<<"Enter number of paralelepipeds you want to create (0 to "<<n<<"):"<<endl;
    int amount = askNumber(0, n);
    return amount;
}

//function to set attributes for array of paralelepipeds
void createParalelepipeds (TParalelepiped array[], int n) {
    float x1, y1, z1;
    for (int i = 0; i < n; i++) {
        cout<<"\nEnter length, width and height of paralelepiped "<<i+1<<" in the next format - L W H"<<endl;
        fflush(stdin); //clearing stdin buffer
        cin>>x1>>y1>>z1;
        array[i].set(x1, y1, z1);
        cout<<"square = "<<array[i].calcSquare()<<endl;
    }
}

//function to set radius for array of balls
void createBalls (TBall array[], int n) {
    float x1;
    for (int i = 0; i < n; i++) {
        cout<<"\nEnter radius of ball "<<i+1<<endl;
        fflush(stdin); //clearing stdin buffer
        cin>>x1;
        array[i].setX(x1);
        cout<<"volume = "<<array[i].calcVolume()<<endl;
    }
}

//function to find overall sqaure of paralelepipeds
void findSquare(TParalelepiped array[], int n) {
    float result = 0;
    for (int i = 0; i < n; i++) {
        result += array[i].getSquare();
    }
    cout<<"\nSum of squares of paralelepipeds is "<<result<<endl;
}

//function to find overall volume of balls
void findVolume(TBall array[], int n) {
    float result = 0;
    for (int i = 0; i < n; i++) {
        result += array[i].getVolume();
    }
    cout<<"Sum of volumes of balls is "<<result<<endl;
}