#include <iostream>
#include <string>

using namespace std;

class URL {
private:
    string url;
    string protocol;
    string host;
    string port;
    string rest;

    void parsingURL() {
        // 1. 기본값 설정
        port = "80"; 

        // 2. 프로토콜 파싱 ("://" 찾기)
        int pEnd = url.find("://");
        if (pEnd != -1) {
            protocol = url.substr(0, pEnd);
        } else {
            protocol = ""; // 프로토콜이 없는 경우 대비
        }

        // 3. 탐색 시작 위치 설정 ("://" 다음부터)
        int hStart = (pEnd != -1) ? pEnd + 3 : 0;

        // 4. 경로(/)의 위치를 먼저 찾습니다. (호스트와 포트의 범위를 제한하기 위함)
        int slashPos = url.find("/", hStart);

        // 5. 포트 구분자(:)를 찾되, 경로(/)보다 앞에 있는 것만 찾습니다.
        int hEnd = url.find(":", hStart);
        
        // 중요: 찾은 ':'가 '/' 뒤에 있다면 그건 포트가 아닙니다.
        if (hEnd != -1 && slashPos != -1 && hEnd > slashPos) {
            hEnd = -1; 
        }

        // 6. 케이스 분류: 포트가 존재하는가?
        if (hEnd != -1) {
            // 호스트 추출
            host = url.substr(hStart, hEnd - hStart);

            // 포트 추출 시도
            string tempPort;
            if (slashPos != -1) {
                tempPort = url.substr(hEnd + 1, slashPos - hEnd - 1);
            } else {
                tempPort = url.substr(hEnd + 1);
            }

            // 추출된 값이 있을 때만 덮어쓰기 (":"만 있는 경우 방어)
            if (tempPort != "") {
                port = tempPort;
            }
        } 
        else {
            // 포트가 없는 경우: 호스트는 hStart부터 slashPos 전까지
            if (slashPos != -1) {
                host = url.substr(hStart, slashPos - hStart);
            } else {
                host = url.substr(hStart);
            }
        }

        // 7. 나머지 주소(rest) 처리
        if (slashPos != -1) {
            rest = url.substr(slashPos);
        } else {
            rest = "/";
        }
    }

public:
    URL(string url) {
        this->url = url;
        parsingURL();
    }

    void show() {
        cout << "프로토콜 : " << protocol << endl;
        cout << "호스트 : " << host << endl;
        cout << "포트 : " << port << endl;
        cout << "주소 : " << rest << endl;
    }
};

int main() {
    string url;
    while (true) {
        cout << "웹주소를 입력하시오 >> ";
        getline(cin, url);
        if (url == "그만") {
            cout << "stop" << endl;
            break;
        }

        URL U(url);
        U.show();
        cout << endl;
    }
    cin.get();
}