#include <iostream>
#include <map>
#include <iterator>
#include <string>
using namespace std;

class Book;
map<string, Book> bookMap;

class Book{
    public:
        string writer, year;
        Book(string w="", string y="") : writer(w), year(y){}
        void set(string w , string y){
            this->writer=w;
            this->year=y;
        }
};

string menu(){
    cout << "삽입 , 검색 , 종료 중에 입력 >> ";
    string in_;
    cin >> in_;
    return in_;
}

void insert(){
    cout << "도서명;저자;연도 식으로 입력 >> ";
    cin.get();
    string text;
    getline(cin, text);
    int find_f = text.find(";");
    string title = text.substr(0,find_f);
    string other = text.substr(find_f + 1);
    int find_s = other.find(";");
    string writer = other.substr(0,find_s);
    string year = other.substr(find_s + 1);
    bookMap.insert(make_pair(title, Book(writer, year)));
}
void search(){
    cout << "도서명 >> ";
    cin.get();
    string title;
    getline(cin, title);

    bool find = false;
    for(auto it = bookMap.begin(); it != bookMap.end(); it++){
        if(title == it->first){
            find = true;
            break;
        }
    }
    if(find == false){
        cout << title << "은 없는 책입니다." << endl;
    }
    else{
        cout << "[";
        for(auto it = bookMap.begin(); it != bookMap.end(); it++){
            if(title == it->first){
                cout << it->first << "," << it->second.writer << "," << it->second.year << "]";
                break;
            }
        }
        cout << endl;
    }
}
int main(){
    cout << "*** 도서 관리 프로그램 책 벌레를 시작합니다. ***" << endl;
    while(true){
        string in_ = menu();
        if(in_ == "종료")break;
        if(in_ == "삽입"){
            insert();
        }
        else if(in_ == "검색"){
            search();
        }
    }
}