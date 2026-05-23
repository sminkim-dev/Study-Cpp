#include <iostream>

using namespace std;

class Star{
    private:
        int row = 4;
    public:
        Star(){}
        void show(){
            for(int i = 0; i < row; i++){
                for(int b= 0; b < i + 1; b++){
                    cout << "*";
                }
                cout << "\n";
            }
        }
};

int main(){
    Star star{};
    star.show();
    system("pause");
    return 0;
}