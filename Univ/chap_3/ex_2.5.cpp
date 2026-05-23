#include <iostream>
#include <string>

using namespace std;

class CoffeeMachine{
    private:
        int waste[3];
    public:
        CoffeeMachine(int c, int w, int s): waste{c, w, s} {}

        void drinkEspresoo(){
            waste[0] -= 1;
            waste[1] -= 1;
        }
        void drinkAmericano(){
            waste[0] -= 1;
            waste[1] -= 2;
        }
        void drinkSugarCoffee(){
            waste[0] -= 1;
            waste[1] -= 2;
            waste[2] -= 1;
        }
        void fill(){
            for(int i = 0; i < 3; i++){
                waste[i] = 10;
            }
        }
        void show(){
            cout << "[머신 상태] ";
            string label[] = {"커피", "물", "설탕"};
            for(int i = 0; i < 3; i++){
                cout << label[i] << ":" << waste[i] << "\t"; 
            }
            cout << "\n";
        }

};

int main(){
    CoffeeMachine java(5, 10, 6);
    java.drinkEspresoo();
    java.show();
    java.drinkAmericano();
    java.show();
    java.drinkSugarCoffee();
    java.show();
    java.fill();
    java.show();

    cin.get();
}