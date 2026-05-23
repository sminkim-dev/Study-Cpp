#include <iostream>
#include <string>

using namespace std;

class Coffee{
    private:
        int Ingredient[4]; //coffee[0] sugar[1] milk[2] water[3]
    public:
        Coffee(int c = 10, int s = 0, int m = 0, int w = 0):Ingredient{c,s,m,w} {};

        void show(){
            char const* label[] = {"coffee", "sugar", "milk", "water"};
            for(int i = 0; i < 4; i++){
                cout << label[i] << " " << string(Ingredient[i],'*') << "\n";
            }
        }
};

int main(){
    Coffee espresso;
    Coffee mySweet(10,5,2,4);

    espresso.show();
    mySweet.show();
    cin.get();
}