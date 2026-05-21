#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

class Schedule{
protected:
    int distance = 0, curLoc, count;
    int *arr;
public:
    Schedule(int curLoc, int n[], int count) : curLoc(curLoc), count(count){
        this->arr = new int[count];
        for(int i = 0; i < count; i++){
            arr[i] = n[i];
        }
    }
    int getDis(){
        int pre = 10;
        for(int i = 0; i < count; i++){
            distance += abs(pre - arr[i]);
            pre = arr[i];
        }
        return distance;
    }
    void show(){
        cout << "현재 위치 : " << curLoc << "..." << curLoc;
        int pre = curLoc;
        for(int i = 0; i < count; i++){
            cout << " -> " << arr[i];
            pre = arr[i];
        }
        curLoc = pre;
        cout << endl;
    }
    int getCurLoc(){return curLoc;}
    virtual~Schedule(){delete []arr;}
};
class SSTF : public Schedule{
public:
    SSTF(int curLoc, int n[], int count) : Schedule(curLoc, n, count){
        
    }

    // 26.05.17 01:08 // 나머지는 일어나서 할 것.
    void sstf(int start){
        int *sort = new int[count];
        bool *visited = new bool[count];
        int tempCur = start;
        for(int i = 0; i < count; i++)visited[i] = false;

        for(int i = 0; i < count; i++){
            int minD = 9999, nextIdx = -1;
            for(int j = 0; j < count; j++){
                if(!visited[j]){
                    int d = abs(tempCur - arr[j]);
                    if(d < minD){
                        nextIdx = j;
                        minD = d;
                    }
                }
            }
            tempCur = arr[nextIdx];
            sort[i] = arr[nextIdx];
            visited[nextIdx] = true;

        }
        // 정렬 이후, 계산 및 출력 코드 작성
        //26.05.17 21:45

        for(int i = 0; i < count; i++){
            this->arr[i] = sort[i];
        }

        int pre = 10;
        for(int i = 0; i < count; i++){
            distance += abs(pre - sort[i]);
            pre = sort[i];
            curLoc = sort[i];
        }
        cout << "시작 위치 :" << start << "..." << start;
        
        for(int i = 0; i < count; i++){
            cout << " -> " << sort[i];
        }
        cout << endl;
        this->curLoc = pre;
        cout << "이동 거리 : " << distance << " 현재 위치 : " << getCurLoc();
        delete [] sort;
        delete [] visited;
    }
};
int main(){
    int n[6] = {0};
    cout << "6개의 동 입력" << endl;
    for(int i = 0; i < 6; i++){
        cin >> n[i];
    }
    Schedule S(10, n, 6);
    S.show();
    cout << "거리 : " << S.getDis() << "현재 위치" << S.getCurLoc() << endl;

    SSTF sstf(10, n, 6);
    sstf.sstf(10);
}