#include <iostream>
#include <string>
using namespace std;

class Point{
    int x, y;
    public:
        Point(int x = 0, int y = 0) : x(x), y(y) {}
        void showPoint(){
            cout << "("<< x << " , " << y << ")" << endl;
        }
        void setP(int x, int y){
            this->x = x;
            this->y = y;
        }
};

class ColorPoint : public Point{
    string color;
    public:
        void set(int x, int y){
            setP(x, y);
        }
        void setColor(string color){
            this->color = color;
        }
        void showColor(){
            cout << this->color << " : ";
            showPoint();
        }
};
int main(){
    Point p;
    ColorPoint cp;
    cp.set(3,4);
    cp.setColor("Red");
    cp.showColor();
}