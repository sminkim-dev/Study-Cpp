#include <iostream>
#include "designed.h"

using namespace std;

int main(){
    int n1,n2;
    cout << "width : ";
    cin >> n1;
    cout << "height : ";
    cin >> n2;
    
    Rect *p = new Rect(n1,n2);

    cout << "사각형의 width : " << p->getWidth() << "이고, 사각형의 height : " << p->getHeight() << "이며, 넓이는 : " << p->getArea() << "입니다." << endl;
    delete p;

    system("pause");
    return 0;
}