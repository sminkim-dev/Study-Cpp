#include <iostream>
using namespace std;

class Wallet{
private:
    string name;
    int money;
public:
    Wallet(string name = "", int money = 0) : name(name), money(money) {}
    void show(){
        cout << this->name << "지갑에 " << this->money << "원 있어요." << endl;
    }
    Wallet& operator+=(int m){
        this->money += m;
        return *this;
    }
    Wallet& operator-=(int m){
        this->money -= m;
        return *this;
    }
    Wallet& operator=(const Wallet& a){
        this->money = a.money;
        return *this;
    }
    friend Wallet operator+(const Wallet& a, const Wallet& b);
    friend Wallet operator+(const Wallet& a, int m);
    friend Wallet operator+(int n, const Wallet& b);
};
Wallet operator+(int n, const Wallet& b){
    Wallet tmp;
    tmp.money = n + b.money;
    return tmp;
}
Wallet operator+(const Wallet& a, const Wallet& b){
    Wallet tmp;
    tmp.money = a.money + b.money;
    return tmp;
}
Wallet operator+(const Wallet&a, int m){
    Wallet tmp;
    tmp.money = a.money + m;
    return tmp;
}
int main(){
    Wallet a("옥지윤", 2000), b("성주연", 100), c("박채원"); // 박채원 지갑은 0원
    a += 1000; a.show();
    a -= 500; a.show();
    b = a + b + 100;
    b.show();
    c = 500 + b;
    c.show();
    return 0;
}