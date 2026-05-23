/*영문 텍스트를 입력받아 알파벳 히스토그램을 그리는 프로그램을 작성하라.
대문자를 모두 소문자로 집계하며 텍스트의 끝은 ';' 문자로 한다.*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main(){
    
    char text[10000];
    char Alp[27] = "abcdefghijklmnopqrstuvwxyz";//26
    int num_box[26] = {0};
    int cnt, sum;
    sum = 0;
    cnt = 0;
    cout << "히스토그램을 그립니다. 텍스트의 끝은 ; 이고\n10000개 문자까지 가능합니다. 영문 텍스트를 입력하세요.\n";
    cin.getline(text,10000,';');

    for(int i = 0; text[i] != '\0'; i++){
            char temp = tolower(text[i]); // 대문자 > 소문자
            if(isalpha(temp)){
                cnt++;
                for(int j = 0; j < 26; j++){
                    if(temp == Alp[j]){
                        num_box[j] += 1;
                        break;
                    }
                }
             }
                
       }
       cout << "총 알파벳 수 : " << cnt << "\n\n";
            for(int i = 0; i < 26; i++){
                cout << Alp[i] << " (" << num_box[i] << ")\t:";
                for(int b = 0; b < num_box[i]; b++){
                    cout << "*";
                }
                cout << "\n";
                }
                cout << "\n";
        system("pause");
}
//clear