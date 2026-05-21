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
    bool operator!(){
        if(this->sugar == 0)return true;
        else return false;
    }
    bool operator>(Coffee b){
        int sum1 = this->water + this->espresso + this->sugar + this->cream;
        int sum2 = b.water + b.espresso + b.sugar + b.cream;
        if(sum1 > sum2) return true;
        else return false;
    }
};
int main(){
    Coffee a(2, 5, 0, 0), b(2,2,2,2);
    if(!a) // no sugar 
    cout << "no sugar" << endl;
    if(a>b) cout << "coffee a가 양이 더 많다.";
    else cout << "coffee b가 양이 더 많다.";
    return 0;
}