// 옛날 기출이라 범위 안 맞음.
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

struct Member {
    char sName[15];
    int sNum;
    char Tel[15];

    Member() : sNum(0) {
        sName[0] = '\0';
        Tel[0] = '\0';
    }
};

struct ProjectTeam {
    int MemberCnt;
    char ProjTitle[50];
    Member* Mber[5];

    ProjectTeam() : MemberCnt(0) {
        ProjTitle[0] = '\0';

        for (int i = 0; i < 5; i++) {
            Mber[i] = nullptr;
        }
    }

    ~ProjectTeam() {
        for (int i = 0; i < 5; i++) {
            delete Mber[i];
        }
    }
};

class Evaluation {
protected:
    int passScore;
    int score[3];

public:
    Evaluation(int ps = 80) : passScore(ps) {
        for (int i = 0; i < 3; i++) {
            score[i] = 0;
        }
    }

    virtual void NthEval(int n) = 0;
    virtual void passORfail(const char* rfname) = 0;

    virtual ~Evaluation() {}
};

class Project : public Evaluation {
protected:
    int PTeamCnt;
    ProjectTeam* pt[7];

    int evalScore[7][3];

public:
    Project(int score = 80, int Pt = 1) : Evaluation(score), PTeamCnt(Pt) {
        if (PTeamCnt < 1) PTeamCnt = 1;
        if (PTeamCnt > 7) PTeamCnt = 7;

        for (int i = 0; i < 7; i++) {
            pt[i] = nullptr;

            for (int j = 0; j < 3; j++) {
                evalScore[i][j] = 0;
            }
        }

        for (int i = 0; i < PTeamCnt; i++) {
            pt[i] = new ProjectTeam;
        }
    }

    ~Project() {
        for (int i = 0; i < 7; i++) {
            delete pt[i];
        }
    }

    void storePrjData(const char* fname) {
        ofstream fout(fname);

        if (!fout) {
            cout << "파일을 열 수 없습니다: " << fname << endl;
            return;
        }

        for (int i = 0; i < PTeamCnt; i++) {
            int memberCnt;

            cin >> memberCnt;

            if (memberCnt < 1) memberCnt = 1;
            if (memberCnt > 5) memberCnt = 5;

            pt[i]->MemberCnt = memberCnt;

            cin >> setw(50) >> pt[i]->ProjTitle;

            fout << pt[i]->MemberCnt << endl;
            fout << pt[i]->ProjTitle << endl;

            for (int j = 0; j < memberCnt; j++) {
                if (pt[i]->Mber[j] == nullptr) {
                    pt[i]->Mber[j] = new Member;
                }

                cin >> setw(15) >> pt[i]->Mber[j]->sName
                    >> pt[i]->Mber[j]->sNum
                    >> setw(15) >> pt[i]->Mber[j]->Tel;

                fout << pt[i]->Mber[j]->sName << " "
                     << pt[i]->Mber[j]->sNum << " "
                     << pt[i]->Mber[j]->Tel << endl;
            }
        }

        fout.close();
    }

    void readNshowPrjData(const char* fname) {
        ifstream fin(fname);

        if (!fin) {
            cout << "파일을 열 수 없습니다: " << fname << endl;
            return;
        }

        for (int i = 0; i < PTeamCnt; i++) {
            int memberCnt;
            char title[50];

            fin >> memberCnt;
            fin >> setw(50) >> title;

            pt[i]->MemberCnt = memberCnt;
            strcpy(pt[i]->ProjTitle, title);

            cout << pt[i]->MemberCnt << endl;
            cout << pt[i]->ProjTitle << endl;

            for (int j = 0; j < memberCnt; j++) {
                if (pt[i]->Mber[j] == nullptr) {
                    pt[i]->Mber[j] = new Member;
                }

                fin >> setw(15) >> pt[i]->Mber[j]->sName
                    >> pt[i]->Mber[j]->sNum
                    >> setw(15) >> pt[i]->Mber[j]->Tel;

                cout << pt[i]->Mber[j]->sName << " "
                     << pt[i]->Mber[j]->sNum << " "
                     << pt[i]->Mber[j]->Tel << endl;
            }
        }

        fin.close();
    }

    void NthEval(int n) override {
        if (n < 1 || n > 3) {
            cout << "평가 번호는 1~3만 가능합니다." << endl;
            return;
        }

        for (int i = 0; i < PTeamCnt; i++) {
            cin >> evalScore[i][n - 1];
        }
    }

    // 사진의 main에는 NthScore라고 보이는 부분이 있어서 호환용으로 추가
    void NthScore(int n) {
        NthEval(n);
    }

    void passORfail(const char* rfname) override {
        ofstream fout(rfname);

        if (!fout) {
            cout << "파일을 열 수 없습니다: " << rfname << endl;
            return;
        }

        for (int i = 0; i < PTeamCnt; i++) {
            int sum = 0;

            for (int j = 0; j < 3; j++) {
                sum += evalScore[i][j];
            }

            double avg = sum / 3.0;
            const char* result = avg >= passScore ? "통과" : "실패";

            fout << i + 1 << "팀 "
                 << pt[i]->ProjTitle << " "
                 << evalScore[i][0] << " "
                 << evalScore[i][1] << " "
                 << evalScore[i][2] << " "
                 << fixed << setprecision(1) << avg << " "
                 << result << endl;
        }

        fout.close();
    }
};

int main() {
    Project p1(85, 3);       // 통과 기준 85점, 프로젝트 팀 3팀

    p1.storePrjData("output3");
    p1.readNshowPrjData("output3");

    p1.NthScore(1);
    p1.NthScore(2);
    p1.NthScore(3);

    p1.passORfail("result");

    return 0;
}