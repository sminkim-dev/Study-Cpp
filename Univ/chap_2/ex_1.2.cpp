//두 점으로 구성되는 사각형에 내접하는 타원의 면적을 출력하는 프로그램을 작성하라.
// 두 점은 왼쪽 상단 점과 오른쪽 하단 점을 순서대로 입력하며 타원의 면적은 3.14*a*b로 구하라. a와b는 각각 타원의 반지름이다.
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    
    double x1,x2,y1,y2,r1,r2;
    double Pi = 3.14;
    double result;
    cout << "사각형의 두 점(x1, y1, x2, y2)를 입력하시오 >>";
    cin >> x1 >> y1 >> x2 >> y2;

    r1 = abs(x1 - x2)/2;
    r2 = abs(y1 - y2)/2;
    result = Pi*r1*r2;
    cout << "타원의 면적은 " << result << "입니다.";
    system("pause");
}
//clear