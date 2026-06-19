#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class UnderGradStudent {
protected:
    char name[20];        // 이름
    char department[20];  // 학부
    int grade;            // 학년
};

class DormStudent {
protected:
    char building[20];    // 기숙사명
    int roomNumber;       // 방 번호
};

class UnderGrad_DormStudent : public UnderGradStudent, public DormStudent {
public:
    void setStdInfo(char n[], char d[], int g, char b[], int r) {
        strcpy(name, n);
        strcpy(department, d);
        grade = g;
        strcpy(building, b);
        roomNumber = r;
    }

    void showStdInfo() {
        cout << "이름: " << name << endl;
        cout << "학부: " << department << endl;
        cout << "학년: " << grade << endl;
        cout << "기숙사명: " << building << endl;
        cout << "방 번호: " << roomNumber << endl;
        cout << "------------------------" << endl;
    }

    int changeDeptName(char searchName[]) {
        if (strcmp(name, searchName) == 0) {
            cout << "검색된 학생 이름: " << name << endl;
            cout << "현재 학부: " << department << endl;

            char answer;
            cout << "학부명을 수정하시겠습니까? (y/n): ";
            cin >> answer;

            if (answer == 'y' || answer == 'Y') {
                cout << "새로운 학부명 입력: ";
                cin >> department;

                cout << "학부명이 수정되었습니다." << endl;
                return 1;
            }
        }

        return 0;
    }

    void writeToFile(ofstream& fout) {
        fout << name << " "
             << department << " "
             << grade << " "
             << building << " "
             << roomNumber << endl;
    }
};

void updateFile(char* fileName, UnderGrad_DormStudent students[], int size) {
    ofstream fout(fileName);

    if (!fout) {
        cout << "파일을 열 수 없습니다." << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        students[i].writeToFile(fout);
    }

    fout.close();
}

int main() {
    const int SIZE = 15;
    UnderGrad_DormStudent students[SIZE];

    ifstream fin("student.txt");

    if (!fin) {
        cout << "student.txt 파일을 열 수 없습니다." << endl;
        return 0;
    }

    char name[20];
    char department[20];
    int grade;
    char building[20];
    int roomNumber;

    for (int i = 0; i < SIZE; i++) {
        fin >> name >> department >> grade >> building >> roomNumber;
        students[i].setStdInfo(name, department, grade, building, roomNumber);
    }

    fin.close();

    cout << "===== 학생 정보 출력 =====" << endl;

    for (int i = 0; i < SIZE; i++) {
        students[i].showStdInfo();
    }

    char searchName[20];
    cout << "학부명을 수정할 학생 이름 입력: ";
    cin >> searchName;

    int changed = 0;

    for (int i = 0; i < SIZE; i++) {
        if (students[i].changeDeptName(searchName) == 1) {
            changed = 1;
            break;
        }
    }

    if (changed == 1) {
        updateFile((char*)"student.txt", students, SIZE);
        cout << "student.txt 파일이 수정되었습니다." << endl;
    } else {
        cout << "수정된 정보가 없습니다." << endl;
    }

    return 0;
}