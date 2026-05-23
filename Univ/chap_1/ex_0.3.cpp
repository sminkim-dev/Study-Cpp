#include <iostream>

using namespace std;

class Cal{
    private:
        int x, y, result;
    public:
    Cal(int a, int b):x(15),y(4){}

    int getCal(){
        result = x % y;
        return result;
    }
    void show(){
        cout << x << "를 " << y << "로 나눈 나머지는 " << result << "입니다." << endl;
    }
};

int main(){
    Cal A(15,4);
    A.getCal();
    A.show();
    system("pause");
    return 0;
}