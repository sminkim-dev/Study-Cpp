#include <iostream>
using namespace std;

class Base
{
public:
    // virtual void func()
    // {
    //     cout << "Base::func()" << endl;
    // }
    void func(){
        cout << "Base::func()" << endl;
    }
};
class Derived : public Base
{
public:
    // void func() override
    // {
    //     cout << "Derived::func()" << endl;
    // }
    void func(){
        cout << "Derived::func()" << endl;
    }
};
int main(){
    Derived d, *dper;
    dper = &d;
    dper->func();

    Base b, *bper;
    bper = &b;
    bper = dper; // upcasting 을 통해 Base 클래스 포인터로 Derived 객체를 가리키게 함.
    bper->func(); // 하지만 virtual이 없으므로 Base 클래스의 func()가 호출됨. 왜냐, virtual이 없으면 해당 포인터를 통해 함수가 호출되기 때문.
    return 0;
}