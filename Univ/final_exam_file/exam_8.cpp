#define _CRT_SECURE_NO_WARNINGS

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
    MyString(const MyString& other);
    ~MyString();

    MyString& operator=(const MyString& other);

    friend ostream& operator<<(ostream& os, const MyString& temp);
    friend MyString operator+(const MyString& a, const MyString& b);
    friend MyString operator-(const MyString& a, const MyString& b);
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
    m_pStr = NULL;
    m_nLen = 0;
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

// + 연산자 : 문자열 연결
MyString operator+(const MyString& a, const MyString& b) {
    int newLen = a.m_nLen + b.m_nLen - 1;

    char* buffer = new char[newLen];

    strcpy(buffer, a.m_pStr);
    strcat(buffer, b.m_pStr);

    MyString result(buffer);

    delete[] buffer;

    return result;
}

// 대소문자 구분 없이 특정 문자가 문자열에 있는지 확인
bool containsIgnoreCase(const char* str, char ch) {
    int target = tolower(static_cast<unsigned char>(ch));

    for (int i = 0; str[i] != '\0'; i++) {
        if (tolower(static_cast<unsigned char>(str[i])) == target) {
            return true;
        }
    }

    return false;
}

// - 연산자 : 두 문자열에 공통으로 들어 있는 문자를 모두 제거
MyString operator-(const MyString& a, const MyString& b) {
    int maxLen = a.m_nLen + b.m_nLen - 1;
    char* buffer = new char[maxLen];

    int index = 0;

    for (int i = 0; a.m_pStr[i] != '\0'; i++) {
        char ch = a.m_pStr[i];

        if (!containsIgnoreCase(b.m_pStr, ch)) {
            buffer[index++] = ch;
        }
    }

    for (int i = 0; b.m_pStr[i] != '\0'; i++) {
        char ch = b.m_pStr[i];

        if (!containsIgnoreCase(a.m_pStr, ch)) {
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
    MyString strE;

    cout << "strA => " << strA << endl;
    cout << "strB => " << strB << endl;

    strE = strA;
    cout << "strE = " << strE << endl;

    strC = strA + strB;
    cout << "strC = " << strC << endl;

    strD = strA - strB;
    cout << "strD = " << strD << endl;

    return 0;
}