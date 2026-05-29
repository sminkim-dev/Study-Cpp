#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Player{
    protected:
        string name; // player name
        string bet; // player가 최근 낸 것 (가위, 바위 보 중에서)
        const string shape[3] = {"가위", "바위", "보"};
        int index;
    public:
        Player(string name):name(name){}
        virtual~Player(){}
        string getName(){return name;}
        string getBet(){return bet;}
        virtual void turn() = 0; // 선수가 자신의 차례일 때 가위, 바위, 보 중 하나를 bet에 저장
        int getIndex(){return index;}
};
class AI : public Player{
    public:
        AI(string name):Player(name){
            srand((unsigned)time(0));
            // srand() 는 rand()가 난수를 만들 때 사용할 "시작값", 즉 seed를 설정하는 함수임.
            // 여기서 time(0)은 현재 시간을 초 단위로 가져옴. 시간이 계속 바뀌니깐...프로그램을 실행할 때마다 다른 seed가 들어가고,
            // 그 결과 rand()가 매번 다른 순서의 난수를 만들게 됨.

            // 만약...? srand() 를 안쓰면, 프로그램을 다시 실행해도 rand()가 같은 순서의 숫자를 만들 수 있음. 가정하면 매번 AI가 비슷한 패턴을 낼 수 있음.
            // 그러면 해당 행동 패턴을 분석하여 예상 행동을 예측할 수 있기에 보안적인 부분에서는 부적합.
            
            // 즉, srand()는 매번 다른 랜덤 결과를 내도록 준비시키는 함수. 
        }
        void turn()override{
            bet = shape[rand() % 3];
            // rand()는 C / C++ 표준 라이브러리에서 제공하는 난수 생성 함수임. 즉, 여기서는 0 , 1 , 2 중 하나가 생성됨.
            // 사용하려면 보통 이런 헤더가 필요함. >> <cstdlib> : rand, srand, <ctime> : time
            for(int i = 0; i < 3; i++){
                if(bet == shape[i]){
                    index = i;
                }
            }
        }
};
class Human : public Player{
        
    public:
        Human(string name):Player(name){}
        void turn()override{
            while(true){
                cout << name << ", 가위 바위 보! >> ";
                string temp;
                cin >> temp;
                for(int i = 0; i < 3; i++){
                    if(temp == shape[i]){
                        bet = temp;
                        index = i;
                        return;
                    }
                    else{
                        continue;
                    }
                }
            }
        }
};
int main(){
    Player* players[2];
    players[0] = new Human("황수희");
    players[1] = new AI("AI제인");

    // 두 선수의 가위 바위 보
    // 교재의 승리 판정은 동일하면 AI 승, 다를 경우 사람 승임.
    // 원래 가위바위보 승리 판정으로 하려면 mod 를 이용하여 해결할 수 있을 듯 함.
    for(int i = 0; i < 2; i++) players[i] -> turn();
    // --- 여기 아래 주석 코드는 교재 7번 문제 승리 판정 부분 --- //
    // for(int i = 0; i < 2; i++) cout << players[i]->getName() + " " + players[i]->getBet() << ", ";
    // cout << endl;

    // if(players[0]->getBet() == players[1]->getBet()){
    //     // 낸 것이 같으면 AI 승리
    //     cout << players[1]->getName() + " 승리!";
    // }
    // else{
    //     cout << players[0]->getName() + " 승리!";
    // }
    // for(int i = 0; i < 2; i++){
    //     delete players[i];
    // }

    // --- 여기부터 교재 승리 판정이 아닌 기존 가위바위보 게임 승리 판정 기준 --- //
    // ((사람 인덱스 - ai 인덱스) + 3 ) % 3 >> 0 : 비김, 1 : 승리, 2 : 패배 < 사람 기준 판정 >
    // 절대값 기준 계산은 0 : 비김, 1 : 패배, 2 : 승리였지만, 이 수식으로 가면 결과가 틀림.
    // 추가... 절대값 사용하면 안됨! , abs() 연산을 하게 되면 승패 방향이 사라져서 결과 도출이 이상해짐. 그래서 양수로 만들기 위해 + 3을 해줌.
    int logic = (players[0]->getIndex() - players[1]->getIndex() + 3) % 3;
    if(logic == 0){
        cout << players[0]->getName() + " " + players[0]->getBet() << ", " << players[1]->getName() + " " + players[1]->getBet() << endl;
        cout << "비겼습니다." << endl;
    }
    else if(logic == 2){
        cout << players[0]->getName() + " " + players[0]->getBet() << ", " << players[1]->getName() + " " + players[1]->getBet() << endl;
        cout << "사람이 졌습니다 || AI가 승리하였습니다." << endl;
    }
    else if(logic == 1){
        cout << players[0]->getName() + " " + players[0]->getBet() << ", " << players[1]->getName() + " " + players[1]->getBet() << endl;
        cout << "사람이 이겼습니다 || AI가 졌습니다." << endl;
    }
    for(int i = 0; i < 2; i++){
        delete players[i];
    }
}