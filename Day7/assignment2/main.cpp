#include <iostream>

using namespace std;


class geoshap{
protected:
    float A,B;
public:
    geoshap(){
        A=B=0;
    }
    geoshap(float n){
        A=B=n;
    }
    geoshap(float n,float m){
        A=n;
        B=m;
    }
    void setA(float n){
        A=n;
    }
    void setB(float m){
        B=m;
    }

    float getA(){
        return A;
    }
    float getB(){
        return B;
    }
   virtual float calcArea()=0;

};

class Rect:public geoshap{
public:
    Rect(){};
    Rect(float x,float y):geoshap(x,y){};
    float calcArea(){
       return A*B;
    }
};

class triangle :public geoshap{
public:
    triangle (){};
    triangle (float x,float y):geoshap(x,y){};
    float calcArea(){
        return .5*A*B;
    }
};

class Cricle:public geoshap{
public:
    Cricle(){};
    Cricle(float r):geoshap(r){};
    float calcArea(){
        return 3.17*A*B;
    }
    void setR(float r){
        A=B=r;
    }
    float getR(){
        return A;
    }
};

class Square:public Rect{
public:
    Square();
    Square(float x):Rect(x,x){};
    float calcArea(){
        return A*B;
    }
};

int main()
{
    geoshap *p;
    Rect R(3,2);
    Cricle C(3);
    triangle T(9,6);
    Square S(3);
    p=&R;
    cout << p->calcArea()<<endl;
    p=&C;
    cout << p->calcArea()<<endl;
    p=&T;
    cout << p->calcArea()<<endl;
    p=&S;
    cout << p->calcArea()<<endl;

    return 0;
}
