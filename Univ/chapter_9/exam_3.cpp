#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Silver{
    private:
        string name;
        int rate;
        int point;
        public:
        Silver(string n, int r = 3): name(n), rate(r), point(0){}
        void earn(int money){
            point += floor(money * rate / 100);
        }
        void show(){
            cout << name << "님의 현재 누적 포인트는 " << point << "점" << endl;
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