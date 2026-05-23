#include <iostream>

class Rect{
private:
    int width, height;
public:
    Rect(int w, int h){width = w; height = h;}
    int getWidth(){return width;}
    int getHeight(){return height;}
    int getArea();
};

int main(){
    Rect r(2,3);
    Rect *p;
    p = &r;
    std::cout << "사각형의 폭은 > " << p->getWidth() << ", 사각형의 높이는 > " << p->getHeight();

    system("pause");
    return 0;
}