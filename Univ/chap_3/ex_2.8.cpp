#include <iostream>
#include <string>

using namespace std;

class Calculator{
    private:
        int value;
        void cals(string Op, int num){
            if(Op == "+"){
                    value += num;;
            }
            if(Op == "-"){
                    value -= num;;
            }
            if(Op == "*"){
                    value *= num;
            }
            if(Op == "/"){
                if(num != 0){
                    value /= num;
                }
            }

        };
    public:
        Calculator(){value = 0;}
        
        void loop(){
            string op;
            int number;
            while(true){
                cout << "연산 입력>> ";
                cin >> op;
                if(op == "그만") break;
                cin >> number;
                cals(op, number);
            }
        }
        int getValue() {return value;}
};

int main(){
    Calculator jane;
    jane.loop();
    cout << "연산 결과는 " << jane.getValue() << endl;
    cin.clear();
    cin.ignore(100,'\n');
    cin.get();
}