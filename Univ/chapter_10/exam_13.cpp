#include <iostream>
#include <map>
#include <string>
#include <iterator>
using namespace std;

class Content;
map<string, Content> passwdMap;

class Content{
    public:
        string passwd, hint; // 암호와 힌트 모두 빈칸 없는 문자열
        Content(string passwd="", string hint=""){
            this->passwd=passwd;
            this->hint=hint;
        }
};

int menu_(){
    cout << "삽입 : 1 , 검사 : 2 , 종료 : 3 >> ";
    int sel;
    cin >> sel;
    return sel;
}
void insert(){
    cout << "이름, 암호, 힌트 >> ";
    string name;
    string passwd;
    string hint;
    cin >> name >> passwd >> hint;
    passwdMap.insert(make_pair(name, Content(passwd, hint)));
}

bool find_name(string name){
    for(auto it = passwdMap.begin(); it != passwdMap.end(); it++){
        if(it->first == name){
            return true;
        }
    }
    return false;
}

bool ck_passwd(string pw){
    for(auto it = passwdMap.begin(); it != passwdMap.end(); it++){
        if(it->second.passwd == pw){
            return true;
        }
    }
    return false;
}
string find_hint(string name){
    string hint = "";
    for(auto it = passwdMap.begin(); it != passwdMap.end(); it++){
        if(it->first == name){
            hint = it->second.hint;
            return hint;
        }
    }
    return hint;
}
void check(){
    cout << "이름? ";
    string name;
    cin >> name;
    if(find_name(name) != true){
        cout << name << "은 없는 이름입니다. " << endl;
        return;
    }
    cout << "암호? ";
    string pw;
    cin >> pw;
    if(ck_passwd(pw) == false){
        cout << "실패---, 힌트는 " << find_hint(name) << endl;
        return;
    }
    cout << "통과!!" << endl;
    return;
}

int main(){
    cout << "*** 암호관리 프로그램 Who are you? 를 시작합니다. ***" << endl;
    while(true){
        int menu = menu_();
        if(menu == 3)break;
        if(menu == 1){
            insert();
        }
        else if(menu == 2){
            check();
        }
    }
    cout << "progran exit...." << endl;
    return 0;
}