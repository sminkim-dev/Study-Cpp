#include <iostream>
#include <string>
using namespace std;

class EspressoCoffee{
    string name;
    int espresso, water;
    public:
        EspressoCoffee(string name, int espresso, int water) : name(name), espresso(espresso), water(water) {}
        void recipe(){
            cout << name << "는 에스프레소 " << espresso << "스푼" << ", 물 " << water << "스푼 " << endl;
        }
        void get(string& name, int &espresso, int &water){
            name = this->name;
            espresso = this->espresso;
            water = this->water;
        }
        int getE(){return espresso;}
        int getW(){return water;}
        string getName(){return name;}
};
class Cappuccino : public EspressoCoffee{
    int milk;
    bool ice; // false means hot
    public:
        Cappuccino(string name, int espresso, int water, int milk, bool ice) : EspressoCoffee(name, espresso, water) , milk(milk), ice(ice) {}
        
        void recipe(){
            // if 여러 개 걸어서 cout을 끊어서 붙이는 것보단 삼항 연산자를 통해 한 줄로 표현하는게 더 효율적이고 직관적임.
            // 지금은 Espresso class의 멤버 변수를 함수를 통해 값을 가져왔지만, private이 아닌, protect로 하면 접근 가능하다고 함. 확인해 볼 것.
            cout << getName() << "는 에스프레소 " << getE() << "스푼, " << (ice ? "얼음물 " : "따뜻한 물 ") 
            << getW() << "스푼, 우유 " << milk << "스푼" << (ice ? ", 얼음 충분히" : "") << endl;
        }
};
int main(){
    EspressoCoffee espresso("에스프레소", 2, 0);
    EspressoCoffee americano("아메리카노", 2,  5);
    americano.recipe();

    Cappuccino myHotCap("따뜻한 카푸치노", 2, 2, 4, false);
    myHotCap.recipe();

    Cappuccino myIceCap("아이스 카푸치노",2,1,5,true);
    myIceCap.recipe();
    return 0;
}