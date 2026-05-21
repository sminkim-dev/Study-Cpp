#include <iostream>
using namespace std;

class Coffee{
private:
    int water, espresso, sugar, cream;
public:
    Coffee(int water = 1, int coffee = 1, int sugar = 0, int cream = 0){
        this->water = water;
        this->espresso = coffee;
        this->sugar = sugar;
        this->cream = cream;
    }
    void show(){
        cout << "water : " << water << ", coffee : " << espresso;
        cout << ", sugar : " << sugar << ", cream : " << cream << endl;
    }
    friend Coffee operator+(Coffee c1, Coffee c2);
    friend Coffee operator+(Coffee c, int n);
};
    Coffee operator+(Coffee c1, Coffee c2){
            Coffee tmp;
            tmp.water = c1.water + c2.water;
            tmp.espresso = c1.espresso + c2.espresso;
            tmp.sugar = c1.sugar + c2.sugar;
            tmp.cream = c1.cream +c2.cream;
            return tmp;
        }
    Coffee operator+(Coffee c, int n){
        Coffee tmp;
        tmp.water = c.water;
        tmp.espresso = c.espresso + n;
        tmp.sugar = c.sugar;
        tmp.cream = c.cream;
        return tmp;
    }
int main(){
    Coffee black(2,5,0,0), dabang(2,2,2,2),c,d;
    c = black + dabang;
    d = c + 1;
    c.show();
    d.show();
    return 0;
}