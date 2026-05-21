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
    Coffee &operator<<(Coffee b){
        this->water += b.water;
        this->espresso += b.espresso;
        this->sugar += b.sugar;
        this->cream += b.cream;
        return *this;
    }
    Coffee& operator<<(int n){
        this->water += n;
        return *this;
    }
};
int main(){
    Coffee a(2,5,0,0), b(2,2,2,2);
    a << b << 3; // coffee a에 coffee b를 더하고, 물 양을 3 더한다.
    a.show();
    return 0;
}