#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(){
    string text;
    string fix_text;
    cout << "텍스트 입력 (한글 안됨) >> ";
    getline(cin, text, '\n');
    for(int i = 0; i < text.length(); i++){
        if(isalpha(text[i]) || text[i] == ' '){
            fix_text.append(1, text[i]);
        }
    }
    cout << fix_text << endl;
    
    cin.get();
}