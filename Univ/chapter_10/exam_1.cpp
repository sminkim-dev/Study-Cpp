#include <iostream>
#include <iterator>
#include <limits>
using namespace std;

template <class T>
T biggest(T *x, int a){
    T max = INT_MIN;
    for(int i =0; i < a; i++){
        if(max < x[i]){
            max = x[i];
        }
    }
    return max;
}

int main(){
    int x[] = {1, 10, 100, 5, 4};
    cout << biggest(x, 5) << endl;

    double y[] = {3.5, 20.7, 6.2, 5.4};
    cout << biggest(y, 4) << endl;
}