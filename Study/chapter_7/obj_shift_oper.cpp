#include <iostream>
using namespace std;
// mac -> debug할 때 파일명 유의. operator 그대로 넣으면 컴파일 과정에서 문제 생김. 예) ! , >> , etc... 유의 할 것
class Power{
    int kick;
    int punch;
    public:
        Power(int kick = 0, int punch = 0){
            this->kick = kick;
            this->punch = punch;
        }
        void show();
        Power& operator << (int n); // 연산 후 power 객체의 참조 리턴
};
void Power::show(){
    cout << "kick = " << kick << " , " << "punch = " << punch << endl;
}
Power& Power::operator<< (int n){
    kick+=n;
    punch+=n;
    return *this;
}
int main(){
    Power a(1,2);
    a << 3 << 5 << 6; // 객체 a 에 3,5,6이 순서대로 더해진다.
    a.show();
    return 0;
}