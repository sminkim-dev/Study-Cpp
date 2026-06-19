#include <iostream>
using namespace std;

class AbstractStack {
public:
    virtual bool push(int n) = 0;
    virtual bool pop(int& n) = 0;
    virtual int size() = 0;
    virtual ~AbstractStack() {}
};

class IntStack : public AbstractStack {
private:
    int size_ = 0;   // 최대 크기
    int tos = 0;     // 현재 저장된 개수, 다음 push 위치
    int* stack;

public:
    IntStack(int size) {
        this->size_ = size;
        this->stack = new int[size];
    }

    ~IntStack() {
        delete[] stack;
    }

    bool push(int n) override {
        if (tos >= size_) {
            return false;
        }

        stack[tos++] = n;
        return true;
    }

    bool pop(int& n) override {
        if (tos == 0) {
            return false;
        }

        tos--;
        n = stack[tos];
        stack[tos] = 0;
        return true;
    }

    int size() override {
        return tos;  // 현재 저장된 개수
    }

    void show_all() {
        for (int i = 0; i < tos; i++) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    IntStack is(10);

    for(int i = 0; i < 10; i++) {
        is.push(i);
    }

    cout << "현재 스택: ";
    is.show_all();

    int n[10];

    cout << "pop 결과: ";
    for(int i = 0; i < 10; i++) {
        if(is.pop(n[i])) {
            cout << n[i] << " ";
        }
    }
    cout << endl;

    cout << "현재 스택: ";
    is.show_all();

    cout << "현재 size: " << is.size() << endl;
}