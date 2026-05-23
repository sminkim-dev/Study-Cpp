#include <iostream>
#include <string>

using namespace std;

class Coffee{
    private:
        int coffee, sugar, milk, water;
    public:
        Coffee():coffee(10), sugar(0), milk(0), water(0){}
        Coffee(int c, int s, int m, int w):coffee(c), sugar(s), milk(m), water(w){}

        void show(){
            cout << "coffee ";
            for(int i = 0; i < coffee; i++){
                cout << "*";
            }
            cout << "\nsugar ";
            for(int i = 0; i < sugar; i++){
                cout << "*";
            }
            cout << "\nmilk ";
            for(int i = 0; i < milk; i++){
                cout << "*";
            }
            cout <<"\nwater ";
            for(int i = 0; i < water; i++){
                cout << "*";
            }
        }

};
int main(){
    Coffee espresso;
    Coffee americano(5,0,0,10);
    Coffee cappuchino(5,1,5,2);
    Coffee mySweet(3,7,5,5);

    espresso.show();
    cout << endl;
    mySweet.show();

    system("pause");
}