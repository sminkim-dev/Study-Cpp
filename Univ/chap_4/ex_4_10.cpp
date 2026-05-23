#include <iostream>
#include <string>

using namespace std;

// 영화 정보를 저장하는 클래스
class Movie{
    string title;
    int score;
    public:
        Movie(){title = ""; score = 0;}
        string getTitle(){return title;}
        int getScore(){return score;}
        void set(string title, int score){
            this->title = title;
            this->score = score;
        }
};

// 영화를 관리하고 추천하는 클래스
class Recommeded{
    string name;
    Movie *p;
    int size;
    public:
        Recommeded(string name, int size){
            this->name = name;
            this->size = size;
            this->p = new Movie[size];
            cout << name << " 객체가 생성되었습니다. " << endl;
        }
        // 소멸자 : 메모리 해제
        ~Recommeded(){
            cout << name << "객체가 소멸되었습니다." << endl;
            delete []p;
        }
        // 영화 정보를 입력 받는 함수
        void read(){
            for(int i = 0; i < size; i++){
                string title;
                int score;
                string temp;

                cout << "영화" << i + 1 << ">> ";
                getline(cin,title, ',');
                cin >> score;
                // 점수 뒤의 엔터 ('\n')를 읽어서 버림 !! 중요
                getline(cin,temp);

                p[i].set(title,score);
            }
        }
        // 입력된 영화 목록을 출력하는 함수
        void list(){
            for(int i = 0; i < size; i++){
                cout << "[" << p[i].getTitle() << "," << p[i].getScore() << "]\t";
            }
            cout << endl;
        }
        // 가장 높은 점수의 영화를 반환하는 함수
        Movie recommend(){
            int maxIndex = 0;
            for(int i = 0; i < size; i++){
                if(p[i].getScore() > p[maxIndex].getScore()){
                    maxIndex = i;
                }
            }
            return p[maxIndex];
        }
        
};

int main(){
    Recommeded *mr = new Recommeded("베스트 영화 추천", 3);
    mr->read();
    mr->list();
    Movie m = mr->recommend();
    cout << "추천 영화 : " << m.getTitle() << endl;
    delete mr;
    cin.clear();
    cin.ignore(100,'\n');
    cin.get();
}