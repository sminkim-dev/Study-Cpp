//빈칸 없는 문자열을 입력받아 각 문자를 분리하여 출력하는 프로그램을 작성하라.
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(){

    //string str1;
    char str1[100];

    cout << "빈칸 없이 문자열을 입력하세요 >> ";
    cin >> str1;
    for(int i = 0; i < 100; i++){
        cout << str1[i] << " ";
        if(str1[i] == '\n'){
            break;
        }
    }
    system("pause");
}
//clear