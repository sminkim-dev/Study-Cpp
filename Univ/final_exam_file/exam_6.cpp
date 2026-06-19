// 파일 가져와서 열고 수정하는거 안배움.
#include <iostream>
#include <cstring>
using namespace std;

struct Member{
    char sName[15];
    int sNum;
    char Tel[15];
};
class ProjectTeam{
    private:
        int MemberCnt;
        char ProjTitle[50];
        struct Member* Mber[5];
    public:
        ProjectTeam(int MbCnt){}
        void prnTeamMember(){}
};
int main(){
    int nums;
    cin >> nums;
    char title[20];
    cin >> title;
    char name[20]; 
    char snum[20]; 
    char tel[20];
    for(int i = 0; i<nums; i++){
        cin >> name >> snum >> tel;    

    }
}