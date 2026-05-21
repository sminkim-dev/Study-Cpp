#include <iostream>
#include <string>
using namespace std;

class PrimitiveCPU{
private:
    int acc = 0; // cpu 내 저장공간
public:
    PrimitiveCPU(int val) : acc(val){}
    void add(int b){acc += b;}
    void load(int b){acc = b;} // acc에 b를 저장하는 연산
    int read(){return acc;} // acc 값을 알려주는 연산
    void show(){
        cout << "acc = " << acc << endl;
    }
};
class ArithCPU : public PrimitiveCPU{
protected:
    void sub(int b){
        int temp = read();
        temp -= b;
        load(temp);
    }
    void mul(int b){
        int temp = read();
        temp *= b;
        load(temp);
    }
    void div(int b){
        int temp = read();
        temp /= b;
        load(temp);
    }
    void execute(string cmd, int operand = -1){
        // 명령 cmd 처리
        if(cmd == "load")load(operand);
        else if(cmd == "add")add(operand);
        else if(cmd == "sub")sub(operand);
        else if(cmd == "mul")mul(operand);
        else if(cmd == "div")div(operand);
        else if(cmd == "prt")show();
    }
public:
    ArithCPU(int val) : PrimitiveCPU(val){}
    void run(){
        cout << "실행을 시작합니다...명령을 입력하세요..." << endl;
        while(true){
            cout << ">> ";
            string line;
            // 아래 방법은 고전적인 방법, c++에서도 tokenizer같은 기능을 구현 가능
            // #include <sstream> 후에 stringstream ss(line); before int operand = -1;
            // ss >> cmd; ss >> operand;
            // 이외에도 vetor and ranges를 응용해, java, python의 split() 함수 구현 가능. (필요할 때 찾아볼 것)
            getline(cin, line, '\n');
            if(line == "stop")break;
            // string으로 한 줄로 받고, 명령어 및 값 처리 과정
            int findIndex = line.find(' ');
            string cmd; 
            int value = -1; // size_t 로 잡을 경우 아래 조건문, findIndex != stirng::nops 변경.
            // int findIndex = line.find(' ');에서 값을 찾으면 해당 값을 반환, 찾지 못한다면 -1을 반환하는 로직을 이용.
            if(findIndex != -1){
                value = stoi(line.substr(findIndex));
                cmd = line.substr(0, findIndex); 
            }
            else{
                cmd = line;
            }
            execute(cmd, value);
        }
        cout << "실행을 종료합니다." << endl;
    }
};
int main(){
    ArithCPU myCPU(0);
    myCPU.run();
}