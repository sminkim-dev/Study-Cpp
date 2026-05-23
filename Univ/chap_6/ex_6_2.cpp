#include <iostream>

using namespace std;

void printMatrix(int x = 2, int y = 2, string symbol = "*"){
    for(int i = 0; i < x; i++){
        for(int b = 0; b < y; b++){
            cout << symbol;
        }
        cout << "\n";
    }
}
int main(){
    printMatrix();
    printMatrix(2,5,"a");
    printMatrix(1,10);
    
    cin.get();
}