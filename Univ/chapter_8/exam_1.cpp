#include <iostream>
using namespace std;

class Circle{
    private:
        int radius;
    public:
        Circle(int radius = 0) : radius(radius) {}
        int getRadius(){return radius;}
        void setRadius(int r){this->radius = r;}
        double getArea(){return 3.14 * radius * radius;}
};

class NamedCircle : public Circle{
    string name;
    public:
        NamedCircle(int radius, string name) : Circle(radius), name(name) {}
        void show(){
            cout << "radius : " << getRadius() << " name : " << name << endl;
        }
};

int main(){
    NamedCircle waffle(3, "waffle");
    waffle.show();
}