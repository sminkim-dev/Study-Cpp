#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <limits>
#include <climits>
// INT_MIN -> <limits> 만으로는 부족할 수 있어, <clitmits> 까지 include 함.
using namespace std;

// 26.06.08 15:14 // 입력 평균까진 정상, 그 이후 제거, 배수 로직 오류  추가로 결과값 출력이 빠짐.

vector<int> arr;
void show_all(){
    for(auto it = arr.begin(); it != arr.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void start(){
    cout << "10개의 정수 입력 >> ";
    int nums;
    for(int i = 0; i < 10; i++){
        cin >> nums;
        arr.push_back(nums);
    }
}
int menu(){
    cout << "가장 큰 값 : 1 , 평균 : 2 , 삽입 : 3, 삭제 : 4 , 증가 : 5 , 종료 : 6 >> ";
    int sel;
    cin >> sel;
    return sel;
}
int max_value(){
    int max = INT_MIN;
    for(auto it = arr.begin(); it != arr.end(); it++){
        if(max < *it){
            max = *it;
        }
    }
    return max;
}
double value_avg(){
    double sum = 0;
    for(auto it = arr.begin(); it != arr.end(); it++){
        sum += *it;
    }
    return sum / arr.size(); 
}
void insert(int in_){
    arr.push_back(in_);
    show_all();
}
void del(int del_){
    bool check = false;
    for(auto it = arr.begin(); it != arr.end(); it++){
        if(*it == del_){
            arr.erase(it);
            check = true;
        }
    }
    if(check == true){
        show_all();
        return;
    }
    else{
        cout << "Error, no exist of value" << endl;
        return;
    }
}
void pow(int pow_){
    for(auto it = arr.begin(); it != arr.end(); it++){
        int before = *it;
        int after = before * pow_;
        *it = after;
    }
    show_all();
}

int main(){
    start();
    while(true){
        int sel = menu();
        if(sel == 6) break;
        if(sel == 1){
            int max = max_value();
            cout << "가장 큰 값 : " << max << endl;
        }
        else if(sel == 2){
            double avg = value_avg();
            cout << "평균 : " << avg << endl;
        }
        else if(sel == 3){
            cout << "삽입할 값 >> ";
            int in_;
            cin >> in_;
            insert(in_);
        }
        else if(sel == 4){
            cout << "삭제할 값 >> ";
            int del_;
            cin >> del_;
            del(del_);
        }
        else if(sel == 5){
            // 입력한 값만 배수 증가.
            cout << "몇 배로 증가 >> ";
            int pow_;
            cin >> pow_;
            pow(pow_);
        }
    }
    cout << "program exit...";
    return 0;
}