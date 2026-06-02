#include <iostream>
using namespace std;

// template 사용하는 이유, 중복되는 함수를 깔끔하게 사용하기 위해서. 여기서도 지금 int, double 값을 변경하는 myswap을 따로 만들면 이름이 겹치지만.
// 이렇게 하면 하나로 해결이 가능함.

//  ---     ---     ---  //
//  템플릿 함수는 컴파일되지도 호출되지도 않는, 그저 함수의 틀임. 템플릿의 역할은 제네릭 함수를 선언하고, 컴파일 시점에 구체화시키기 위한 틀을 만드는 것임.
//  템플릿 함수로부터 구체화된 버전의 함수가 컴파일되고 호출된다.

//  --- 주의 사항 --- //
//  구체화 오류 ---> template <class T> void myswap(T & a, T & b)
//  제네릭 타입 T에 유의해야함. 매개변수 a,b 모두 타입 T로 선언되어 있기에, myswap()을 호출할 때 두 개의 매개 변수 타입이 동일해야 한다.

//  예를 들어... 해당 예시는 잘못된 호출임. int s = 4; double t = 5; myswap(s,t); --> X

//  템플릿은 함수의 작성을 용이하게 함. 즉 --> 소프트웨어의 생산성과 유연성을 높임.
//  반면 컴파일러에 따라 지원되지 않을 수도 있어 포팅에 취약함. 추가로 템플릿과 관련된 오류 메시지가 빈약하여 디버깅에 많은 어려움이 존재함.
class Circle{
    int radius;
    public:
        Circle(int radius=1):radius(radius){}
        int getRadius(){return radius;}
};

template <class T>
void myswap(T & a, T & b){
    // generic funciton
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main(){
    int a = 4, b = 5;
    myswap(a,b);
    cout << "a=" << a << " , " << "b=" << b << endl;
    double c = 0.3, d = 12.5;
    myswap(c,d);
    cout << "c=" << c << " , " << "d=" << d << endl;
    
    Circle donut(5), pizza(20);
    myswap(donut, pizza);
    cout << "donutRadius=" << donut.getRadius() << ", ";
    cout << "pizzaRadius=" << pizza.getRadius() << endl;
}