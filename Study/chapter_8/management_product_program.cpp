#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 부모 클래스: Product
class Product {
protected:
    int id;
    string description;
    string producer;
    int price;

public:
    Product(int id, string desc, string prod, int price)
        : id(id), description(desc), producer(prod), price(price) {}

    // 다형성을 위해 가상 소멸자 선언
    virtual ~Product() {}

    // 동적 바인딩을 위한 가상 함수
    virtual void showInfo() {
        cout << "--- 상품ID : " << id << endl;
        cout << "상품설명 : " << description << endl;
        cout << "생산자 : " << producer << endl;
        cout << "가격 : " << price << endl;
    }
};

// 자식 클래스: Book
class Book : public Product {
protected:
    string isbn;
    string author;
    string title;

public:
    Book(int id, string desc, string prod, int price, string isbn, string author, string title)
        : Product(id, desc, prod, price), isbn(isbn), author(author), title(title) {}

    void showInfo() override {
        Product::showInfo();
        cout << "ISBN : " << isbn << endl;
        cout << "책제목 : " << title << endl;
        cout << "저자 : " << author << endl;
    }
};

// 자식 클래스: CompactDisc
class CompactDisc : public Product {
protected:
    string albumTitle;
    string artist;

public:
    CompactDisc(int id, string desc, string prod, int price, string album, string artist)
        : Product(id, desc, prod, price), albumTitle(album), artist(artist) {}

    void showInfo() override {
        Product::showInfo();
        cout << "앨범제목 : " << albumTitle << endl;
        cout << "가수 : " << artist << endl;
    }
};

// 손자 클래스: ConversationBook
class ConversationBook : public Book {
protected:
    string language;

public:
    ConversationBook(int id, string desc, string prod, int price, string isbn, string author, string title, string lang)
        : Book(id, desc, prod, price, isbn, author, title), language(lang) {}

    void showInfo() override {
        Book::showInfo();
        cout << "언어 : " << language << endl;
    }
};

int main() {
    Product* pList[100]; // 부모 포인터 배열 (업캐스팅 활용)
    int count = 0;

    cout << "***** 상품 관리 프로그램을 작동합니다 *****" << endl;

    while (count < 100) {
        int menu;
        cout << "상품 추가(1), 모든 상품 조회(2), 끝내기(3) ? ";
        cin >> menu;

        if (menu == 3) break;

        if (menu == 1) {
            int type;
            cout << "상품 종류 책(1), 음악CD(2), 회화책(3) ? ";
            cin >> type;
            cin.ignore(); // 버퍼 비우기

            string desc, prod, title, author, isbn, album, artist, lang;
            int price;

            cout << "상품설명>>"; getline(cin, desc);
            cout << "생산자>>"; getline(cin, prod);
            cout << "가격>>"; cin >> price; cin.ignore();

            if (type == 1) {
                cout << "책제목>>"; getline(cin, title);
                cout << "저자>>"; getline(cin, author);
                cout << "ISBN>>"; getline(cin, isbn);
    
                // 수정: 인덱스 증가를 분리하여 모호함 제거
                pList[count] = new Book(count, desc, prod, price, isbn, author, title);
                count++;
            }
            else if (type == 2) {
                cout << "앨범제목>>"; getline(cin, album);
                cout << "가수>>"; getline(cin, artist);
    
                pList[count] = new CompactDisc(count, desc, prod, price, album, artist);
                count++;
            }
            else if (type == 3) {
                cout << "책제목>>"; getline(cin, title);
                cout << "저자>>"; getline(cin, author);
                cout << "언어>>"; getline(cin, lang);
                cout << "ISBN>>"; getline(cin, isbn);
    
                pList[count] = new ConversationBook(count, desc, prod, price, isbn, author, title, lang);
                count++;
            }
        } else if (menu == 2) {
            for (int i = 0; i < count; i++) {
                pList[i]->showInfo(); // 동적 바인딩 발생
            }
        }
    }

    // 메모리 해제
    for (int i = 0; i < count; i++) delete pList[i];

    return 0;
}