#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Book{
    string title;
    int price;
    public:
        Book(){
            this->title = "";
            this->price = 0;
        }
        void set(string title, int price){
            this->title = title;
            this->price = price;
        }

        string getTitile(){
            return this->title;
        }
        int getPrice(){
            return this->price;
        }
};

class Library{
    string library_name;
    Book *p;
    int size;
    int nextIdx = 0;
    public:
        Library(string name, int size){
            this->library_name = name;
            this->size = size;
            p = new Book[size];
        }
        ~Library(){delete[] p;}
        void add(string name, int price){
            p[nextIdx++].set(name,price);
        }
        Book* mostExpensive(){
            int max = numeric_limits<int>::min();
            int index = 0;
            for(int i = 0; i < nextIdx; i++){
                if(p[i].getPrice() != 0){
                    if(max < p[i].getPrice()){
                        max = p[i].getPrice();
                        index = i;
                    }
                }
            }
            return &p[index];
        }
        void show(){
            if(p[0].getTitile() == "" && p[0].getPrice() == 0){
                cout << "저장된 값이 없습니다." << endl;
            }
            else{
                int count = 0;
                for(int i = 0; i < nextIdx; i++){
                    if(p[i].getTitile() != "" && p[i].getPrice() != 0){
                        count ++;
                    }
                }
                cout << this->library_name << "에 입고된 책은 다음 " << count <<  "권 입니다." << endl;
                for(int i = 0; i < nextIdx; i++){
                    if(p[i].getTitile() != "" && p[i].getPrice() != 0){
                        cout << "[" << p[i].getTitile() << "]     ";
                    }
                }
                cout << "\n";
            }
        }

};

int main(){
    Library *lib = new Library("한국도서관", 10);
    lib->add("명품 C++", 30000);
    lib->add("라즈베리파이", 34000);
    lib->add("HTML5", 33000);
    lib->show();

    Book *b = lib->mostExpensive();
    cout << "가장 비싼 책 제목 : " << b->getTitile() << " 가격 : " << b->getPrice() << endl; 
    delete lib;
    cin.get();
}