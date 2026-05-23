#include <iostream>
#include <string>
using namespace std;

class Pipe{
    private:
        int data[10] = {0};
        int index;
    public:
        Pipe() {index = 0;}
        
        int arrive(int n){
            if(index < 10){
                data[index] = n;
                index++;
                return -1;
            }
            else{
                int first = data[0];
                
                for(int i = 0; i < 9; i++){
                    data[i] = data[i+1];
                }
                data[9] = n;
                return first;
            }
        };
        int shift(){
            int first = data[0];
            for(int i = 0; i < 9; i++){
                data[i] = data[i+1];
            }
            data[9] = 0;
            //data가 하나 줄었으니 인덱스도 줄어야함.
            //if(index > 0) index--; 0에 대한 생각을 좀 더해봐야 할 듯, 일단 교수님께 물어본 결과, 문제도 애매하긴 했지만 일단 문제를 따라가라. 나대로 할거면 문제를 출제하라고 하더라.
            return first;
        };
        void show(){
            cout << "파이프 내부 [";
            for(int i = 0; i < 10; i++){
                cout << data[i] << " ";
            }
            cout << "]\n";
        };
};

int main(){
    Pipe pipe;
    for(int i = 0; i < 6; i++){
        pipe.arrive(i);
    }
    pipe.show();
    for(int i = 6; i < 12; i++){
        pipe.arrive(i);
    }
    pipe.show();
    int front = pipe.shift();
    cout << "shift()로 제거된 맨 앞 데이터 : " << front << endl;
    pipe.show();
    front = pipe.arrive(50);

    cout << "arrive(50)로 제거된 맨 앞 데이터 : " << front << endl;
    pipe.show();
    system("pause");
}
//물어봐야 할 부분 존재.
//shift()를 통해 앞으로 땡기면서 index--가 실행. 즉 10칸짜리 index가 9칸으로 바뀐다는 것, 즉, 10칸짜리 index에 여분의 공간이 있다라고 볼 수 있음.
//그러나 shift로 밀면서 생긴 "0"은 데이터로서의 가치가 있다고 보기엔 애매하며, index--로 인해 빈 공간이란 것이 입증이 가능.
//따라서 "0"은 데이터가 아닌 여분의 공간으로 보고 arrive(50)의 50이라는 데이터는 data[9]인 빈공간에 들어오면서 10칸이 꽉 차게 된다.
//class arrive함수를 보면 index가 초과하지 않을 경우 즉, 여분의 빈공간이 있을 경우에는 앞 데이터 data[0]을 밀면서 날리지 않기 때문에
//return -1 을 반환한다. 왜냐하면 날린 데이터가 존재하지 않기 때문에.
//위 내용이 맞다면 arrive(50) 함수 호출 후 결과 값은...
//파이프 내부 [3 4 5 6 7 8 9 10 11 50]과 제거된 맨 앞 데이터 : -1 이 출력되어야 한다. //개인적인 생각.
//허나 교재는 반환 데이터는 "3"이며, shift로 생긴 0을 데이터로 인식하며 data[0]에 있는 3을 밀면서 날리고 뒤에 50을 추가로 넣으면서.
//[4 5 6 7 8 9 10 11 0 50]이라는 출력 값을 보여준다. 이해가 가지 않는 것은. index 변수는 임의로 만든 것이 아니고 문제에서 도착하는 정수의 위치를 나타내는 배열의 인덱스라고 표현한점.
//index를 명시를 했음에도 0을 데이터로 받아들인 점은 이해가 가지 않는다고 할 수 있다.