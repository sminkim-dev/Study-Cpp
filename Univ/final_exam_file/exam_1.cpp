#include <iostream>
#include <string>
using namespace std;

class Point{
    int x, y;
    public: 
        Point(int x = 1, int y = 1){this->x = x; this->y = y;}
        int getX(){return this->x;}
        int getY(){return this->y;}
        void setXY(int x , int y){
            this->x = x;
            this->y = y;
        }
};

class ColorPoint : public Point{
    string color;
    public:
        ColorPoint(int x = 0, int y = 0, string color = "black") : Point(x,y){}
        void setColor(string color){this->color = color;}
        void show(){
            cout << this->color << "색으로 (" << Point::getX() << "," << Point::getY() << ")에 위치한 점입니다." << endl;
        }
        void setPoint(int x, int y){
            Point::setXY(x,y);
        }
};

int main(){
    Point point;
    cout << "Point 객체의 기본 좌표는 " << point.getX() << ", " << point.getY() << "입니다. " << endl;
    point.setXY(5,10);
    cout << "변경된 point 객체의 좌표는 " << point.getX() << ", " << point.getY() << "입니다. " << endl;

    ColorPoint zeroPoint;
    zeroPoint.show();

    ColorPoint cp(5,5);
    cp.setPoint(10,20);
    cp.setColor("BLUE");
    cp.show();
}