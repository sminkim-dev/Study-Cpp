#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class IDManage{
    string front[4] = {"뛰어난" , "사랑스러운" , "까불까불" , "씩씩한"};
    string back[4] = {"호랑이", "장미", "고양이" , "나팔꽃"};
    public:
        IDManage(){}
        void nick(){
            while (true)
            {
                /* code */
                srand((unsigned)time(0));
                int idx = rand() % 4;
                string select;
                cout << "사용자 ID 생성 (Yes / No) >> ";
                cin >> select;
                if(select == "no"){
                    break;
                }
                cout << front[idx] << " " << back[idx] << endl;
            }
        }
};

int main(){
    IDManage id{};
    id.nick();
}