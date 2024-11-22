#include <iostream>

using namespace std;

class Stack{
    int size1,*pt;
    //int arr[size1];
    int top=0;
public:
    int getSize(){
        return size1;
    }
    void push(int n){
        if(this->top == 10){
            cout<<"the stack is full";
        }else{
            this -> pt[top]=n;
            this -> top++;
        }
    }
    int pop(){
        int retur=0;
        if(this->top==0){
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
    }
    Stack(int x){
        size1=x;
        pt=new int[size1];
    }

    ~Stack(){
        delete pt;
    }
};


int main()
{
    int size1;
    int num,x=1;
    printf("please enter size for stack ");
    scanf("%d",&size1);
    Stack s1(size1);
    for(int i=0;i<size1;i++){
            printf("please enter your number ");
            scanf("%d",&num);
            s1.push(num);
    }
    printf("stack is full");

    cout<<s1.pop();
    //do{}while(x !=0)

    return 0;
}
