#include <iostream>
using namespace std;

template <class T>
T bigger(T a, T b){
    // 두 개의 매개 변수 a, b를 비교하여 큰 값을 리턴
    if(a > b) return a;
    else return b;
}

int main(){
    int a = 20, b = 50;
    char c = 'a', d = 'z';
    cout << "result of bigger(20, 50) -> " << bigger(a,b) << endl;
    cout << "result of bigger('a','z') --> " << bigger(c,d) << endl; 
}