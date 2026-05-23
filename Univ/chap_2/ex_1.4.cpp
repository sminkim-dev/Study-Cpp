//소수점을 가지는 실수 5개를 입력받아 양수들만 합하여 출력하라.
#include <iostream>
using namespace std;

int main(){
    
    double n1,n2,n3,n4,n5;
    double sum = 0;
    cout << "실수 5개를 입력하세요 >> ";
    cin >> n1 >> n2 >> n3 >> n4 >> n5;
    double num[] = {n1, n2, n3, n4, n5};

    for(int i = 0; i < 5; i++){
        if(num[i]>0){
            sum += num[i];
        }
    }
    cout << "양수 합은 " << sum << "입니다.";

    system("pause");
}
//clear