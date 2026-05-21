#include <iostream>
using namespace std;

class Matrix{
private:
    int matrix [4] = {0 , 0 , 0 , 0};
public:
    Matrix(int matrix []){
        for(int i = 0; i < 4; i++){
            this->matrix[i] = matrix[i];
        }
    }
    Matrix(int a = 0, int b = 0, int c = 0, int d = 0){
        this->matrix[0] = a;
        this->matrix[1] = b;
        this->matrix[2] = c;
        this->matrix[3] = d;
    }
    void show(){
        cout << "Matrix : { ";
        for(int i = 0; i < 4; i++){
            cout << this->matrix[i] << " ";
        }
        cout << "}" << endl;
    }
    Matrix& operator=(Matrix a){
        for(int i = 0; i < 4; i++){
            this->matrix[i] = a.matrix[i];
        }
        return *this;
    }
    Matrix operator+(const Matrix& b){
        int tmp[4];
        for(int i = 0; i < 4; i++){
            tmp[i] = this->matrix[i] + b.matrix[i];
        }
        return Matrix(tmp[0], tmp[1], tmp[2], tmp[3]);
    }
    Matrix& operator+=(const Matrix &b){
        for(int i = 0; i < 4; i++){
            this->matrix[i] += b.matrix[i];
        }
        return *this;
    }
    bool operator==(const Matrix &c){
        bool check = false;
        for(int i = 0; i < 4; i++){
            if(this->matrix[i] != c.matrix[i]){
                check = true;
                break;
            }
        }
        if(check == true)return false;
        else return true;
    }
};

int main(){
    Matrix a(1,2,3,4) , b(2,3,4,5) , c;
    c = a + b;
    a += b;
    a.show(); b.show(); c.show();
    if(a == c){
        cout << "a와 c는 같습니다." << endl;
    }
    return 0;
}