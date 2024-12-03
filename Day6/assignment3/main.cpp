#include <iostream>
#include <graphics.h>

using namespace std;
class Shape{
protected:
    string color;
public:
    Shape(){
            color="red";
    }
    Shape(string c){
        color=c;
    }
    string getColor(){
        return color;
    }
    void setColor(string c){
        color=c;
    }
    virtual void draw() = 0;
};
class Point {
    int x, y;

public:
    Point() {
        x = 0;
        y = 0;
    }

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    Point(const Point& p) {
        this->x = p.x;
        this->y = p.y;
    }

    void setx(int x) {
        this->x = x;
    }

    void sety(int y) {
        this->y = y;
    }

    int getx() {
        return x;
    }

    int gety() {
        return y;
    }
};

class Circle:public Shape {
    Point center;
    int rad;

public:
    Circle() {
        rad = 0;
        color="red";
    }

    Circle(int x, int y, int r,string c) : center(x, y),Shape(c) {
        rad = r;
    }

    Circle(Point p, int r,string c) : center(p),Shape(c) {
        rad = r;
    }

    void setx(int x) {
        center.setx(x);
    }

    void sety(int y) {
        center.sety(y);
    }

    void setp(Point p) {
        center = p;
    }

    int getx() {
        return center.getx();
    }

    int gety() {
        return center.gety();
    }

    Point getp() {
        return center;
    }

    void draw() {
        cout << "Drawing circle at point ("<<center.getx() << ","<<center.gety()<<")"<<"color is "<< color<<endl;
        circle(center.getx(), center.gety(), rad);
        }
};

class Line:public Shape  {
    Point startp, endp;

public:
    Line() {}

    Line(int x1, int y1, int x2, int y2,string c) : startp(x1, y1), endp(x2, y2),Shape(c) {}

    Line(Point p1, Point p2,string c) : startp(p1), endp(p2),Shape(c) {}

    void setStart(Point p) {
        startp = p;
    }

    void setEnd(Point p) {
        endp = p;
    }

    Point getStart() {
        return startp;
    }

    Point getEnd() {
        return endp;
    }

    void draw() {
        cout << "Drawing Line from (" << startp.getx() << ", " << startp.gety() << ") to ("
             << endp.getx() << ", " << endp.gety() << ")" << "color is "<< color<<endl;
    }
};

class Rect: public Shape {
    Point topLeft, bottomRight;

public:
    Rect() {}

    Rect(int x1, int y1, int x2, int y2,string c) : topLeft(x1, y1), bottomRight(x2, y2),Shape(c) {}

    Rect(Point tl, Point br) : topLeft(tl), bottomRight(br) {}

    void setTopLeft(Point p) {
        topLeft = p;
    }

    void setBottomRight(Point p) {
        bottomRight = p;
    }

    Point getTopLeft() {
        return topLeft;
    }

    Point getBottomRight() {
        return bottomRight;
    }

    void draw() {
        cout << "Drawing Rectangle with top-left (" << topLeft.getx() << ", " << topLeft.gety()
             << ") and bottom-right (" << bottomRight.getx() << ", " << bottomRight.gety() << ") color is "<<color << endl;
    }
};

class Picture
{
    /*Circle *c;
    Line *l;
    Rect *r;
    int cs,ls,rs;*/

    Shape** shapes;
    int shapeCount;
public:

    Picture(Shape ** s,int count):shapes(s),shapeCount(count){};
    void draw() {
        for (int i = 0; i < shapeCount; ++i) {

            shapes[i]->draw();
        }
    }

};
int main() {
    //new => operator is used to allocate memory dynamically on the heap
  Shape* shapes[] = {
        new Circle(200, 200, 50, "blue"),
        new Rect(300, 300, 70,50, "green"),
        new Line(400, 400, 100,300, "red")
    };

    Picture pic(shapes, 3);

    pic.draw();
return 0;

}
