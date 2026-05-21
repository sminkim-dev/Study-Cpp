#include <iostream>
#include <string>
using namespace std;

class Member{
    private:
        string name;
        int point;
    public:
        Member(string name = "", int point = 100){
            this->name = name;
            this->point = point;
        }
        Member& operator+=(int num){
            this->point += num;
            return *this;
        }
        void show(){
            cout << "[" << this->name << " , " << this->point << "]" << endl;
        }
};  
class MemberManager{
private:
    Member mems [100];
    int count;
public:
    MemberManager() : count(0){}
    MemberManager& operator <<(const Member& a){
        if(count < 100){
            mems[count++] = a; // 멤버 클래스 내부에 포인터가 없음으로 기본 대입 연산자가 값복사를 완벽히 수행함.
        }
        return *this;
    }
    Member& operator[](int index){
        return mems[index];
    }
};

int main(){
    MemberManager man;
    for(int i = 0; i < 3; i++){
        cout << "신규 회원 이름 >> ";
        string name;
        cin >> name; // 고객 이름 입력
        man << Member(name); // << 연산자로 신규 회원 저장, 포인트는 100으로 저장
    }

    for(int i = 0; i < 3; i++){
        man[i].show();
    }
    man[2] += 500;
    Member& c = man[1]; // man[1]은 컴파일러에 의해 man.[](1)로 해석됨.
    c += 200;

    for(int i = 0; i < 3; i++){
        man[i].show();
    }
    return 0;
}