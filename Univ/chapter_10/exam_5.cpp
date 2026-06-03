#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;
// 아직 수정 중. 26.06.03 11:53
double cal_avg(const vector<string> &program){
    double point[] = {4.5,4.0,3.5,3.0,2.5,2.0,1.5,1.0,0}; //9개
    string loc[] = {"A+", "A", "B+", "B", "C+", "C". "D+", "D". "F"}; // 9개
    double avg = 0;

    for(auto it = program.begin(); it != program.end(); it++){
        for(int i = 0; i < 9; i++){
            if(*it == loc[i]){
                int index = i;
                avg += point[index];
                break;
            }
        }
    }
    return avg / program.size();
}

int main(){
    vector<string> program;

    cout << "6과목의 학점 입력 >> ";
    for(int i = 0; i < 6; i++){
        string sub;
        cin >> sub;
        program.push_back(sub);
    }
    cout << "학점 평균은 : " << cal_avg(program) << endl;
}