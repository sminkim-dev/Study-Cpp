//cin.getline()으로 영문 텍스트 한 라인을 입력받아 단어가 몇 개 있는지 출력하는 프로그램을 작성할 것. "exit"을 입력받으면 종료될 것
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm> // transform을 쓰기 위해 필요
#include <cctype>    // tolower를 쓰기 위해 필요
using namespace std;

int main(){
    
    string text;
    while(true){
        cout << "영문 텍스트를 입력하세요(빈칸 포함 가능) >> ";
        getline(cin,text);
        // 2가지 방법 존재.
        
        // 문자열 전체를 소문자로 변환 (이게 핵심!)
        // 시작부터 끝까지 돌면서 각 문자를 tolower(소문자화) 시킵니다.
        //transform(text.begin(), text.end(), text.begin(), ::tolower);

        int count = 0;
        for(int i = 0; i < text.length(); i++){
            //exit ,Exit, EXIT 관계없이 들어가는 모든 값을 소문자로 만들어서 결국엔 정지되게 만듦.
            text[i] = tolower(text[i]);// 위에 transform 한 줄이 이 반복문 5줄과 같은 내용. 하지만 cnt 자릿 수를 찾아야해서 반복문 자체는 필요.
            count++;
        }
        if(text == "exit"){
            break;
            return 0;
        }
        cout << "단어의 개수는 " << count << "개이다.\n";
        

        /*
        if(text == "exit"){
        break;
        return 0;
        }   
        int cnt = 0;
        for(int i = 0; ;i++){
            if(text[i] == '\0'){
                cout << "단어의 개수는 " << cnt << "개이다.\n";
                break;
            }
            else{
                cnt++;
            }
        }
    }
        
        */
        
    
    }
    system("pause");
}
//clear