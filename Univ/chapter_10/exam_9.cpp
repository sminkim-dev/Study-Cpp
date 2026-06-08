#include <iostream>
#include <map>
#include <iterator>
#include <string>
using namespace std;

map<string, int> menu = {
    {"짜장면", 5000},
    {"짬뽕", 6000},
    {"볶음밥", 8000},
    {"탕수육", 25000}
};
int cal_price(string menu_, int nums){
    int price = 0;
    bool none_menu = false;
    for(auto it = menu.begin(); it != menu.end(); it++){
        if(it->first == menu_){
            price += (it->second * nums);
            none_menu = true;
            break;
        }
    }
    if(none_menu == true){
        return price;
    }
    else{
        return -1;
    }
    
}
int main(){
    while(true){
        string menu_;
        int nums;
        cout << "주문 >> "; // ex 짜장면 2
        cin >> menu_;
        if(menu_ == "그만")break;
        cin >> nums;
        if(nums == 0){
            cout << "0개는 주문 불가능..1개 이상 입력." << endl;
            continue;
        }
        int price = cal_price(menu_, nums);
        if(price == -1){
            cout << "메뉴에 없는 이름입니다." << endl;
        }
        else{
            cout << "가격은 " << price << "원입니다." << endl;
        }
    }
    cout << "program exit...";
    return 0;
}