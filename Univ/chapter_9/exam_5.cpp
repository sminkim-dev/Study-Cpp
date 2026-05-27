#include <iostream>
using namespace std;

class AbstractStack
{
public:
    virtual bool push(int n) = 0; // 스택에 n을 push한다. 스택이 full이면 false return
    virtual bool pop(int &n) = 0; // stack에서 pop한 정수를 n에 return, stack이 empty이면 false return

    virtual int size() = 0; // 현재 스택에 저장된 정수의 개수 return
};
class InsStack : public AbstractStack
{
private:
    int *stack;
    int capacity;
    int data = 0;

public:
    InsStack(int capacity = 0) : capacity(capacity) {
        stack = new int[capacity];
    }
    bool push(int n) override
    {
        if (capacity <= data)
        {
            return false;
        }
        else
        {
            stack[data++] = n;
            return true;
        }
    }
    bool pop(int &n) override
    {
        if(data == 0){
            return false;
        }
        else{
            n = stack[data - 1];
            stack[data - 1] = 0;
            data--;
            cout << n << " ";
            return true;
        }
    }
    int size() override
    {
        return data;
    }
};
int main()
{
    cout << "** stack **" << endl;
    cout << "stack size >> ";
    int capacity;
    cin >> capacity;
    InsStack ls(capacity);
    int n;
    cout << "push >> ";
    for(int i = 0; i < capacity; i++){
        cin >> n;
        if(ls.push(n));
        else break;
    }
    cout << "pop >> ";
    for(int i = 0; i < capacity; i++){
        if(ls.pop(n));
        else break;
    }
    cout << endl;
    return 0;
}