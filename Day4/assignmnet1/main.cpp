#include <iostream>

using namespace std;

    class complexClass{
        int real;
        int img;
    public:
       int getR();
       int getI();
       void setR(int);
       void setI(int);
       void display();


       /*complexClass(){
            cout<<"i am default constractor \n";
       }
       complexClass(int x){
            cout<<" i am overloading constractor \n";
       }
       ~complexClass(){
            cout<<" i am dest \n";
       }
       */


       //operator com + int
        complexClass operator+(float);

       //operator int + com
       friend complexClass operator+(int,complexClass);

       //operator +
       complexClass operator+(complexClass);

       //operator -
       complexClass operator-(complexClass);

       //operator /
       complexClass operator/(complexClass);

       //operator *
       complexClass operator*(complexClass);

       //operator +=
       complexClass operator+=(complexClass);

       //operator -=
       complexClass operator-=(complexClass);

       //operator *=
       complexClass operator*=(complexClass);

       /*//operator /=
       complexClass operator/=(complexClass);*/


        //operator ==
       bool operator==(complexClass);

       //operator !=
       bool operator!=(complexClass);

       //operator >
       bool operator>(complexClass);

       //operator <
       bool operator<(complexClass);

       //operator &&
       bool operator&&(complexClass);

       //operator ||
       bool operator||(complexClass);
    };

int main()
{
    complexClass res,C1,C2;

    //++++
    C1.setR(10);
    C1.setI(20);
    C2.setR(8);
    C2.setI(3);
    res=C1+C2;
    res.display();

    cout<<"\n====================\n";

    //---
    res=C1-C2;
    res.display();

    cout<<"\n====================\n";

    /////
    res=C1/C2;
    res.display();

    cout<<"\n====================\n";

    //****
    res=C1*C2;
    res.display();

    cout<<"\n====================\n";

    //+=
    C1+=C2;
    C1.display();

    cout<<"\n====================\n";

    //-=
    C1-=C2;
    C2.display();

    cout<<"\n====================\n";

    //*=
    C1*=C2;
    C2.display();

    cout<<"\n====================\n";

   /* //*=
    C1/=C2;
    C2.display();*/

    cout<<"\n====================\n";

    if(C1==C2){
        cout<<"the same\n";
    }else{
        cout<<"not the same\n";
    }


    cout<<"\n====================\n";

    if(C1!=C2){
        cout<<"they are not equal\n";
    }else{
        cout<<"they are equal\n";
    }


    cout<<"\n====================\n";

    if(C1>C2){
        cout<<"C1 greater than C2\n";
    }else{
        cout<<"C2 greater than C1\n";
    }

    cout<<"\n====================\n";

    if(C1<C2){
        cout<<"C2 greater than C1\n";
    }else{
        cout<<"C1 greater than C2\n";
    }

    cout<<"\n====================\n";

    if(C1&&C2){
        cout<<"both have value in real and imag\n";
    }else{
        cout<<"both  have not value in real and imag\n";
    }

    cout<<"\n====================\n";

    if(C1||C2){
        cout<<"at least one have value in real and imag\n";
    }else{
        cout<<"both  have not value in real and imag";
    }

    cout<<"\n====================\n";

    res=C1+2;
    res.display();

    cout<<"\n====================\n";
    res=2+C2;
    res.display();

    return 0;
}



int complexClass:: getR(){
    return real;
}
int complexClass:: getI(){
    return img;
}

void complexClass:: setR(int r){
    real=r;
}

void complexClass:: setI(int C){
    img=C;
}

void complexClass:: display(){
    if(img>0){
        cout << getR() << "+" << getI() <<"i"<<endl;
    }else if(img<0){
        cout << getR() << getI() <<"i"<<endl;
    }else{
        cout << getR()<<endl;
    }
}

complexClass complexClass::operator+(float x){
    complexClass res;
    res.real=real+x;
    res.img=img;
    return res;
}
 complexClass operator+(int x,complexClass C ){
    complexClass res;
    res.real=C.real+x;
    res.img=C.img;
    return res;
}
complexClass complexClass::operator+(complexClass C){
    complexClass res;
    res.real=real+C.real;
    res.img=img+C.img;
    return res;
}

complexClass complexClass::operator-(complexClass C){
    complexClass res;
    res.real=real-C.real;
    res.img=img-C.img;
    return res;
}
complexClass complexClass::operator*(complexClass C){
        complexClass res;
        double denominator = C.real * C.real + C.img * C.img; // c^2 + d^2
        res.real = (real * C.real + img * C.img) / denominator; // (ac + bd) / (c^2 + d^2)
        res.img = (img * C.real - real * C.img) / denominator; // (bc - ad) / (c^2 + d^2)
        return res;
}
complexClass complexClass::operator/(complexClass C){
        complexClass res;
        res.real = (real * C.real) - (img * C.img); // (ac - bd)
        res.img = (real * C.img) + (img * C.real); // (ad + bc)
        return res;
}

complexClass complexClass::operator+=(complexClass C){
        this->real=real+C.real;
        this->img=img+C.img;
        return *this;
}
complexClass complexClass::operator-=(complexClass C){
        complexClass res;
        this->real=real-C.real;
        this->img=img-C.img;
        return res;
}
complexClass complexClass::operator*=(complexClass C){
    int tempReal = (real * C.real) - (img * C.img); // (ac - bd)
    img = (real * C.img) + (img * C.real);         // (ad + bc)
    real = tempReal;
    return *this; // Return reference to the current object
}

/*complexClass complexClass::operator/=(complexClass C){
    int denominator = C.real * C.real + C.img * C.img; // c^2 + d^2
    if (denominator == 0) {
        cout << "Error: Division by zero!" << endl;
        return *this;
    }
}*/


bool complexClass::operator==(complexClass C){
    return (real == C.real && img == C.img);
}

bool complexClass::operator!=(complexClass C){
    return (real != C.real && img != C.img);
}

bool complexClass::operator>(complexClass C){
    return (real > C.real && img > C.img);
}

bool complexClass::operator<(complexClass C){
    return (real < C.real && img < C.img);
}

bool complexClass::operator&&(complexClass C){
    return (real !=0 && img !=0) && (C.real !=0 && C.img !=0);
}

bool complexClass::operator||(complexClass C){
    return (real !=0 || img !=0) || (C.real !=0 || C.img !=0);
}

