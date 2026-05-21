#include <iostream>
using namespace std;

class BaseArrary{
private:
    int capacity;
    int *mem;
protected:
    BaseArrary(int capacity = 50):capacity(capacity){
        this->mem = new int[capacity];
    }
    ~BaseArrary(){delete []mem;}
    void put(int index, int val){
        mem[index] = val;
    }
    int get(int index){
        return mem[index];
    }
public:
    int getCapacity(){return capacity;}
};
class MyStacks : public BaseArrary{
private:
    int index;
public:
    MyStacks(int capacity = 100) : BaseArrary(capacity){
        index = 0;
    }
    void push(int n){
        put(index, n);
        index++;
    }
    int pop(){
        int temp = get(index - 1);
        put(index - 1, 0);
        index--;
        return temp;
    }
    int length(){
        return index;
    }
};
int main(){
    MyStacks m;
    int n;

    cout << "큐에 저장할 5개의 정수 입력 >> ";
    for(int i = 0; i < 5; i++){
        cin >> n;
        m.push(n);
    }
    cout << "스택 용량 : " << m.getCapacity() << ", 스택 크기 : " << m.length() << endl;
    cout << "큐의 모든 정수를 삭제하고 출력...";

    while(m.length() != 0){
        cout << m.pop() << " ";
    }
    cout << endl;
    cout << "스택 용량 : " << m.getCapacity() << ", 스택 크기 : " << m.length() << endl;
}