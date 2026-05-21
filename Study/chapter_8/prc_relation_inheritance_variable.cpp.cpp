#include <iostream>
#include <string>
using namespace std;

class TV{
    private:
        int size;
    public:
        TV(){size = 20;}
        TV(int size) : size(size) {}
        int getSize(){return size;}
};

class WideTV : public TV{
    bool videoIn;
    public:
        WideTV(int size, bool videoIn) : TV(size){
            this->videoIn = videoIn;
        }
        bool getVideoIn(){return videoIn;}
};

class Smart : public WideTV{
    string inAddr; // address internet
    public:
        Smart(string inAddr, int size) : WideTV(size, true){
            this->inAddr = inAddr;
        }
        string getInAddr(){return inAddr;}
};

int main(){
    // size 32inch , address '192.0.0.1' create smart tv object
    Smart htv("192.0.0.1", 32);
    cout << "size = " << htv.getSize() << endl;
    // 함수에서는 value of bool을 true or false로 반환하지만, cout 표준 설정이 true(1), false(0) 임으로
    // cout 에서 bool을 문자로 출력하고 싶을 경우엔 boolalpha를 작성해야함. 반대로 다시 숫자로 변환하고 싶을 경우엔 한 번더 작성한다.
    cout << "videoIn = " << boolalpha << htv.getVideoIn() << endl;
    cout << "IP = " << htv.getInAddr() << endl;
}