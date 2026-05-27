#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class AbstractPoint{
    protected:
        string name;
        int point = 0;
        int ratio;
        public:
        AbstractPoint(string name, int ratio = 1): name(name), ratio(ratio){}
        virtual void earn(int pay) = 0;
        virtual void show() = 0;
        int getPoint(){return point;}
};
class Silver : public AbstractPoint{
        public:
        Silver(string name, int ratio = 3): AbstractPoint(name, ratio){}
        void earn(int money) override{
            point += floor(money * ratio / 100);
        }
        void show() override{
            cout << name << "님의 현재 누적 포인트는 " << getPoint() << "점" << endl;
        }
};
int main(){
    Silver hwang("황기태"), ok("옥지윤" , 4);

    hwang.earn(10000); // 1만원을 지출한 경우, 포인트 300적립
    hwang.earn(20000); // 2만원을 지출한 경우, 포인트 600적립
    hwang.earn(5000);  // 5천원 지출한 경우, 포인트 150적립
    ok.earn(5000); // 5천원 지출한 경우, 포인트 200 적립
    hwang.show(); // 현재 누적 포인트는 1050점
    ok.show(); // 현재 누적 포인트는 200점
}