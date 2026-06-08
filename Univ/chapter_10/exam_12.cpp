#include <iostream>
#include <vector>
#include <iterator>
#include <string>
using namespace std;


class Moving;
vector<Moving> v;

class Moving{
    public:
    string location;
    int distance;
    Moving(string l, int d){
        this->location = l;
        this->distance = d;
    }
    void set(string l, int d){
        this->location = l;
        this->distance = d;
    }
};
void result(){
    int total_dis = 0;
    for(auto it = v.begin(); it != v.end(); it++){
        if(it->location == "우리집"){
            cout << it->location << ":" << it->distance << "km";
            total_dis += it->distance;
        }
        else{
            cout << it->location << ":" << it->distance << "km -> "; 
            total_dis += it->distance;
        }
    }
    cout << endl;
    cout << "총 이동 거리 : " << total_dis << "km" << endl;
}

void logic(){
    while(true){
        cout << "목적지와 이동거리를 입력 >> ";
        string text;
        getline(cin, text);
        int find = text.find(" ");
        string loc = text.substr(0, find);
        int dis = stoi(text.substr(find + 1));
        Moving m(loc, dis);
        v.push_back(m);        
        //v.push_back(Moving(loc, dis));
        //v.emplace_back(loc, dis); // 일반적으로 벡터에 객체를 넣는 상황에서는 이걸 더 많이 사용함. // 객체를 벡터 안에서 직접 생성함. // 벡터 내부 메모리에서 생성. 이동도 복사도 없음.
        if(loc == "우리집"){
            result();
            break;
        }
    }
}

int main(){
    logic();
    return 0;
}