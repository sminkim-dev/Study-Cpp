#include <iostream>
#include <string>
using namespace std;

string erase(string src, string target = " ", string replacement = "") {
    size_t pos = 0;
    
    // find() 함수로 target의 위치를 찾음 (찾지 못할 때까지 반복)
    while ((pos = src.find(target, pos)) != string::npos) {
        // target의 길이만큼을 replacement로 교체
        // 만약 replacement가 ""(기본값)라면 결과적으로 해당 부분이 삭제됨
        src.replace(pos, target.length(), replacement);
        
        // 치환 후, 치환된 문자열의 다음 위치부터 다시 검색
        pos += replacement.length(); 
    }
    
    return src;
}

int main(){
    string a = erase("Hello     world,  Yaho");
    cout << "모든 빈 칸 지운 결과\t" << a << endl;
    string b = erase("Hello     world,  Yaho", "ll");
    cout << "모든 ll을 지운 결과\t" << b << endl;
    string c = erase("Hello     world,  Yaho", "o", "77");
    cout << "모든 o을 77로 바꾼 결과\t" << c << endl;

    cin.get();
}