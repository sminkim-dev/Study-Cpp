#include <iostream>
#include <string>

using namespace std;

class Account{
    private:
        string Owner;
        int money;
    public:
        Account(string name){
            Owner = name;
            money = 0;
        }
        int deposit(int D){
            money += D;
            return money;
        }
        int withDraw(int w){
            if(w <= money){
                money -= w;
                return w;
            }
            else if(w > money){//with 8000 m 5000
                int temp = money;
                money = 0;
                return temp;
            }
            //int actulbalence = if(money > w) ? w : money; money -= actualbalence; return actualbalence;
        }
        int inquiry(){return money;}
        string const getOwner(){return Owner;}
};

int main(){
    Account a("황수희");
    a.deposit(20000);
    cout << a.getOwner() << " 잔액은 " << a.inquiry() << endl;
    int money = a.withDraw(15000);
    cout << money << "원 출금, ";
    cout << a.getOwner() << " 잔액은 " << a.inquiry() << endl;
    money = a.withDraw(8000);
    cout << money << "원 출금,";
    cout << a.getOwner() << " 잔액은 " << a.inquiry() << endl;
    
    cin.get();
}