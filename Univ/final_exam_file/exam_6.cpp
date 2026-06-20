#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class MyString{
    int m_nLen;
    char * m_pStr;

public:
    MyString(){
        m_nLen = 1;
        m_pStr = new char[m_nLen];
        strcpy(m_pStr,"");
    }

    MyString(const char * str){
        m_nLen = strlen(str) + 1;
        m_pStr = new char[m_nLen];
        strcpy(m_pStr, str);
    }

    MyString& operator=(const MyString & other){
        if(this == &other) return *this;

        delete [] m_pStr;

        m_nLen = other.m_nLen;
        m_pStr = new char[m_nLen];
        strcpy(m_pStr, other.m_pStr);

        return *this;
    }

    friend ostream& operator<<(ostream &os, const MyString& n);
    friend MyString operator+(const MyString& f, const MyString& s);
    friend MyString operator-(const MyString& f, const MyString& s);
    friend bool sameignore(const MyString& str, const char ch);
};

ostream& operator<<(ostream &os, const MyString& n){
    os << n.m_pStr;
    return os;
}

MyString operator+(const MyString& f, const MyString& s){
    int n_len = f.m_nLen + s.m_nLen - 1;
    char * n_str = new char[n_len];

    strcpy(n_str, f.m_pStr);
    strcat(n_str, s.m_pStr);

    MyString result(n_str);
    delete [] n_str;

    return result;
}

bool sameignore(const MyString& str, const char ch){
    char target = tolower(ch);

    for(int i = 0; str.m_pStr[i] != '\0'; i++){
        if(tolower(str.m_pStr[i]) == target){
            return true;
        }
    }

    return false;
}

MyString operator-(const MyString& f, const MyString& s){
    char * buffer = new char[f.m_nLen];

    int index = 0;

    for(int i = 0; f.m_pStr[i] != '\0'; i++){
        char ch = f.m_pStr[i];

        if(!sameignore(s, ch)){
            buffer[index++] = ch;
        }
    }
    for(int i = 0; s.m_pStr[i] != '\0'; i++){
        char ch = s.m_pStr[i];

        if(!sameignore(f, ch)){
            buffer[index++] = ch;
        }
    }

    buffer[index] = '\0';

    MyString result(buffer);
    delete [] buffer;

    return result;
}

int main(){
    MyString strA("Banana");
    MyString strB("Orange");
    MyString strC;
    MyString strD;
    MyString strE;

    cout << strA << endl;
    cout << strB << endl;

    strE = strA;
    cout << strE << endl;

    strC = strA + strB;
    cout << strC << endl;

    strD = strA - strB;
    cout << strD << endl;
}