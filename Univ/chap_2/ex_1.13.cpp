/*커피를 주문하는 간단한 c++ 프로그램 작성할 것, 커피 종류는 "에스프레소" , '아메리카노', '카푸치노'의 3가지이며, 
가격은 각각 3000원, 3500원, 4000원이다. 하루에 30000원이상 벌게 되면 카페를 닫는다.*/
#include <iostream>

using namespace std;

int main(){

    string menu[] = {"에스프레소", "아메리카노", "카푸치노"};
    int price[] = {3000,3500,4000};
    int cnt;
    int sum = 0;
    int result = 0;
    string ord;
    
    cout << "에스프레소 3000원, 아메리카노 3500원 ,카푸치노 4000원입니다.\n";

    while(true){
        bool ck = false;
        cout << "주문 >> ";
        cin >> ord >> cnt;
        cout << "\n";
        for(int i = 0; i < 3; i++){
            if(ord == menu[i]){
                result = cnt * price[i];
                cout << result << "원입니다. 맛있게 드세요.\n";
                ck = true;
                sum += result;
            }
        }
        if(!ck){
                cout << "Error, No exist at list.\n";
            }
        if(sum >= 30000){
            cout << "오늘" << sum << "원을 판매하여 카페를 닫습니다. 내일 오픈합니다.\n";
            break;
        }
    }
    system("pause");
}
//clear