#include <iostream>
#include <string>

using namespace std;

class Star {
private:
    int row;
public:
    Star() : row(0) {}

    // 입력을 담당하는 함수
    int getSelectShape() {
        string kind[] = { "직각 삼각형", "피라미드", "역직각 삼각형" };
        int choice;

        cout << "----- 별 찍기 모양 선택 -----\n";
        for (int i = 0; i < 3; i++) {
            cout << i + 1 << "번 | " << kind[i] << "\n";
        }
        cout << "선택 >> ";
        cin >> choice;

        if (choice < 1 || choice > 3) {
            cout << "[Error] 잘못된 선택입니다.\n";
            return -1;
        }

        cout << "줄 수(Row)를 입력하세요 >> ";
        cin >> row;

        return choice - 1; // 0, 1, 2로 반환하여 배열/조건문에 활용
    }

    // 출력을 담당하는 함수
    void show(int shapeType) {
        if (shapeType == -1) return;

        cout << "\n--- 출력 결과 ---\n";
        for (int i = 0; i < row; i++) {
            if (shapeType == 0) { // 직각 삼각형
                for (int j = 0; j <= i; j++) cout << "*";
            }
            else if (shapeType == 1) { // 피라미드
                for (int j = 0; j < row - i - 1; j++) cout << " ";
                for (int j = 0; j < (2 * i + 1); j++) cout << "*";
            }
            else if (shapeType == 2) { // 역직각 삼각형
                for (int j = 0; j < row - i; j++) cout << "*";
            }
            cout << "\n";
        }
    }
};

int main() {
    Star star;
    
    // 입력을 한 번만 받아 변수에 저장 (최적화 핵심)
    int selected = star.getSelectShape();
    
    // 결과 출력
    star.show(selected);

    cout << "\n";
    system("pause");
    return 0;
}