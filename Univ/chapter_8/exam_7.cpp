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
class MyQueue :public BaseArrary{
    private:
        int frontIndex;
        int backIndex;
        //int size = 0;
    public:
        MyQueue(int capacity = 100) : BaseArrary(capacity){
            frontIndex = 0;
            backIndex = 0;
        }
        void enqueue(int n){
            put(frontIndex, n);
            frontIndex++;
            //size++;
        }
        int dequeue(){
            // queue의 맨 마지막 수를 제거 및 출력
            // point, queue는 스택처럼 관리하지 말 것. 선입선출 형태가 되어야만 함. 스택처럼 관리하면 가장 나중에 들어간 값이 출력되게 되니 유의할 것.
            // 때문에 index를 두개로 관리하여 선입선출 관계를 만들어야 함.
            int temp = get(backIndex);

            put(backIndex , 0);
            backIndex++;
            return temp;
        }
        int length(){
            return frontIndex - backIndex;
        }
};
int main(){
    MyQueue m;
    int n;

    cout << "큐에 저장할 5개의 정수 입력 >> ";
    for(int i = 0; i < 5; i++){
        cin >> n;
        m.enqueue(n);
    }
    cout << "큐 용량 : " << m.getCapacity() << ", 큐 크기 : " << m.length() << endl;
    cout << "큐의 모든 정수를 삭제하고 출력...";

    while(m.length() != 0){
        cout << m.dequeue() << " ";
    }
    cout << endl;
    cout << "큐 용량 : " << m.getCapacity() << ", 큐 크기 : " << m.length() << endl;
}