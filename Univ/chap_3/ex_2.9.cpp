#include <iostream>
#include <string>

using namespace std;

class Coffee{
    private:
        int list[3];
        int price[3] = {3000, 3500, 4000};
        int sum;
        string name[3] = {"에스프레소", "아메리카노", "카푸치노"};
    public:
        string N;
        int n, result;
        void cal(){
            cout << "에스프레소 3000원, 아메리카노 3500원, 카푸치노 4000원입니다.\n";
            while(true){
                cout << "주문 >> ";
                cin >> N >> n;
                for(int i = 0; i < 3; i++){
                    if(name[i] == N){
                        sum = price[i] * n;
                        result += sum;
                    }
                }
                cout << sum << "원입니다. 맛있게 드세요.\n";
                if(result > 30000){
                    cout << "오늘 " << result << "원을 판매하여 카페를 닫습니다.\n";
                    break;
                } 
            }
        }
};

int main(){
    Coffee a;
    a.cal();
    cin.clear();
    cin.ignore(100,'\n');
    cin.get();
}