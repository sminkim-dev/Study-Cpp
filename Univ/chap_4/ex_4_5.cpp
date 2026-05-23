#include <iostream>

using namespace std;

class Container{
    private:
        int* p;
        int size;
    public:
        Container(int size){
            this->size = size;
            this->p = new int[size];
        }
        ~Container(){}
        void read(){
            cout << "정수 10개 입력 >> ";
            for(int i = 0; i < size; i++){
                cin >> p[i];
            }
        }
        void write(){
            for(int i = 0 ; i < size; i ++){
                cout << p[i] << " ";
            }
            cout << "\n";
        }
        void rotate(){
            // 1 2 3 4 5 6 7 8 9 10  -->  10 1 2 3 4 5 6 7 8 9
            int lastTemp = p[size - 1];
            for(int i = size - 1; i > 0; i--){
                p[i] = p[i - 1]; // 8번이 9번 자리로 한 칸 옆으로 간다고 생각할 것.
            }
            p[0] = lastTemp;
        }
        double avg(){
            double sum = 0;
            for(int i = 0; i < size; i++){
                sum += p[i];
            }
            return sum / size;
        }
};
int main(){
    Container c(10);
    c.read();
    c.write();
    c.rotate();
    c.write();
    cout << "평균은 " << c.avg() << endl;

    cin.clear();
    cin.ignore(100,'\n');
    cin.get();
}
