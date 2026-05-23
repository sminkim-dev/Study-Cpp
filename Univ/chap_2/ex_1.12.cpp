/*실행 사례와 같이 투표를 집계하는 프로그램을 작성하라, 출마자는 2명으로 "황수희" 와 "장수희"이다. "그만"이 입력될 때까지
집계된 투표수로 과대표를 출력하라. 동표인 경우 공동 대표로 한다.*/
#include <iostream>
#include <string>

using namespace std;

int main(){

    string N[] = {"황수희", "장수희"};
    int V[] = {0,0};
    string S_name;
    int vote;
    
    cout << "과대표 출마자 : 황수희, 장수희\n";
    while(true){
        vote = 0;
        bool found = false;

        cout << "이름과 투표수>> ";
        cin >> S_name;
        if(S_name == "그만"){
            cout << "최종 집계 : ";
            for(int i = 0; i < 2; i++){
                cout << N[i] << " " << V[i] << "\t";
            }
            cout << "\n";
            if(V[0]>V[1]){
                cout << "과대표로 " << N[0] << "가 선출되었습니다.";
            }else if(V[0]< V[1]){
                cout << "과대표로 " << N[1] << "가 선출되었습니다.";
            }
            else{
                cout << "무승부입니다.\n";
            }
            break;
        }
        cin >> vote;
        for(int i = 0; i < 2; i++){
            if(S_name == N[i]){
                V[i] += vote;
                found = true;
            }
        }
        
        if(!found){
            cout << S_name << "은 출마자가 아닙니다.\n";
        }
    }
    system("pause");
}
//clear