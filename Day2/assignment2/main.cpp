#include <iostream>

using namespace std;

    class complexClass{
        int real;
        int com;
    public:
       int getR();
       int getC();
       void setR(int);
       void setC(int);
       void display();

       complexClass(){
            cout<<"i am default constractor \n";
       }
       complexClass(int x){
            cout<<" i am overloading constractor \n";
       }
       ~complexClass(){
            cout<<" i am dest \n";
       }
    };

int main()
{
    complexClass s(5) ;
    complexClass s1;



    return 0;
}
