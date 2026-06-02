#include <iostream>
#include <typeinfo>
using namespace std;

template <class T1, class T2>
void mcopy(T1 src [], T2 dest [], int n){
    // src []의 n개 원소를 dest [] 에 복사
    for(int i = 0; i < n; i++){
        dest[i] = (T2)src[i];
    }
}

int main(){
    int x[] = {1,2,3,4,5};
    double d[5];
    char c[5] = {'H', 'e', 'l', 'l','o'}, e[5];

    mcopy(x,d,5); // int x []의 원소 5개를 double d[] 에 복사
    mcopy(c , e, 5); // char c[]의 원소 5개를 char c[]에 복사

    for(int i = 0; i < 5; i++){
        cout << d[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < 5; i++){
        cout << e[i] << " ";
    }
    cout << endl;
    cout << "d 배열의 자료형은 -> " << typeid(d[0]).name() << "uoble 입니다." << endl;
    cout << "x 배열의 자료형은 -> " << typeid(x[0]).name() << "nt 입니다." << endl;
    cout << "e 배열의 자료형은 -> " << typeid(e[0]).name() << "har 입니다." << endl;
    cout << "위의 결과를 보면 알 수 있듯이, int -> double로 복사가 완료되었음." << endl;
}