#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string publisher;
    string title;
    int price;
    int page;

public:
    Book() {
        publisher = "";
        title = "";
        price = 0;
        page = 0;
    }

    void setBook(string publisher, string title, int price, int page) {
        this->publisher = publisher;
        this->title = title;
        this->price = price;
        this->page = page;
    }

    string getPublisher() {
        return publisher;
    }

    string getTitle() {
        return title;
    }

    int getPrice() {
        return price;
    }
};

int main() {
    int n;
    cout << "책 개수 입력: ";
    cin >> n;

    Book books[100];

    for (int i = 0; i < n; i++) {
        string publisher, title;
        int price, page;

        cin >> publisher >> title >> price >> page;

        books[i].setBook(publisher, title, price, page);
    }

    // 출판사 기준 정렬
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (books[j].getPublisher() > books[j + 1].getPublisher()) {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }

    // 같은 출판사끼리 묶어서 출력
    int i = 0;

    while (i < n) {
        string currentPublisher = books[i].getPublisher();
        int totalPrice = 0;

        cout << currentPublisher << " ";

        bool first = true;

        while (i < n && books[i].getPublisher() == currentPublisher) {
            if (first == false) {
                cout << ", ";
            }

            cout << books[i].getTitle();
            totalPrice += books[i].getPrice();

            first = false;
            i++;
        }

        cout << " " << totalPrice << endl;
    }

    return 0;
}