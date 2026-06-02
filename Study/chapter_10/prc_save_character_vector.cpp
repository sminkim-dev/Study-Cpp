#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    vector<string> sv; // 문자열 배열 생성
    string name;    // 사전에서 가장 위에 나오는 이름을 저장하기 위한 변수

    cout << "이름을 5개 입력하라." << endl;
    for(int i = 0; i < 5; i++){
        cout << i + 1 << ">> ";
        getline(cin, name);
        sv.push_back(name);
    }
    name = sv.at(0); // vector의 첫번째 이름
    for(int i = 1; i < sv.size(); i++){
        if(name < sv[i]){ // 아스키 코드로 비교해서 비교함. 그래서 "사전식" 가장 마지막 이름을 찾는 것.
            // sv[i]의 문자열이 name보다 사전에서 뒤에 나옴
            name = sv[i]; // namedmf sv[i]의 문자열로 변경
        }
    }
    cout << "사전에서 가장 뒤에 나오는 이름은 " << name << "입니다." << endl;
}