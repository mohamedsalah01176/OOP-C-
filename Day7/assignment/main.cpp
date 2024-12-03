

using namespace std;
class Complex{
    int real;
    int img;

public:
    Complex(){
        real=0;
        img=0;
    }
    Complex(int x,int y){
            real=x;
            img=y;
    }
    int getR(){
        return real;
    }
    int getI(){
        return img;
    }
    friend ostream& operator<<(ostream&,Complex&);
    friend istream& operator>>(istream&,Complex&);


};

int main()
{
    Complex c(20,10) ,c2;

    cout<<c<<endl;
    cout<<"please enter real and img"<<endl;
    cin>>c2;
    cout<<c2;

    ofstream outFile("test.txt");
    if (!outFile) {
        cerr << "Error: Could not open file for writing!" << endl;
        return 1;
    }

    outFile << c << endl;

    outFile.close();




    ifstream inFile("test.txt");
    if (!inFile) {
        cerr << "Error: Could not open file for reading!" << endl;
        return 1;
    }

    cout << "\nContent of 'test.txt':" << endl;
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();

    return 0;
}

ostream& operator<<(ostream& myst,Complex& C){

    myst<<"("<<C.real<<"+i"<< C.img<<")";
    return myst;
}

istream& operator>>(istream& myst, Complex& C) {
    myst >> C.real >> C.img;
    return myst;
}





