#include <iostream>
using namespace std;

class Point{
private:
    int x, y;
public:
    Point(int x, int y) : x(x) , y(y) {}
    int getX(){return x;}
    int getY(){return y;}
    void leftX(){
        this->x -= 1;
    }
    void upY(){
        this->y += 1;
    }
protected:
    void move(int x, int y){
        this->x = x;
        this->y = y;
    }
};
class Point3D : public Point{
private:
    int z;
public:
    Point3D(int x, int y, int z) : Point(x,y), z(z){}
    void show(){
        cout << "(" << getX() << "," << getY() << "," << z << ")" << endl;
    }
    void upZ(){
        this->z += 1;
    }
    void set(int x, int y, int z){
        move(x,y);
        this->z = z;
    }
};
int main(){
    Point3D p(1,2,3);
    p.show();
    p.upZ();
    p.leftX();
    p.upY();
    p.show();
    p.set(10,20,30);
    p.show();
}