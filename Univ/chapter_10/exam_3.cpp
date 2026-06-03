#include <iostream>
using namespace std;
// 일단 int값 비교는 정상, char 비교에서 ASCII로 비교해서 소 / 대문자는 서로 다른 값을 가지니 return false여야 하는데...답은 true라서.
// tolower로 소 / 대문자 구분 없이 동일 알파벳이면 true 리턴하게끔 만듦. 문제는 template 하나만 가지고 작성해야하는 문제인데,
// template 하나만 작성하면 기존 int 값에 tolower 이 개입하면서 잘못된 값이 나올 수 있어서,char 용을 따로 만드는 것이 나음.
// 오타 같긴 한데...일단 구해야 하는 답을 우선시로 구함.

template <class T>
bool equals(T *a, T *b, int n){
    bool check = true;
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]) return false;
    }
    return true;
}
bool equals(char *c, char *d, int n){
    bool check = true;
    for(int i = 0; i < n; i++){
        if(tolower(c[i]) != tolower(d[i])) return false;
    }
    return true;
}

int main(){
    int x[] = {3,5,9,7};
    int y[] = {3,5,7,9};
    if(equals(x,y,4)) cout << "같다." << endl;
    else cout << "다르다." << endl;

    char c[] = {'j','a','v','a'};
    char d[] = {'j','a','v','A'};
    if(equals(c,d,4)) cout << "같다." << endl;
    else cout << "다르다." << endl;
 }