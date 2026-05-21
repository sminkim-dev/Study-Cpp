#include <iostream>
using namespace std;

class Chart{
    private:
        int *data;
        int size;
        int count = 0;
    public:
        Chart(int size) : size(size){
            this->data = new int [size];
        }
        ~Chart(){delete []data;}
        void show(){
            cout << "차트 데이터 : ";
            for(int i = 0; i < count; i++){
                cout << this->data[i] << " ";
            }
            cout << endl;
        }
        int operator~(){
            int sum = 0;
            for(int i = 0; i < count; i++){
                sum += this->data[i];
            }
            return (sum / count);
        }
        Chart operator <<(int n){
            this->data[count++] += n;
            return *this;
        }
        bool operator !(){
            return (this->count == 0);
        }
};

int main(){
    Chart chart(100); // 100개의 정수가 저장가능한 차트 객체 생성
    if(!chart) cout << "차트가 비었습니다." << endl;

    int n;
    cout << "정수 4개 입력 >> ";
    for(int i = 0; i < 4; i++){
        cin >> n; // 정수 입력
        chart << n; // 차트에 입력 받은 정수 저장
    }
    int avg = ~chart; // 차트 데이터의 평균 값 리턴
    cout << "평균은 " << avg << endl;
    chart.show(); // 현재 저장된 차트 데이터 출력
    return 0;
}