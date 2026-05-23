#include <iostream>

using namespace std;

class A{
    string *tokens;
    int size = 0;
    int nextTokenIndex = 0;
    public:
        A(string text, string delimiter){
            this->tokens = new string[text.length()];

            int start = 0;
            while(true){
                int found = text.find(delimiter, start);
                if(found == -1){
                    string lastToken = text.substr(start);
                    if(lastToken != ""){
                        tokens[size++] = lastToken;
                    }
                    break;
                }

                string token = text.substr(start, found - start); // 시작 위치 , 가져올 문자 개수임. 혼동 X > 시작 위치 ~ 끝 위치가 아님.
                // substr(start, found) -> 로 하면 제대로 안짤림, 왜냐면 start부터 found index전까지 다 짤라버리기 때문. found전까지만 잘라야하는데 found 인덱스 까지 잘라버려서 문제 생김.
                // 예를 들어 start 4 이고 found 6이면 4~5인덱스 2개만 가져와야 하는데. 시작 4부터 문자 개수 6개인 인덱스 9번까지 감.
                // 그래서 필요한 자리만 짤라야 하기에. substr(시작, 가져올 자릿수) >> start , found - start가 되어야만 함.
                if(token != ""){
                    tokens[size++] = token;
                }
                start = found + delimiter.length();
            }
        }
        ~A(){
            delete[]tokens;
        }
        int length(){return size;}
        string next(){
            if(nextTokenIndex < size){
                return tokens[nextTokenIndex++];
            }
            return "";
        }
        bool hasNext(){
            if(nextTokenIndex < size){
                return true;
            }
            else{
                return false;
            }
        }
        
};

int main(){
    A code("i++; for(); sum+=i;" , " ");

    for(int i = 0; i < code.length(); i++){
        cout << code.next() << endl;
    }

    A text("모짜르트,베토벤,슈베르토,황기태", ",");
    while(text.hasNext()){
        cout << text.next() << endl;
    }
    cin.get();
}