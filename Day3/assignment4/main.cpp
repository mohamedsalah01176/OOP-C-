#include <iostream>

using namespace std;
class Stack{
    int size1,*pt,counter=0;
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

    Stack(){
        top=0;
        size1=10;
        pt=new int[size1];
        counter++;
    }
    Stack(int x){
        size1=x;
        pt=new int[size1];
        counter++;
    }

    ~Stack(){
        delete pt;
        counter--;
    }
    Stack(Stack&);
};
void viewSatck(Stack );


int main()
{
    Stack myS(5);
    myS.push(5);
    myS.push(10);
    myS.push(0);
    myS.push(3);
    viewSatck(myS);
    cout <<myS.pop();


    return 0;
}

Stack::Stack(Stack &S){
    this->top=S.top;
    this->size1=S.size1;
    this->pt=new int[this->size1];
    for (int i = 0; i <= this->top; i++) {
        this->pt[i]=S.pt[i];
    }
        counter++;

}




void viewSatck( Stack S) {
    int n=S.getTop();
    cout << "Stack contents: ";
    for (int i = 0; i < n; i++) {
        cout << S.pop() << " ";
    }
}
