//cin.getline()을 이용하여 "OK"가 입력될 때까지 종료되지 않는 프로그램을 작성하라.
#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char text[100];

    while(true){
        cout << "끝내려면 OK를 입력하세요 >> ";
        cin.getline(text,100,'\n');
        if(strcmp(text,"OK") == 0){
            cout << "종료합니다.";
            break;
        }
    }
    system("pause");
}
//clear