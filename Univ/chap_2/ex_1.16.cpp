/*한 줄 짜리의 두 영문 문자열에 공통적으로 들어 있는 알파벳을 출력하라. 대문자를 모두 소문자로 취급하고, 알파벳이
아닌 문자들은 무시하라. 공통으로 발견된 동일한 알파벳은 한 번만 출력하라. 영문 문자열은 99개의 문자를 최대로 한다.*/
#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

int main(){

    char text[2][100];
    bool check1[26] = {false};
    bool check2[26] = {false};

    for(int i = 0; i < 2; i++){
        cout << i + 1 << "번째 텍스트 입력 >> ";
        cin.getline(text[i],100);
        for(int b = 0; text[i][b] != '\0'; b++){
            char temp = char(tolower(text[i][b]));
            if(isalpha(text[i][b])){
                if(i == 0){
                    check1[temp - 'a'] = true;
                }
                else{
                    check2[temp - 'a'] = true;
                }
            }
        }
    }
    for(int i = 0; i < 26; i++){
        if(check1[i] && check2[i]){
            cout << (char)(i + 'a') << " ";
        }
    }
    system("pause");
}
//복습 필요.