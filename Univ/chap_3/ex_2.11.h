#include <iostream>
#include <string>

using namespace std;

class Oval{
    private:
        int width, height;
    public:
        Oval(int x = 1, int y = 1):width(x), height(y){}
        /*
        Oval():width(1), height(1){}
        Oval(int x, int y):width(x), height(y){}
        문제에서는 생성자를 2개로 나누라고 되있는데 내가 한 것처럼 해도 3가지 조건을 충족함.
        디폴트 매개변수. 인수가 없을 경우 자동으로 1을 넣음.
        a -> 1, 1
        a(4) -> 4, 1
        a(10, 2) -> 10, 2
        */
        //소멸자는 모르겠음. 일단 대기

        ~Oval(){
            cout << "Oval 소멸 : " << width << "x" << height << endl;
            cout.flush();
        }
        void set(int x, int h){
            width = x;
            height = h;
        }
        void show(){
            cout << "Oval : width = " << width << ", " << "height = " << height << "\n";
        }
        double area(){
            double oval;
            double Pi = 3.14;
            oval = Pi*((width/2.0)*(height/2.0));
            return oval;
        }
        int getWidth(){return width;}
        int getHeight(){return height;}
};