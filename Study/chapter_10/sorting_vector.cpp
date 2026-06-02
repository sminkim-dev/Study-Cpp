#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> v;

    cout << "5개의 정수를 입력하세요 >> ";
    for(int i = 0; i < 5; i++){
        int n;
        cin >> n;
        v.push_back(n); 
    }
    // v.begin()에서 v.end() 사이의 값을 오름차순으로 정렬
    // sort() 함수의 실행 결과 벡터 v의 원소 순서가 변경됨
    
    cout << "내림차순 정렬" << endl;
    sort(v.begin(), v.end());

    vector<int>::iterator it;
    for(it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    cout << "내림차순 정렬" << endl;
    reverse(v.begin(), v.end());
    for(it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}