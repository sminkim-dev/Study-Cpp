//키보드로부터 2개의 정수를 입력받아 합, 차, 곱을 구하여 출력하라.
#include <iostream>
using namespace std;

int main(){
    
    int n1, n2;
    int sum,sub,mul;
    cout << "두개의 정수를 입력하세요 >>";
    cin >> n1 >> n2;
    sum = n1 + n2;
    sub = n1 - n2;
    mul = n1 * n2;
    cout << n1 << "+" << n2 << "=" << sum << "\n" << n1 << "-" << n2 << "=" << sub << "\n"
        << n1 << "*" << n2 << "=" << mul;
    return 0;
}
// clear