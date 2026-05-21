#include <iostream>
using namespace std;

class A{
    int x;
    public:
        A(){x = 0;}
        A(int x) : x(x) {}
        int getX(){return x;}
};
class B : public A{
    int y;
    public:
        B(int x, int y) : A(x + 5){
            this->y = y;
        }
        int getY(){return y;}
};
class C : public B{
    int m;
    public:
        C(int x, int y, int c) : B(x,y){
            m = x * y * c;
        }
        int getM(){return m;}
};

int main(){
    C c(3,5,2);
    B b(3,4);
    cout << "C >> x : " << c.getX() << " y : " << c.getY() << " m : " << c.getM() << endl;
    cout << "B >> x : " << b.getX() << " y : " << b.getY() << endl;
    return 0;
}