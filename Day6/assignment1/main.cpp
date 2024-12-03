#include <iostream>
using namespace std;

template <class T>
class Stack {
    int top;
    int size1;
    T* myStack;
public:
    static int counter;
    Stack();
    Stack(int sizee);
    ~Stack();

    void push(T n);
    T pop();
    int getTop() const;
    void viewStack() const;
    Stack& operator=(const Stack& s);
    T& operator[](int i);
};



int main() {
    // Stack<int>
    Stack<int> c1, sCopy;
    c1.push(1);
    c1.push(2);
    c1.push(3);
    c1.push(4);
    sCopy = c1;
    cout << "The content of stack is: ";
    sCopy.viewStack();

    // Stack<char>
    Stack<char> c2, sCopy2;
    c2.push('M');
    c2.push('n');
    c2.push('o');
    c2.push('o');
    cout << "The content of stack is: ";
    sCopy2 = c2;
    sCopy2.viewStack();

    sCopy2[90];

    return 0;
}


template <class T>
int Stack<T>::counter = 0;

template <class T>
Stack<T>::Stack() : size1(4), top(0) {
    myStack = new T[size1];
    counter++;
}

template <class T>
Stack<T>::Stack(int sizee) : size1(sizee), top(0) {
    myStack = new T[size1];
    counter++;
}

template <class T>
Stack<T>::~Stack() {
    delete[] myStack;
    counter--;
}

template <class T>
void Stack<T>::push(T n) {
    if (top == size1) {
        cout << "Stack is full\n";
    } else {
        myStack[top] = n;
        cout<<"push item "<< n<<endl;
        top++;
    }
}

template <class T>
T Stack<T>::pop() {
    if (top > 0) {
        cout << "Popped " << myStack[--top] << endl;
    } else {
        cout << "Stack Underflow" << endl;
    }
}

template <class T>
int Stack<T>::getTop() const {
    return top;
}

template <class T>
void Stack<T>::viewStack() const {
    for (int i = 0; i < top; i++) {
        cout << myStack[i] << " ";
    }
    cout << endl;
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack& s) {
    if (this != &s) {
        delete[] myStack;
        size1 = s.size1;
        top = s.top;
        myStack = new T[size1];
        for (int i = 0; i < top; i++) {
            myStack[i] = s.myStack[i];
        }
    }
    return *this;
}

template <class T>
T& Stack<T>::operator[](int index) {
    if (index < 0 || index >= top) {
        cout<<"Index out of range"<<endl;
    }
    return myStack[index];
}
