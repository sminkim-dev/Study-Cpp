//3월 달력을 출력하는 프로그램을 작성해라. 1일이 무슨 요일인지 입력받고 실행 결과와 같이 출력하라. 각 날은 '\t'으로 분리하라.
#include <iostream>
#include <string>
using namespace std;

int main(){
    cout << "3월 1일은 무슨 요일입니까? >> ";
    
    int cnt = 0;
    string day_list[] = {"일","월","화","수","목","금","토"};
    string day;
    cin >> day;

    for(int i = 0; i < 7; i++){
        cout << day_list[i] << "\t";
    }
    cout << "\n";
    for(int i = 0; i < 7; i++){
        if(day == day_list[i]){
            cnt += i;
        }
    }
    for(int i = 0; i < cnt; i++){
        cout << "\t";
    }
    for(int i = 1; i <= 31; i++){
        cout << i << "\t";
        if((i + cnt) % 7 == 0){
            cout << "\n";
        }
    }
    cout << "\n";
    system("pause");
}
//clear