#include <iostream>
#include <vector>
#include <iterator>
#include <limits>
#include <climits>
using namespace std;


vector<int> arr;
int max_value(){
    int max = INT_MIN;
    for(auto it = arr.begin(); it != arr.end(); it++){
        if(max < *it){
            int temp = *it;
            max = temp;

        }
    }
    return max;
}
void show_all(){
    cout << "[";
    for(auto it = arr.begin(); it != arr.end(); it++){
        cout << *it << " ";
    }
    cout << "] , 가장 큰 수 " << max_value() << endl;
}
int menu(){
    cout << "정수를 입력, 0이면 종료 >> ";
    int in_;
    cin >> in_;
    return in_;
}
bool dupliment(int nums){
    for(auto it = arr.begin(); it != arr.end(); it++){
        if(*it == nums){
            return false;
        }
    }
    return true;
}
void insert(int nums){
    if(dupliment(nums)){
        arr.push_back(nums);
        show_all();
        return;
    }
    else{
        cout << "이미 존재함." << endl;
        return;
    }
}
int main(){
    while(true){
        int sel = menu();
        if(sel == 0) break;
        insert(sel);
    }
    cout << "program exit ..." << endl;
    return 0;
}