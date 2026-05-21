#include <iostream>
#include <cmath>
using namespace std;

class Schedule {
protected:
    int count;
    int* jobs;
    int curLoc;

public:
    Schedule(int curLoc, int n[], int count)
        : curLoc(curLoc), count(count)
    {
        jobs = new int[count];

        for (int i = 0; i < count; i++)
            jobs[i] = n[i];

        cout << "현재 위치는 " << curLoc << "동 : 배달 시작 ..." << curLoc;

        for (int i = 0; i < count; i++)
            cout << " -> " << jobs[i];

        cout << endl;
    }

    virtual ~Schedule() {
        delete[] jobs;
    }

    int run() {
        int dist = 0;
        int prev = curLoc;

        for (int i = 0; i < count; i++) {
            dist += abs(prev - jobs[i]);
            prev = jobs[i];
        }

        curLoc = prev;

        return dist;
    }

    int getCurLoc() {
        return curLoc;
    }
};

class ShortestFirst : public Schedule {

    // 부모 생성자 호출 전에
    // SSTF 순서 배열 생성
    static int* makeShortest(int start, int jobs[], int count) {

        int* sorted = new int[count];
        bool* visited = new bool[count];

        for (int i = 0; i < count; i++)
            visited[i] = false;

        int cur = start;

        for (int i = 0; i < count; i++) {

            int minDist = 999999;
            int idx = -1;

            for (int j = 0; j < count; j++) {

                if (!visited[j]) {

                    int d = abs(cur - jobs[j]);

                    if (d < minDist) {
                        minDist = d;
                        idx = j;
                    }
                }
            }

            sorted[i] = jobs[idx];
            visited[idx] = true;
            cur = jobs[idx];
        }

        delete[] visited;

        return sorted;
    }

public:
    ShortestFirst(int curLoc, int jobs[], int count)
        : Schedule(curLoc, makeShortest(curLoc, jobs, count), count)
    {
    }
};

int main() {

    int jobs[6];

    cout << "택배를 픽업할 동을 요청 순서대로 6개 입력 >> ";

    for (int i = 0; i < 6; i++)
        cin >> jobs[i];

    // FCFS
    Schedule fcfs(10, jobs, 6);

    cout << "전체 움직인 거리는 "
         << fcfs.run() << ", ";

    cout << "현재 위치는 "
         << fcfs.getCurLoc() << "동"
         << endl << endl;

    // SSTF
    ShortestFirst sf(10, jobs, 6);

    cout << "전체 움직인 거리는 "
         << sf.run() << ", ";

    cout << "현재 위치는 "
         << sf.getCurLoc() << "동"
         << endl;

    return 0;
}