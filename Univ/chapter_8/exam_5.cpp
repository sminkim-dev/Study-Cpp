#include <iostream>
#include <string>
using namespace std;

// 해당 문제의 오타가 많은 듯 함.
// 1. 골드 멤버 포인트는 2750이 될 수 없음. 계산 값 자체가 크기 때문에 계산 식 문제라기보단, 물리적으로 불가능한 수치임.
// + 억지로 2750을 맞추기 위해 계산 수식을 변경하여, 단위를 100 단위를 줄여 27500 -> 2750으로 만들 순 있지만, 정상적인 방법은 아니며, 수학적인 부분도 틀린 부분임.
// 2. 조건문 또한 범위 단위가 이상함. 자칫 실수하면 기본값 까지 건들임.
// 3. 단위 표현을 마음대로 써서 독자가 봤을 때 의도한 숫자가 명확히 전달이 안됨. 200000 "원" != 200000 "만원" >> 후자는 20 억원임.
class Member{
protected:
    string name;
    int point;
    int ratio; // point 적립률
public:
    Member(string name, int ratio = 1):name(name) , ratio(ratio) , point(0) {}
    void earn(int pay){
        // 사용한 만큼 포인트 적립
        this->point += (pay * (ratio * 0.01));
    }
    int getPoint(){return point;}
    void show(){
        cout << name << "의 포인트 " << point << endl;
    }
};
class GoldMember : public Member{
public:
    GoldMember(string name, int ratio = 3) : Member(name, ratio) {}
    void earn(int pay) {
    int currentRatio; // 이번 결제에 적용할 적립률

    if (pay >= 200000) {             // 20만 원 이상: 5%
        currentRatio = 5;
    } 
    else if (pay >= 100000) {        // 10만~20만 미만: 4%
        currentRatio = 4;
    } 
    else {                           // 그 외: 3%
        currentRatio = 3;
    }

    // (금액 * 적립률) / 100 순서로 계산해야 소수점 누락을 방지합니다.
    this->point += (pay * currentRatio / 100);
}
    int getPoint(){return point;}
    void show(){
        cout << name << "의 포인트 " << point << endl;
    }
};
int main(){
    Member a("황기태");
    GoldMember b("제인");

    for(int i = 0; i < 5; i++){
        string name; int pay;
        cout << i + 1 << "이름과 지출액 >> ";
        cin >> name >> pay;
        if(name == "황기태") a.earn(pay);
        else if(name == "제인") b.earn(pay);
        else i--;
    }
    a.show();
    b.show();
}