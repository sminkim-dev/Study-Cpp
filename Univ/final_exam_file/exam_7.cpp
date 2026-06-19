#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class MyString {
private:
    int m_nLen;
    char* m_pStr;

public:
    MyString();
    MyString(const char* str);
    MyString(const MyString& other);              // 복사 생성자
    ~MyString();

    MyString& operator=(const MyString& other);   // 대입 연산자

    friend ostream& operator<<(ostream& os, const MyString& temp);
    friend MyString operator+(const MyString& a, const MyString& b);
    friend MyString operator-(const MyString& a, const MyString& b);
    friend bool containsIgnoreCase(const MyString& s, char ch);
};

// 기본 생성자
MyString::MyString() {
    m_nLen = 1;
    m_pStr = new char[m_nLen];
    strcpy(m_pStr, "");
}

// 문자열 생성자
MyString::MyString(const char* str) {
    m_nLen = strlen(str) + 1;
    m_pStr = new char[m_nLen];
    strcpy(m_pStr, str);
}

// 복사 생성자
MyString::MyString(const MyString& other) {
    m_nLen = other.m_nLen;
    m_pStr = new char[m_nLen];
    strcpy(m_pStr, other.m_pStr);
}

// 소멸자
MyString::~MyString() {
    delete[] m_pStr;
    m_nLen = 0;
    m_pStr = NULL;
}

// 대입 연산자
MyString& MyString::operator=(const MyString& other) {
    if (this == &other) {
        return *this;
    }

    delete[] m_pStr;

    m_nLen = other.m_nLen;
    m_pStr = new char[m_nLen];
    strcpy(m_pStr, other.m_pStr);

    return *this;
}

// 출력 연산자
ostream& operator<<(ostream& os, const MyString& temp) {
    os << temp.m_pStr;
    return os;
}

// + 연산자 : 두 문자열 연결
MyString operator+(const MyString& a, const MyString& b) {
    int newLen = a.m_nLen + b.m_nLen - 1;

    char* buffer = new char[newLen];

    strcpy(buffer, a.m_pStr);
    strcat(buffer, b.m_pStr);

    MyString result(buffer);

    delete[] buffer;

    return result;
}

// 대소문자 구분 없이 문자가 들어있는지 확인
bool containsIgnoreCase(const MyString& s, char ch) {
    char target = tolower(ch);

    for (int i = 0; s.m_pStr[i] != '\0'; i++) {
        if (tolower(s.m_pStr[i]) == target) {
            return true;
        }
    }

    return false;
}

// - 연산자 : 두 문자열에 공통으로 들어있는 문자를 모두 삭제
MyString operator-(const MyString& a, const MyString& b) {
    int maxLen = a.m_nLen + b.m_nLen - 1;
    char* buffer = new char[maxLen];

    int index = 0;

    // a 문자열 검사
    for (int i = 0; a.m_pStr[i] != '\0'; i++) {
        char ch = a.m_pStr[i];

        if (!(containsIgnoreCase(a, ch) && containsIgnoreCase(b, ch))) {
            buffer[index++] = ch;
        }
    }

    // b 문자열 검사
    for (int i = 0; b.m_pStr[i] != '\0'; i++) {
        char ch = b.m_pStr[i];

        if (!(containsIgnoreCase(a, ch) && containsIgnoreCase(b, ch))) {
            buffer[index++] = ch;
        }
    }

    buffer[index] = '\0';

    MyString result(buffer);

    delete[] buffer;

    return result;
}

int main() {
    MyString strA("Banana");
    MyString strB("Orange");
    MyString strC;
    MyString strD;

    cout << "strA => " << strA << endl;
    cout << "strB => " << strB << endl;

    strC = strA + strB;
    cout << "strC = " << strC << endl;

    strD = strA - strB;
    cout << "strD = " << strD << endl;

    return 0;
}