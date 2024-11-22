#include <iostream>

using namespace std;

class Stack{
    int arr[10];
    int top=0;
public:
    void push(int n){
        if(this->top == 10){
            cout<<"the stack is full";
        }else{
            this -> arr[top]=n;
            this -> top++;
        }
    }
    int pop(){
        int retur=0;
        if(this->top==0){
            cout << "the stack is empty";
        }else{
            top--;
            retur=arr[top];
        }
        return retur;
    }
    void intotop(){
        top=0;
    }
};

int main()
{
    Stack s1;
    s1.intotop();
    s1.push(5);
    s1.push(6);
    s1.push(7);
    cout<<s1.pop();
    //cout<<s1.pop();
    return 0;
}
