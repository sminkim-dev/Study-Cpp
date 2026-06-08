#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
using namespace std;
class Nation;
vector<Nation> v;
int count_N = 0;
class Nation{
    public:
        string nation, capital;
        Nation(string n, string c):nation(n), capital(c){}
        void set(string n, string c){
            this->nation = n;
            this->capital = c;
        }
};

void start_str(){
    cout << "*** 나라의 수도 맞추기 게임을 시작합니다. ***" << endl;
}

int menu_(){
    cout << "정보 입력 : 1 , 퀴즈 : 2 , 종료 : 3 >> ";
    int sel;
    cin >> sel;
    string temp;
    getline(cin, temp);
    return sel;
}
bool check(string first, string second){
    for(auto it = v.begin(); it != v.end(); it++){
        if(it->nation == first){
            return false;
        }
    }
    return true;
}
void insert(){
    cout << "현재 " << count_N << "개의 나라가 입력되어 있습니다. " << endl;
    cout << "나라와 수도를 입력하세요 (no no 이면 입력 끝)" << endl;
    while(true){
        cout << count_N + 1 << "> ";
        string text;
        getline(cin, text);
        if(text == "no no")break;
        int cut = text.find(" ");
        string first = text.substr(0, cut);
        string second = text.substr(cut + 1);
        if(check(first, second) == true){
            Nation n(first, second);
            v.push_back(n);
            count_N++;
        }
        else{
            cout << "alreadt exists !!" << endl;
            continue;
        }
    }
}
void quiz(){
    while(true){
        int r_num = rand() % v.size();
        cout << v[r_num].nation << "의 수도는? >> ";
        string ans;
        getline(cin, ans);
        if(ans == "exit")break;
        if(ans == v[r_num].capital){
            cout << "Correct !!" << endl;
        }
        else{
            cout << "No !!" << endl;
        }
    }
}
int main(){
    srand(unsigned(time(0)));
    start_str();  
    while(true){
        int menu = menu_();
        if(menu == 3)break;
        else if(menu == 1){
            insert();
        }
        else if(menu == 2){
            quiz();
        }
    }
}