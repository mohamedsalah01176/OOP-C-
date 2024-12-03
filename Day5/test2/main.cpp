#include <iostream>
#include <graphics.h>

using namespace std;

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

class Circle {
    Point center;
    int rad;

public:
    Circle() {
        rad = 0;
    }

    Circle(int x, int y, int r) : center(x, y) {
        rad = r;
    }

    Circle(Point p, int r) : center(p) {
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
        cout << "Drawing cricle at point ("<<center.getx() <<","<<center.gety() <<") with raduis is "<< rad<<endl;
        circle(center.getx(), center.gety(), rad);
        }
};

class Line {
    Point startp, endp;

public:
    Line() {}

    Line(int x1, int y1, int x2, int y2) : startp(x1, y1), endp(x2, y2) {}

    Line(Point p1, Point p2) : startp(p1), endp(p2) {}

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
             << endp.getx() << ", " << endp.gety() << ")" << endl;
    }
};

class Rect {
    Point topLeft, bottomRight;

public:
    Rect() {}

    Rect(int x1, int y1, int x2, int y2) : topLeft(x1, y1), bottomRight(x2, y2) {}

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
             << ") and bottom-right (" << bottomRight.getx() << ", " << bottomRight.gety() << ")" << endl;
    }
};

class Picture
{
    Circle *c;
    Line *l;
    Rect *r;
    int cs,ls,rs;
public:
    Picture()
    {
        cs = ls = rs = 0;
        c = NULL;
        l = NULL;
        r = NULL;
    }

    Picture(Circle *pc,Line *pl, Rect *pr, int cn,int ln,int rn)
    {
       c = pc;
       l = pl;
       r = pr;
       cs = cn;
       ls = ln;
       rs = rn;
    }
    void setCircles(Circle *pc, int cn) {
        c = pc;
        cs = cn;
    }

    void setLines(Line *pl, int ln) {
        l = pl;
        ls = ln;
    }

    void setRectangles(Rect *pr, int rn) {
        r = pr;
        rs = rn;
    }

     Circle* getCircles() {
        return c;
    }

    int getCircleCount() {
        return cs;
    }

    Line* getLines() {
        return l;
    }

    int getLineCount() {
        return ls;
    }

    Rect* getRectangles() {
        return r;
    }

    int getRectangleCount() {
        return rs;
    }

    void draw() {
        cout << "Drawing Picture with:" << endl;

        for (int i = 0; i < cs; ++i) {
            cout << "  Circle " << i + 1 << ": ";
            c[i].draw();
        }

        for (int i = 0; i < ls; ++i) {
            cout << "  Line " << i + 1 << ": ";
            l[i].draw();
        }

        for (int i = 0; i < rs; ++i) {
            cout << "  Rectangle " << i + 1 << ": ";
            r[i].draw();
        }
    }

    ~Picture() {
        delete[] c;
        delete[] l;
        delete[] r;
    }

};
int main() {
   initgraph();
    setcolor(9);

//    Line l1 (500,250,150,600);
//    l1.draw();

    Circle c1(500,300,100);
    c1.draw();

    Line l2 (500,150,300,250);
    l2.draw();


    Rect r1 (300,400,700,500);
    r1.draw();



    return 0;
}
