#include <iostream>
#include <string>

using namespace std;

class Storage{
    private:
        double temperature[10];
        int count;
    public:
        Storage():count(0){}
        
        void put(double N){
            if(count < 10){
                temperature[count] = N;
                count++;
            }
        }
        void dump(){
            for(int i = 0; i < count; i++){
                cout << temperature[i] << " ";
            }
            cout << "\n";
        }
        double getAvg(){
            double sum = 0.0;
            for(int i = 0; i < count; i++){
                sum += temperature[i];
            }
            return sum / count;
        }
};

int main() {
    Storage a;
    a.put(36.7);
    a.put(36.9);
    a.put(36.4);
    a.dump();
    cout << "평균 체온은 " << a.getAvg() << "입니다." << endl;
    cin.get();
}