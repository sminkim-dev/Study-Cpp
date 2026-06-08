#include <iostream>
#include <map>
#include <iterator>
#include <sstream>
#include <climits>
using namespace std;

map<string, int> vote;
void elect_(){
    int elect = INT_MIN;
    string name = "";
    for(auto it = vote.begin(); it != vote.end(); it++){
        if(it->second > elect){
            int temp = it->second;
            elect = temp;
            string temp_ = it ->first;
            name = temp_;
        }
    }
    cout << name << "님이 회장으로 선출되었습니다." << endl;
}
void result(){
    for(auto it = vote.begin(); it != vote.end(); it++){
        cout << it->first << ":" << it->second << " , ";
    }
    cout << endl;
    elect_();
}
void insert_(){
    cout << "이름 3개 >> ";
    string text;
    getline(cin, text);

    stringstream ss(text);
    string tokens;
    while(ss >> tokens){
        if(tokens == "그만"){
            result();
            exit(0);
        }
        vote[tokens]++;
    }
}
// vote , 한 번에 3명 투표
int main(){
    while(true){
        insert_();
    }
}