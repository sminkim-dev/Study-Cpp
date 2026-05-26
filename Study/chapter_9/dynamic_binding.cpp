#include <iostream>
using namespace std;

class Shape{
    public:
        void paint(){
            draw();
        }   
        virtual void draw(){
            cout << "Shape::draw() called" << endl;
        }
};
class Circle : public Shape{
    public:
        void draw() override{
            cout << "Circle::draw() called" << endl;
        }
};
int main(){
    Shape* shape = new Circle();
    shape->paint(); // Shape::paint() 호출 -> Circle::draw() 호출
    delete shape;
    return 0;
}