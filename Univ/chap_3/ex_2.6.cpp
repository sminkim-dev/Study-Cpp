#include <iostream>
#include <string>

using namespace std;

class Memo{
    private:
        string list[2]; //date[0] content[1]
    public:
        Memo(string date, string content):list{date,content}{}

        bool isSameDate(Memo b){// 중요!, 매개변수와 멤버변수의 이름이 같을 경우 충돌 일어남.
            if(list[0] == b.list[0]){ // this-> 써야되는 상황은 멤버 변수와 매개변수의 이름이 동일 할 경우 ex) this->date = date; 가까운 클래스에 있는 변수를 먼저 잡음.
                return true;
            }
            else{
                return false;
            }
        }
        string getDate(){return list[0];}
        string getContent(){return list[1];}
        void show(){
            cout << list[0] << ", " << list[1] << "\n";
        }
};

int main(){
    Memo a("1:20", "동계 프로그래밍 캠프");
    Memo b("2:20", "김경미 독일 송별회");
    Memo c("2:21", "박채원 졸업식, 대학원 간대");

    a.show();
    if(a.isSameDate(b)){
        cout << "같은 날입니다." << endl;
    }
    else{
        cout << "다른 날입니다." << endl;
    }
    cout << b.getDate() << "에 " << b.getContent() << endl;
    cin.get();
}