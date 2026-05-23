//빈칸 없는 두 개의 문자열을 입력받아 두 개의 문자열이 같으면 "YES", 아니면 "NO"를 출력하는 프로그램을 작성하되
// 다음 2개의 지시된 대로 각각 작성할 것. 빈칸 없는 문자열의 입력은 cin과 >> 연산자를 이용하면 됨.
#include <iostream>
#include <string>
using namespace std;

int main(){
    string first_str;
    string second_str;

    cout << "문자열을 입력하세요 >> ";
    cin >> first_str;
    cout << "문자열을 입력하세요 >> ";
    cin >> second_str;

    if(first_str == second_str){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    system("pause");
}
//clear