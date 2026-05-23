//구구단 퀴즈의 답을 검사하는 프로그램을 작성하라. 
//랜덤하게 구구단을 묻고 사용자로부터 답을 입력받아 정답인지 판단한다. 3번 틀리면 종료.
#include <iostream>
//랜덤 정수를 발생시키기 위해서는 두 개의 헤더파일.h을 불러와야 한다.
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){

    cout << "***구구단 맞추기 퀴즈입니다. ***\n";
    
    srand((unsigned)time(0));//랜덤 수 발생시키기 전에 한 번만 호출. seed 초기화
    int mul, in_num, cnt;
    while(true){
        int n = rand() % 9 + 1;// [0, RAND_MAX(32767)]사이의 랜덤 정수 발생
        int m = rand() % 9 + 1;// 구구단이기 때문에 1 ~ 9 사이의 정수 값만 발생시키는 것.
        mul = n*m;
    
        cout << n << " * " << m << " = ";
        cin >> in_num;
        if(mul == in_num){
            cout << "정답입니다. 잘했습니다.\n";
        }
        else{
            cnt++;
            cout << cnt << "번 틀렸습니다. 분발하세요.\n";
            if(cnt == 3){
                cout << "퀴즈 종료합니다.\n";
                break;
                return 0;
            }
        }
    }
    
    
    system("pause");
}
//clear