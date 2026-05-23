#include <iostream>
#include <string>

using namespace std;

double getAvg(double *temperature, int size){
    double sum = 0; 
    for(int i = 0; i < size; i++){
        sum += temperature[i];
    }
    return sum / size;
}

int main(){
    int size = 5;
    double* temperature = new double[size];
    cout << "온도 5개 입력 >> ";
    for(int i = 0; i < size; i++){
        cin >> temperature[i];
    }
    double result = getAvg(temperature , size);
    printf("평균은 %.2f", result);

    delete []temperature;
    cin.clear();
    cin.ignore(100, '\n');
    cin.get();
}