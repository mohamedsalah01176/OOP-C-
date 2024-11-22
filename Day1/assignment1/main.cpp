#include <iostream>

using namespace std;

    struct complexStruct{
        int real;
        int com;
       int getR();
       int getC();
       void setR(int);
       void setC(int);
       void display();
    };

complexStruct sum(complexStruct,complexStruct );
complexStruct sub(complexStruct,complexStruct );

int main()
{
    complexStruct S1,S2,res,resSub;
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


int complexStruct:: getR(){
    return real;
}
int complexStruct:: getC(){
    return com;
}

void complexStruct:: setR(int r){
    real=r;
}

void complexStruct:: setC(int C){
    com=C;
}
void complexStruct:: display(){
    if(com>=0){
        cout << real << "+" << com <<"i"<<endl;
    }else{
        cout << real << com <<"i"<<endl;
    }
}

complexStruct sum(complexStruct c1 ,complexStruct c2){
    complexStruct result;
    result.setR(c1.getR() + c2.getR() );
    result.setC(c1.getC() + c2.getC());
    return result;
}
complexStruct sub(complexStruct c1 ,complexStruct c2){
    complexStruct result;
    result.setR(c1.getR() - c2.getR() );
    result.setC(c1.getC() - c2.getC());
    return result;
}


