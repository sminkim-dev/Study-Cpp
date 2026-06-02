#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v; // create vector that only useable type of int 

    v.push_back(1); // 벡터에 정수 삽입
    v.push_back(2);
    v.push_back(3);

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";    // 벡터의 모든 원소 출력
    }
    cout << endl;

    v[0] = 10;  // 벡터의 첫번째 원소를 10으로 변경
    int m = v[2];   // m에 3저장
    v.at(2) = 5;    // 벡터의 3번째 원소를 5로 변경

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";    // 벡터의 모든 원소 출력
    }
    cout << m << endl;
    cout << endl;
}