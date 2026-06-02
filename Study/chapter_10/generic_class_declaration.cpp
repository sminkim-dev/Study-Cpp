#include <iostream>
using namespace std;

// generic class 선언부
template <class T>
class MyStack{
    int tos;
    T data [100]; // T 타입의 배열 스택에 최대 100개의 원소 저장
public:
    MyStack();
    void push(T element); // T 타입 원소 element를 data []에 push
    T pop(); // stack top에 있는 원소를 data[]에서 pop하여 return
};
// generic class 구현부
template <class T>
MyStack<T>::MyStack(){
    tos = -1; // stack is empty
}
template <class T>
void MyStack<T>::push(T element){
    if(tos == 99){
        cout << "stack FULL";
        return;
    }
    tos++;
    data[tos] = element;
}
template <class T> T MyStack<T>::pop(){
    T retData;
    if(tos == -1){
        cout << "stack empty";
        return 0; // print error
    }
    retData = data[tos--];
    return retData;
}

int main(){ 
    MyStack<int> istack; // only useable type of int
    istack.push(3);
    cout << istack.pop() << endl;

    MyStack<double> dstack; // only useable type of double
    dstack.push(3.3);
    cout << dstack.pop() << endl;

    MyStack<char> *p = new MyStack<char>(); // only useable type of char
    p->push('a');
    cout << p->pop() << endl;
    delete p;
}