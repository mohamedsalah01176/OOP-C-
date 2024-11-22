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
    };

complexClass sum(complexClass,complexClass );
complexClass sub(complexClass,complexClass );

int main()
{
    complexClass S1,S2,res,resSub;
    S1.setR(7);
    S1.setC(8);
    S2.setR(10);
    S2.setC(18);
   S1.display();


   res=sum(S1,S2);
    res.display();


    resSub=sub(S1,S2);
    resSub.display();

    return 0;
}


int complexClass:: getR(){
    return real;
}
int complexClass:: getC(){
    return com;
}

void complexClass:: setR(int r){
    real=r;
}

void complexClass:: setC(int C){
    com=C;
}
void complexClass:: display(){
    if(com>=0){
        cout << getR() << "+" << getC() <<"i"<<endl;
    }else{
        cout << getR() << getC() <<"i"<<endl;
    }
}

complexClass sum(complexClass c1 ,complexClass c2){
    complexClass result;
    result.setR(c1.getR() + c2.getR() );
    result.setC(c1.getC() + c2.getC());
    return result;
}
complexClass sub(complexClass c1 ,complexClass c2){
    complexClass result;
    result.setR(c1.getR() - c2.getR() );
    result.setC(c1.getC() - c2.getC());
    return result;
}


