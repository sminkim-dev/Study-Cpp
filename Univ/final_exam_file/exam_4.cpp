// 핵심, 중간에서도 이미 한 번 나옴. 깊은 복사 문제 const char * <- char *
#include <iostream>
#include <cstring>
using namespace std;

class Student{
    const char *name;
    public:
        Student(char * n){
            char *temp = new char[strlen(n) + 1];
            strcpy(temp , n);
            this->name = temp;
        }
        void setName(char * n){
            delete [] name;
            
            char *temp = new char[strlen(n) + 1];
            strcpy(temp, n);
            this->name = temp;
        }
        const char* getName(){return this->name;}
};
int main(){
    Student s("Kim");
    cout << s.getName() << endl;
    s.setName("gim");
    cout << s.getName() << endl;
}