//정수를 1개 읽고 10자리 수가 얼마인지 출력하라.
#include <iostream>
using namespace std;

int main(){
    int n,result;

    cout << "정수를 입력하세요 >>";
    cin >> n;
    
    result = (n/10)%10;
    cout << "10의 자리 수는 " << result << "입니다.";
    system("pause");
}
//clear