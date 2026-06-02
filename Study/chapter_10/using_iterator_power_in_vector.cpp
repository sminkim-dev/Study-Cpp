#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    vector<int>::iterator it; // vector v의 원소에 대한 포인터 it
    cout << "계산 이전 vector" << endl;
    for(it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    for(it = v.begin(); it != v.end(); it++){
        // iterator를 이용하여 모든 원소 탐색
        int n = *it; // it가 가리키는 원소 값 리턴
        n = n*2;
        *it = n; // it가 가리키는 원소에 값 쓰기
    }
    cout << "계산 이후(n * 2) vector" << endl;
    for(it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}