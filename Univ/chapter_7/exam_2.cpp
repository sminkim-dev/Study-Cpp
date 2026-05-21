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
    // 멤버 함수 구현
    Coffee operator+=(Coffee &c1){
        this->water += c1.water;
        this->espresso += c1.espresso;
        this->sugar += c1.sugar;
        this->cream += c1.cream;
        return *this;
    }
    Coffee operator+=(int n){
        this->espresso += n;
        return *this;
    }
    Coffee operator++(int n){
        Coffee tmp;
        tmp.espresso++;
        return tmp;
    }
    // 프렌드 함수 구현
    // friend Coffee operator+=(Coffee &c1, Coffee &c2);
    // friend Coffee operator+=(Coffee &c1, int n);
    // friend Coffee operator++(Coffee &c, int n);
};
// Coffee operator+=(Coffee &c1, Coffee &c2){
//     c1.water += c2.water;
//     c1.espresso += c2.espresso;
//     c1.sugar += c2.sugar;
//     c1.cream += c2.cream;
//     return c1;
// }
// Coffee operator+=(Coffee &c, int n){
//     c.espresso += 1;
//     return c;
// }
// Coffee operator++(Coffee &c, int n){
//     Coffee tmp;
//     tmp.espresso++;
//     return tmp;
// }
int main(){
    Coffee black(2, 5, 0, 0), dabang(2,2,2,2);
    black += dabang; // black coffee에 dabang coffee 합치기
    black += 1; // add espresso + 1
    black++; // espresso + 1
    black.show();
    return 0;
}