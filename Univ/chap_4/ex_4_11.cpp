#include <iostream>

using namespace std;

class Container{
    int size;
    public:
        Container(){size = 10;}
        void fill(int n){
            this->size = n;
        }
        bool consume(int n){
            if(size < n) return false;
            this->size -= n;
            return true;
        }
        int getSize(){return size;}
};

class CoffeeVendingMachine{
    Container tong[3]; // 0 커피, 1 물, 2 설탕통
    void fill(){
        tong[0].fill(10);
        tong[1].fill(10);
        tong[2].fill(10);
    }
    void getEspresso(){
        if(tong[0].getSize() >= 1 && tong[1].getSize() >= 1){
            tong[0].consume(1);
            tong[1].consume(1);
        }
        else cout << "원료가 부족합니다." << endl;
    }
    void getAmericano(){
        if(tong[0].getSize() >= 1 && tong[1].getSize() >= 2){
            tong[0].consume(1);
            tong[1].consume(2);
        }
        else cout << "원료가 부족합니다." << endl;
    }
    void getSugarCoffee(){
        if(tong[0].getSize() >= 1 && tong[1].getSize() >= 2 && tong[2].getSize() >= 1){
            tong[0].consume(1);
            tong[1].consume(2);
            tong[2].consume(1);
        }
        else cout << "원료가 부족합니다." << endl;
    }
    void show(){
        cout << "커피 : " << tong[0].getSize() << ", 물 : " << tong[1].getSize() << ", 설탕 : " << tong[2].getSize() << endl;
    }
    public:
        void run(){
            cout << "***** 커피 자판기를 작동합니다. *****";
            while(true){
                int menu;
                cout << "메뉴를 눌러주세요(1. 에스프레소, 2. 아메리카노, 3. 설탕커피, 4. 잔량보기, 5. 채우기) >> ";
                cin >> menu;
                switch (menu)
                {
                case 1:getEspresso();
                    break;
                case 2:getAmericano();
                    break;
                case 3:getSugarCoffee();
                    break;
                case 4:show();
                    break;
                case 5:fill();
                    break;
                case 6:cout << "자판기를 종료합니다." << endl; return;
                default:
                    cout << "잘못된 입력입니다." << endl;
                    break;
                }
            }
        }
};

int main(){
    CoffeeVendingMachine cvm;
    cvm.run();

    cin.get();
}