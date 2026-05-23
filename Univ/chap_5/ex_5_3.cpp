#include <iostream>

using namespace std;

class Bubble{
    int radius;
    public:
        Bubble(int radius){this->radius = radius;}
        int getRadius(){return radius;}
        void setRadius(int radius){this->radius=radius;}
};
void addBubble(Bubble &a, Bubble &b, Bubble &c){
    int sum = a.getRadius() + b.getRadius() + c.getRadius();
    c.setRadius(sum);
}
int main(){
    Bubble a(5), b(10), c(130);
    addBubble(a,b,c);
    cout << "버블 c의 반지름 " << c.getRadius() << endl;

    cin.get();
}