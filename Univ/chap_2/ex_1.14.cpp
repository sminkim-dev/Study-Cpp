/*짜장면 10인분, 짬뽕 20인분, 볶음밥 5인분으로 하루에 파는 량이 정해진 중식당이 있다.
모든 메뉴가 고갈되거나 없는 메뉴가 입력되면 프로그램이 종료된다.*/

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main(){

    const char* Menu[] = {"짜장면", "짬뽕", "볶음밥"};
    int remain[] = {10, 20 , 5};
    int r, cnt;
    r = 0;
    char ord[20];
    
    while(true){
        bool ck = false;
        cout << "오늘의 주문 가능량 : ";
        for(int i = 0; i < 3; i++){
            if(i < 2){
                cout << Menu[i] << " " << remain[i] << ", ";
            }else if(i == 2){
                cout << Menu[i] << " " << remain[i];
            }
            
        }
        cout << "\n주문 >> ";
        cin >> ord >> cnt;
        
        for(int i = 0; i < 3; i++){
            if(strcmp(ord,Menu[i]) == 0){
                if(remain[i] == 0){
                    cout << "주문 불가능. 재료 소진\n프로그램 종료";
                    ck = true;
                    break;
                }
                else if(remain[i] < cnt){
                    cout << remain[i] << "인분만 주문 가능합니다.\n";
                }
                
                else{
                    remain[i] -= cnt;
                }
            }
        }
        if(ck){
            break;
            return 0;
        }
    }
    system("pause");
}
//clear