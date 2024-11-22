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
       complexClass sum(complexClass,complexClass);
       complexClass sum(complexClass,complexClass,complexClass );
       complexClass sum(complexClass,int);
       complexClass sum(int,complexClass);


int main()
{
    complexClass s1,s2,s3, res;
    s1.setR(5);
    s1.setC(0);
    s2.setR(15);
    s2.setC(0);
    s3.setR(5);
    s3.setC(4);

    cout <<" complex +complex =   ";
    res=sum(s1,s2);
    res.display();

    cout <<" complex +int =   " ;
    res=sum(s1,5);
    res.display();

    cout <<" int +complex =   ";
    res=sum(1,s2);
    res.display();

     cout <<" complex + complex +complex =   ";
    res=sum(s1,s2,s3);
    res.display();


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
    if(com>0){
        cout << getR() << "+" << getC() <<"i"<<endl;
    }else if(com <0){
        cout << getR() << getC() <<"i"<<endl;
    }else{
        cout << getR() ;
    }
}

complexClass sum(complexClass c1,complexClass c2){
    complexClass result;
    result.setR(c1.getR() + c2.getR() );
    result.setC(c1.getC() + c2.getC());
    return result;
}
complexClass sum(complexClass c1,int c2){
    complexClass result;
    result.setR(c1.getR() + c2 );
    result.setC(c1.getC());
    return result;
}
complexClass sum(int c1,complexClass c2){
    complexClass result;
    result.setR(c2.getR()+c1 );
    result.setC(c2.getC());
    return result;
}
complexClass sum(complexClass c1,complexClass c2,complexClass c3){
    complexClass result;
    result.setR(c1.getR() + c2.getR()  +c3.getR());
    result.setC(c1.getC() + c2.getC()+c3.getC());
    return result;
}

/*complexClass sumClass::sum(complexClass c1,complexClass c2){
    complexClass res;
    res.setR(c1.getR(),c2.getR());
}*/
