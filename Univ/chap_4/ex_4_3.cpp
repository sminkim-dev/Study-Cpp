#include <iostream>
#include <string>

using namespace std;

int main(){
    string text;
    string fix_text;
    cout << "텍스트 입력 >> ";
    getline(cin, text, '\n');
    for(int i = 0; i < text.length(); i++){
        if(i > 0 && text[i] == ' ' && text[i - 1] == ' '){
            continue;
        }
        fix_text.append(1, text[i]);
    }
    cout << fix_text << endl;

    cin.clear();
    cin.ignore(100, '\n');
    cin.get();
}