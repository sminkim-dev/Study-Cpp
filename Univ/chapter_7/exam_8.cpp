#include <iostream>
using namespace std;

class Matrix{
private:
    int matrix[4] = {0,0,0,0};
public:
    Matrix(int a = 0, int b = 0, int c = 0, int d = 0){
        this->matrix[0] = a;
        this->matrix[1] = b;
        this->matrix[2] = c;
        this->matrix[3] = d;
    }
    Matrix(int m[]){
        for(int i = 0; i < 4; i++){
            this->matrix[i] = m[i];
        }
    }
    void show(){
        cout << "Matrix : { ";
        for(int i = 0; i < 4; i++){
            cout << this->matrix[i] << " ";
        }
        cout << "}" << endl;
    }
    // void operator >>(int x[]){
    //     for(int i = 0; i < 4; i++){
    //         x[i] = this->matrix[i];
    //     }
    // }
    // void operator <<(int y[]){
    //     for(int i = 0; i < 4; i++){
    //         this->matrix[i] = y[i];
    //     }
    // }
    friend void operator >>(Matrix &a, int x[]);
    friend void operator <<(Matrix &b, int y[]);
};
void operator >>(Matrix &a, int x[]){
    for(int i = 0; i < 4; i++){
        x[i] = a.matrix[i];
    }
}
void operator <<(Matrix &b, int y[]){
    for(int i = 0; i < 4; i++){
        b.matrix[i] = y[i];
    }
}
int main(){
    Matrix a(4,3,2,1) , b;
    int x[4] , y[4] = {1,2,3,4};
    a >> x;
    b << y;
    for(int i = 0; i < 4; i++){
        cout << x[i] << " ";
    }
    cout << endl;
    b.show();
    return 0;
}