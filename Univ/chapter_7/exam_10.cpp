#include <iostream>
using namespace std;

class Stack{
    private:
        int *data;
        int size;
        int count = 0;
    public:
        Stack(int size = 3) : size(size){
            this->data = new int[size];
        }
        ~Stack(){delete []data;}
        friend Stack& operator <<(Stack& a, int n);
        bool operator!(){
            return (this->count == 0);
        }
        friend Stack& operator >>(Stack& a, int &x);
};
Stack& operator <<(Stack& a, int n){
    a.data[a.count++] = n;
    return a;
}
Stack& operator >>(Stack& a, int &x){
    x = a.data[--a.count]; // 위에서 증감 후위 연산자를 썼기에 제일 최근 count는 현재 들어간 인덱스보다 +1임으로, 전위 증감 연산자로 먼저 깎고 시작.
    return a;
}

int main(){
    Stack stack;
    stack << 3 << 5 << 10; // 3 , 5 , 10 순서대로 푸쉬 + 연쇄 연산이 가능함으로, 객체 + int and int + int로 나눠서 생각할 필요 x
    while(true){
        if(!stack)break;
        int x;
        stack >> x; // stack의 탑에 있는 정수 팝
        cout << x << " "; // print reverse
    }
    cout << endl;
    return 0;
}