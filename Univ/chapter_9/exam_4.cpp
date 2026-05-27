#include <iostream>
#include <string>
using namespace std;

class AbstractPoint
{
protected:
    string name;
    int point = 0;
    int ratio;

public:
    AbstractPoint(string name, int ratio = 1) : name(name), ratio(ratio) {}
    virtual void earn(int pay) = 0;
    virtual void show() = 0;
    int getPoint() { return point; }
};
class Platinum : public AbstractPoint
{
private:
    int ck_point;
    int ratio2;

public:
    Platinum(string name, int ratio, int ck_point, int ratio2) : AbstractPoint(name, ratio), ck_point(ck_point), ratio2(ratio2) {}
    void earn(int pay) override
    {
        if (pay >= ck_point)
        {
            point += pay * ratio2 / 100;
        }
        else
        {
            point += pay * ratio / 100;
        }
    }
    void show() override{
        cout << name << "님*** 적립 포인트는 " << getPoint() << "점입니다. " << endl;
    }
    void combine(Platinum &p){
        point += p.getPoint();
        p.point = 0;
    }
};
int main(){
    Platinum hwang("황기태", 5, 100000, 7), park("박채원", 5, 100000, 7);
    // 100000원까지는 5% 그 위는 7% 적립
    hwang.earn(50000); // 5만원을 지출한 경우, 포인트 2500점 적립
    hwang.earn(200000); // 20만원을 지출한 경우, 포인트 14000점 적립
    park.earn(500000); // 50만원을 지출한 경우, 포인트 35000점 적립
    hwang.show(); // 현재 누적 포인트는 16500점입니다.
    park.show(); // 현재 누적 포인트는 35000점입니다.

    hwang.combine(park); // 황기태가 박채원의 포인트를 합산
    hwang.show(); // 황기태님의 현재 누적 포인트는 51500점
    park.show(); // 박채원님의 현재 누적 포인트는 0점
}