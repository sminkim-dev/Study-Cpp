#include <iostream>

using namespace std;

class StringTokenizer{
    string* tokens;
    int size = 0;
    int nextTokenIndex = 0; // next 시에 다음 토큰(단어)에 대한 인덱스
    public:
    // 생성자에서 원본 텍스트에서 구분자의 위치를 찾아 나눔과 동시에 size 크기까지 늘림.
        StringTokenizer(string text, string delimiter){
                this->tokens = new string[text.length()];

                int start = 0;
                while(true){
                    int found = text.find(delimiter,start);
                    if(found == -1){
                        string lastTokens = text.substr(start);
                        if(lastTokens != ""){
                            tokens[size++] = lastTokens;
                        }
                        break;
                    }

                    string token = text.substr(start, found); // start <= index < found
                    if(token != ""){
                        tokens[size++] = token;
                    }

                    start = found + delimiter.length();
                }
            }
        ~StringTokenizer(){
            delete[]tokens;
        }
        int length(){
            // string class 기능 중 하나인 length()가 아닌, 내가 만든 클래스 내에 있는 length()함수라서 다름.
            // 맨 위에 보면 size = 0으로 초기화되어 있지만, 생성자가 만들어짐과 동시에 리스트에 값이 들어가면서 size++가 되기에 size 값이 커지게 되서
            // 이 함수를 쓸 때에는 0이 아닌 늘어난 만큼 값이 ++ 이 되어있다.
            return size;
        }
        string next(){
            if (nextTokenIndex < size) {
                return tokens[nextTokenIndex++];
            }
            return "";
        }
        bool hasNext(){
            return nextTokenIndex < size;
        }
};

int main(){
    StringTokenizer code("i++; for(); sum+=i;" , " ");

    for(int i = 0; i < code.length(); i++){
        cout << code.next() << endl;
    }

    StringTokenizer text("모짜르트,베토벤,슈베르토,황기태", ",");

    while(text.hasNext()){
        cout << text.next() << endl;
    }

    cin.get();
}