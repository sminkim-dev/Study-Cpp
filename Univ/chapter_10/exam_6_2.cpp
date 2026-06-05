#include <iostream>
#include <vector>
#include <set>
#include <ctime>
#include <cstdlib>
#include <iterator>
#include <string>
#include <sstream>
using namespace std;

vector<string>first;
vector<string>middle;
vector<string>last;
set<string>createdName;
vector<string>*words_groups[3] = {
    &first, &middle, &last
};

void insert_value(string &text, vector<string> &words){
    stringstream ss(text);
    string tokens;
    while(ss >> tokens){
        words.push_back(tokens);
    }
}

int value_of_limit(){
    int check = 0;
    for(auto it = first.begin(); it != first.end(); it++){
        for(auto itt = middle.begin(); itt != middle.end(); itt++){
            for(auto ittt = last.begin(); ittt != last.end(); ittt++){
                if(*it != *itt && *it != *ittt && *itt != *ittt){
                    check++;
                }
            }
        }
    }
    return check;
}
string random_word(vector<string> names){
    return names[rand() % names.size()];
}
int main(){
    srand(unsigned(time(0)));
    string text[3] = {
        "성으로 사용될 글자들 입력 >> ",
        "중간 이름으로 사용될 글자들 입력 >> ",
        "끝 이름으로 사용될 글자들 입력 >> "
    };
    string words[3] = {
        "황 박 정 이 김 최 배 명",
        "유 진 수 행 채 고 태 민 지 나 송 리 원",
        "원 수 민 효 희 재 서 은 현 림 연 정 진 찬"
    };
    for(int i = 0; i < 3; i++){
        //cout << text[i];
        // string write;
        // getline(cin, write);
        insert_value(words[i], *words_groups[i]);
    }
    while(true){
        cout << "생성할 이름 수 >> ";
        int create;
        cin >> create;
        if(create > value_of_limit()){
            cout << "최대 생성 가능한 이름 개수는 " << value_of_limit() << endl;
            continue;
        }
        int check = 0;
        if(create == 0) break;
        while(true){
            if(check == create) break;
            string first_word = random_word(*words_groups[0]);
            string middle_word = random_word(*words_groups[1]);
            string last_word = random_word(*words_groups[2]);

            string Name = first_word + middle_word + last_word;
            if(createdName.insert(Name).second){
                check++;
            }
        }
        // 1400이후 부터 값이 안나오는 듯한 양상이 조금씩 보이는데, 무한 루프나 멈춘 것이 아닌, 중복된 값을 처리하고 중복되지 않는 값을 찾는 과정이
        // 오래 걸려서 그렇게 보이는 것. 이름을 찾을 때마다 다음 이름을 찾을 확률이 줄어드는데, 마지막 확률은 1% 아래로 내려가기에 운이 좋으면 1411 max값도 바로 나오지만,
        // 운이 없으면 멈춘 듯이 출력되지 않음. 하지만 실제로는 수백 수천번의 연산을 하며 랜덤 난수로 뽑은 단어들의 조합이 중복되지 않을 때까지 계속 무한 루프 돌면서 연산하기에
        // 이런 양상이 보이는 것. 실제로 랜덤 난수가 아닌, 3중 반복문으로 돌려보면 금방 출력되는 것을 알 수 있음. 하지만 이 문제는 랜덤 난수로 이름을 무작위 생성을 바랐기에, 이런 형태가 됨.
        for(auto it = createdName.begin(); it != createdName.end(); it++){
            cout << *it << " ";
        }
        cout << endl;
    }
}