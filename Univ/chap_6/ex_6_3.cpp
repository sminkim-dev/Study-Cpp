#include <iostream>

using namespace std;

bool equal(string x, string y, int n = 0, string z = ""){
    if(n == 0){
        return x==y;
    }
    if(x.substr(0,n) != y.substr(0,n)){
        return false;
    }
    if(z != ""){
        if(x.substr(0,n) != z.substr(0,n)){
            return false;
        }
    }
    return true;
}

int main(){
    string x = "Prof. Hwang";
    string y = "Prof. Kim";
    string z = "Prof. Lee";
    if(equal(x,y)) cout << "같음" << endl;
    if(equal(x,y,3)) cout << "앞 3글자 같음" << endl;
    if(equal(x,z,5)) cout << "앞 5글자 같음 " << endl;
    cin.get();
}