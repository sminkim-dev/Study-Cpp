#include <iostream>

using namespace std;

int max(int price[], int size){
    int max = 0;
    for(int i = 0; i < size; i++){
        if(max < price[i]){
            max = price[i];
        }
    }
    return max;
}
int min(int price[], int size){
    int min = 1000000000;
    for(int i = 0; i < size; i++){
        if(min > price[i]){
            min = price[i];
        }
    }
    return min;
}

int main(){
    int size;
    int* price = new int[size];
    cout << "구입할 물품의 개수 >> ";
    cin >> size;
    cout << "물품 " << size << "개의 가격 입력 >> ";
    for(int i = 0; i < size; i++){
        cin >> price[i];
    }
    cout << "제일 싼 가격은 >> " << min(price,size) << endl;
    cout << "제일 비싼 가격은 >> " << max(price, size) << endl;

    cin.clear();
    cin.ignore(100, '\n');
    cin.get();;
}