#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <math.h>

using namespace std;

class TBody {
    protected:
        float x, y, z;
        float square, volume;
    public: 
        TBody (): x(0), y(0), z(0) {}
        TBody (float x1, float y1 = 0, float z1 = 0) {x = x1; y = y1; z = z1;}
        void set (float x1, float y1 = 0, float z1 = 0) {x = x1; y = y1; z = z1;}
        void setX (float x1) {x=x1;}
        float getX () {return x;}
        float getY () {return y;}
        float getZ () {return z;}
        virtual float calcSquare () = 0;
        virtual float calcVolume () = 0;
};

class TParalelepiped:public TBody{
    public: 
    TParalelepiped (): TBody() {}
    TParalelepiped (float x1, float y1, float z1): TBody(x1, y1, z1) {}
    float calcSquare ();
    float calcVolume ();
    float getSquare() {return square;}
};

class TBall:public TBody{
    public: 
    TBall (): TBody() {}
    TBall (float x1): TBody(x1) {}
    float calcSquare ();
    float calcVolume ();
    float getVolume() {return volume;}
};

int askNumber(int, int);
int takeAmount();
int takeParalelepipeds(int);
void createParalelepipeds(TParalelepiped[], int);
void createBalls(TBall[], int);
void findSquare(TParalelepiped[], int);
void findVolume(TBall[], int);