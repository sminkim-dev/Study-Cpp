#include <iostream>
#include <cmath>
using namespace std;

// chapter 8 - problem 6 - 2
// 문제 먼가 이상함. class, main 수정하지 않고, 문제 결과와 일치해야하는데, 출력 값을 생성자 외엔 넣을 곳이 없음.
// 생성자에 넣으면 부모 클래스는 정상 작동하지만, 자식 클래스에선 부모 클래스 생성자가 생성되고 난 뒤에 생성되므로, 부모 클래스 출력문 나오고 자식 클래스 출력문이 나오게됨.
// 즉, 문제와 다르게 출력 결과물이 나옴. 값은 동일하지만 출력문이 중복으로 나오는 상황. 따로 출력 함수로 빼면 문제가 생기지 않으나. main, class 수정하지 않고 하려니 몹시 난해함.
int check = 0;
class Schedule {
protected:
    int count;
    int *jobs;
    int curLoc;

    // [핵심] 자식 클래스만 골라서 탈 수 있는 protected 생성자를 추가해야함. 안그러면 public의 생성자 안에 있는 출력문이 출력되서 결과값이 이상해짐.
    // 이 생성자는 데이터 세팅만 하고 '출력문'이 전혀 없습니다!
    // Schedule(int curLoc, int n[], int count, bool isChild) : curLoc(curLoc), count(count) {
    //     this->jobs = new int[count];
    //     for (int i = 0; i < count; i++) this->jobs[i] = n[i];
    // }
public:
    Schedule(int curLoc, int n[], int count) : curLoc(curLoc), count(count) {
        this->jobs = new int[count];
        for (int i = 0; i < count; i++) this->jobs[i] = n[i];
        if(check == 0){
            cout << "현재 위치는 " << curLoc << "동 : 배달 시작 ..." << curLoc;
            for (int i = 0; i < count; i++) cout << " -> " << jobs[i];
            cout << endl;
        }
        check++;
    }
    virtual ~Schedule() { delete[] jobs; }
    void print(){
        // 부모 생성자: 기본 FCFS 경로 출력
        // cout << "현재 위치는 " << curLoc << "동 : 배달 시작 ..." << curLoc;
        // for (int i = 0; i < count; i++) cout << " -> " << jobs[i];
        // cout << endl;
    }
    int run() {
        int dist = 0;
        int prev = 10; // 시작 지점 고정 (문제의 기준)
        for (int i = 0; i < count; i++) {
            dist += abs(prev - jobs[i]);
            prev = jobs[i];
        }
        this->curLoc = prev;
        return dist;
    }
    int getCurLoc() { return curLoc; }
};

class ShortestFirst : public Schedule {
public:
    ShortestFirst(int curLoc, int n[], int count) : Schedule(curLoc, n, count) {
        // 1. 최단 거리 순서로 jobs 배열 재정렬
        sortShortest(curLoc);
        
        // 2. 재정렬된 경로를 출력하는 함수 호출
        printPath(curLoc);
    }

    // [추가한 함수] 최단 거리(SSTF) 알고리즘으로 배열 재배치
    void sortShortest(int start) {
        int* sorted = new int[count];
        bool* visited = new bool[count];
        for (int i = 0; i < count; i++) visited[i] = false;

        int tempCur = start;
        for (int i = 0; i < count; i++) {
            int minD = 9999, nextIdx = -1;
            for (int j = 0; j < count; j++) {
                if (!visited[j]) {
                    int d = abs(tempCur - jobs[j]);
                    if (d < minD) {
                        minD = d;
                        nextIdx = j;
                    }
                }
            }
            visited[nextIdx] = true;
            sorted[i] = jobs[nextIdx];
            tempCur = jobs[nextIdx];
        }

        for (int i = 0; i < count; i++) this->jobs[i] = sorted[i];
        delete[] sorted;
        delete[] visited;
    }

    // [추가한 함수] 자식 전용 경로 출력 함수
    void printPath(int start) {
        cout << "현재 위치는 " << start << "동 : 배달 시작 ..." << start;
        for (int i = 0; i < count; i++) cout << " -> " << jobs[i];
        cout << endl;
    }
};

int main() {
    int jobs[6];
    cout << "택배를 픽업할 동을 요청 순서대로 6개 입력 >> ";
    for (int i = 0; i < 6; i++) cin >> jobs[i];

    // FCFS 실행
    Schedule fcfs(10, jobs, 6);
    //fcfs.print();
    cout << "전체 움직인 거리는 " << fcfs.run() << ", ";
    cout << "현재 위치는 " << fcfs.getCurLoc() << "동" << endl << endl;

    // ShortestFirst 실행 (main 수정 없음)
    ShortestFirst sf(10, jobs, 6);
    //sf.printPath(10);
    cout << "전체 움직인 거리는 " << sf.run() << ", ";
    cout << "현재 위치는 " << sf.getCurLoc() << "동" << endl;

    return 0;
}