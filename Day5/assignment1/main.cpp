#include <iostream>
#include <graphics.h>


using namespace std;


class Point{
protected:
    int x;
    int y;
    string color;
public:
    Point():x(0),y(0),color("red"){};
    Point(int n1,int n2):x(n1),y(n2){
    }
    ~Point(){}
    void draw(){
        cout<<"test";
    };
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
};

class Rect:public Point{
protected:
    Point ul,dr;
public:
    Rect(){};
    Rect(int n1,int n2, int n3, int n4,string c):ul(n1,n2),dr(n3,n4){
        color=c;
    };
    void draw(){
        cout << "Drawing Rectangle with top-left (" << ul.getX() << ", " << ul.getY()
             << ") and bottom-right (" << dr.getX() << ", " << ul.getY() << ") color is "<<color<<endl;
    }
};

class Line:public Point{
    Point P1,P2;
public:
    Line();
    Line(int n1,int n2, int n3, int n4,string c):P1(n1,n2),P2(n3,n4){
        color=c;
    };
     void draw() {
        cout << "Drawing Line from (" << P1.getX() << ", " << P1.getY() << ") to ("
             << P2.getX() << ", " << P2.getY() << ")" << "color is "<< color<<endl;
    }
};

class Cricl:public Point{
    Point center;

public:
    Cricl(){};
    Cricl(int n1,int n2,string c):center(n1,n2){
        color=c;
    };
    void draw() {
        cout << "Drawing circle at point ("<<center.getX() << ","<<center.getY()<<")"<<"color is "<< color<<endl;
    }
};


class Picture{

    int numC;
    int numR;
    int numL;
    Line *lines;
    Cricl *cricles;
    Rect *rects;

public:
    Picture(){
        numC=0;
        numR=0;
        numL=0;
        lines=NULL;
        cricles=NULL;
        rects=NULL;
    }
    Picture(Line *ln,int nL,Cricl *cr,int nC,Rect *rc,int nR){
        lines=ln;
        numL=nL;
        cricles=cr;
        numC=nC;
        rects=rc;
        numR=nR;
    }

    void setLine(Line *ln ,int nL){
        lines=ln;
        numL=nL;
    }
    void setCricl(Cricl *cr ,int nC){
        cricles=cr;
        numC=nC;
    }
    void setRect(Rect *rc,int nR){
        rects=rc;
        numR=nR;
    }
    void paint(){
        for(int i=0;i<numL;i++){
            lines[i].draw();
        }
        for(int i=0;i<numC;i++){
            cricles[i].draw();
        }
        for(int i=0;i<numR;i++){
            rects[i].draw();
        }
    }
};

int main()
{

    Line lines[2]={ Line(4,6,8,3,"blue"), Line(40,9,80,30,"blue")};
    Rect rects[2]={ Rect(4,6,8,3,"blue"), Rect(40,9,80,30,"green")};
    Cricl cricles[1]={ Cricl(2,8,"blue")};

    Picture pc(lines,2,cricles,1,rects,2);
    pc.paint();
    lines[0].draw();

}
