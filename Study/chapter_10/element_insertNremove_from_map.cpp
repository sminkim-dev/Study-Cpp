#include <iostream>
#include <map>
#include <string>
using namespace std;

class Item{
    // 1개의 상품 정보
    public:
        int price; // 상품 가격
        int count; // 재고 수량

        Item(int price = 0, int count = 0):price(price), count(count){}
};
int main(){
    map<string, Item> stock;
    string name; // 상품명
    int price = 0, count = 0, removedCount = 0; // 상품 가격과 개수, 삭제된 개수

    while(true){
        cout << "상품 입고 : 1, 검색 : 2, 삭제 : 3, 종료 : 4 >> ";
        int menu;
        cin >> menu;
        switch (menu)
        {
        case 1:
            cout << "상품명, 가격, 개수 입력 >> ";
            cin >> name >> price >> count;
            stock.insert(make_pair(name, Item(price, count))); // insert
            break;
        case 2:
            cout << "상품명 입력 >> ";
            cin >> name;
            if(stock.find(name) == stock.end()) cout << "'" <<name << "' 해당 상품 없음" << endl; // 상품이 없는 경우
            else{
                Item item = stock[name]; // search
                cout << "가격 " << item.price << ", 재고 " << item.count << "개" << endl;
            }
            break;
        case 3:
            // remove
            cout << "상품명 입력 >> ";
            cin >> name;
            removedCount = stock.erase(name); // 상품 삭제
            if(removedCount == 0) cout << "'" << name << "' 해당 상품 없음" << endl; // 상품이 없는 경우
            else{
                cout << name << "삭제 완료" << endl;
            }
            break;
        case 4:
            cout << "종료합니다...." << endl;
            return 0;
        default:
            cout << "menu에서 번호를 골라주십시오..." << endl;
            continue;
        } // end of switch
    } // end of while
}