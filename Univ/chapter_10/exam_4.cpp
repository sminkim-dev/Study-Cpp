#include <iostream>
using namespace std;

template <class T>
bool add(T *array, int size, int index, T save){
    if(index >= size || index < 0) return false;
    else{
        array[index] = save;
        return true;
    }
}
template <class T>
void print(T *array, int index){
    for(int i = 0; i < index; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(){
    int intArray[10] = {1,2,3,4,5};
    bool ret = add(intArray, 10, 5, 20); //intArray 크기가 10이고, 원소 5(6번째)에 20 저장

    if(ret == true) print(intArray,6);
    else cout << "삽입 실패" << endl;

    char charArray[6] = {'c','+','+'};
    ret = add(charArray,6,3,'!'); // charArray 크기가 6이고, 원소 3(4번째)에 '!'문자 저장

    if(ret == true)print(charArray, 4);
    else cout << "삽입 실패" << endl;
}