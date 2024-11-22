#include <iostream>

using namespace std;

class Stack{
    int size1,*pt;
    //int arr[size1];
    int top=0;
public:
    int getTop(){
        return top;
    }
    int getSize(){
        return size1;
    }
    void push(int n){
        if(top == 10){
            cout<<"the stack is full";
        }else{
            pt[top]=n;
            top++;
        }
    }
    int pop(){
        int retur=0;
        if(top==0){
            cout << "the stack is empty";
        }else{
            top--;
            retur=pt[top];
        }
        return retur;
    }
    void intotop(){
        top=0;
    }
    Stack(){
        top=0;
        size1=10;
        pt=new int[size1];
    }
    Stack(int x){
        size1=x;
        pt=new int[size1];
    }

    ~Stack(){
        delete pt;
    }

   /* void viewSatck( Stack S) {
        int n =S.getTop();
        cout << "Stack contents: ";
        for (int i = 0; i < n; i++) {
            cout << S.pop() << " ";
        }
    }*/
};

void viewSatck(Stack);

int main()
{
     Stack myS(5);
    myS.push(5);
    myS.push(10);
    myS.push(0);
    myS.push(3);
    myS.viewSatck(myS);

    return 0;
}
void viewSatck( Stack S) {
        int n =S.getTop();
        cout << "Stack contents: ";
        for (int i = 0; i < n; i++) {
            cout << S.pop() << " ";
        }
    }

