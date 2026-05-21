#include <iostream>
using namespace std;

class Schedule{
protected:
    int count; // jobs[] 배열의 크기
    int *jobs; // 방문한 아파트 동 번호를 저장할 배열
    int curLoc; // 현재 택배 기사가 있는 동 번호
public:
    Schedule(int curLoc, int n[], int count):curLoc(curLoc), count(count){
        this->jobs = new int[count];
        for(int i = 0; i < count; i++){
            this->jobs[i] = n[i];
        }
        cout << "현재 위치는 " << curLoc << "동 : 배달 시작 ..." << curLoc;
        for(int i = 0; i < count; i++){
            cout << " -> " << jobs[i];
        }
        cout << endl;
    }
    ~Schedule(){delete []jobs;}
    int run(){
        // 도착 순서대로 택배 처리
        int cur = this->curLoc;
        int distance = 0;
        distance += abs(cur - jobs[0]);
        for(int i = 0; i < count - 1; i++){
            distance += abs(jobs[i] - jobs[i + 1]);
            this->curLoc = jobs[i + 1];
        }
        return distance;
    }
    int getJobs(){return count;}
    int getCurLoc(){return curLoc;}
};


int main(){
    int jobs[6];
    cout << "택배를 픽업할 동을 요청 순서대로 6개 입력 >> ";
    for(int i = 0; i < 6; i++){
        cin >> jobs[i];
    }
    Schedule fcfs(10, jobs, 6); // 현재 10동에 택배 기사 있음, 6은 jobs 배열 크기
    cout << "전체 움직인 거리는 " << fcfs.run() << ", ";
    cout << "현재 위치는 " << fcfs.getCurLoc() << "동" << endl;
}