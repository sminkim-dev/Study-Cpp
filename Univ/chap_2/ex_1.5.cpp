//cout과 << 연산자를 이용하여 1에서 55까지의 정수를 한줄에 10개씩 출력하라. 각 수는 탭'\t'을 분리하여 출력하라.
#include <iostream>
using namespace std;

int main(){
    for(int i = 1; i <= 55; i++){
        cout << i << "\t";
        if(i % 10 == 0){
            cout << "\n";
        }
    }
    system("pause");
}
//clear