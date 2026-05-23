#include <iostream>
#include <string>

using namespace std;

class Chart{
    private:
        int data[3];
        string color[3] = {"빨강", "파랑", "노랑"};
        string title;
        //아래 서로 다른 함수에서 같은 변수를 사용하는 경우가 있어서 전역으로 사용하려고 위로 뺴둠.
        double avg;
        double value[3];
    public:
    
        Chart(string Title):title(Title){};
        ~Chart(){
            cout << "차트 데이터는 저장되지 않고 사라집니다.\n";
        }
        int getNumberOfColors(){return 3;}//왜 이렇게 사용하는지는 모르겠는데, 문제에서는 함수 호출하라고 되어있음.

        string getColor(int N){
            return color[N];
        }
        void add(int x, int y){
            value[x] += y;
            avg += y;
        }
        void drow(){
            //점유율 현재 수 / 전체 수 * 100
            cout << title << "*****************\n";
            for(int i = 0; i < getNumberOfColors(); i++){
                cout << color[i] << ": " << (value[i] / avg) * 100 << "%\n";
            }
            cout << "***********************\n";
        }
};

int main(){
    {
        Chart chart("색 선호도 조사 차트");
        for(int i = 0; i < chart.getNumberOfColors(); i++){
            cout << chart.getColor(i) << "이 좋은 학생>>";
            int count;
            cin >> count;
            chart.add(i, count);
        }
        chart.drow();
    }
    system("pause");
    return 0;
    
}