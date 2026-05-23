#include <iostream>

using namespace std;

class Polygon{
    int size = 0;
    int *xlist, *ylist;
    public:
        Polygon(int size){
            this->size=size;
            this->xlist = new int[size];
            this->ylist = new int[size];
        }
        ~Polygon(){
            delete [] xlist;
            delete [] ylist;
        }
        void read(){
            cout << "아래에 x, y 값으로 " << size << "개의 점을 입력하세요." << endl;
            for (int i = 0; i < size; i++) cin >> xlist[i] >> ylist[i];
        }
        int getSize(){return size;}
        bool get(int n, int &x, int &y) {
            if (n < 1 || n > size) return false;
            x = xlist[n - 1]; // 1부터 시작하므로 인덱스는 n-1
            y = ylist[n - 1];
            return true;
        }
};

int main(){
    Polygon poly(6);
    poly.read();
    int n = 3 , x , y;
    bool res = poly.get(n,x,y);
    if(res == true){
        cout << n << "n번째 점은 " << "(" << x << "," << y << ")" << endl;
    }
    else{
        cout << n << "번째 점은 없습니다." << endl;
    }

    cin.clear();
    cin.ignore(100,'\n');
    cin.get();
}