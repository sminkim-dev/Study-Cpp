#include <iostream>

using namespace std;

class Player{
private:
    string name;
public:
    void setName(string name){this->name = name;}
    string getName(){return name;}
};

class FourSumGame{
    private:
        int player;
        Player *p;
    public:
        FourSumGame(int player){
            this->player = player;
            this->p = new Player[player];
        }
        ~FourSumGame(){delete []p;}
        void run(){
            cout << player << "명이 Four Sum 게임을 시작합니다." << endl;
            for(int i = 0; i < player; i++){
                string name;
                cin >> name;
                p[i].setName(name);
            }
            
            int turn = 0;
            while(true){
                int sum, mynum;
                Player& currentPlayer = p[turn % player];

                cout << currentPlayer.getName() << "님, 예상 합과 수 입력하세요>>";
                cin >> sum >> mynum;
                // 컴퓨터의 랜덤 수
                int comNum = rand() % 3;

                // 결과 판단 로직
                if (sum == (mynum + comNum)) {
                cout << "예상 합 " << sum << ", " << currentPlayer.getName() 
                     << " " << mynum << ", 컴 " << comNum << " : " 
                     << currentPlayer.getName() << "님 승리!!" << endl;
                    break; // 게임 종료
                } else {
                    cout << "예상 합 " << sum << ", " << currentPlayer.getName() 
                        << " " << mynum << ", 컴 " << comNum << " : 실패!" << endl;
                }

                turn++; // 다음 사람 차례로 넘기기
            }
        }
};

int main(){
    FourSumGame game(2);
    game.run();

    cin.clear();
    cin.ignore(100,'\n');
    cin.get();
}