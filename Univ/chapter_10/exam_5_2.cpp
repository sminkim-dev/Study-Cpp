#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cctype>
using namespace std;

double cal_avg(const vector<string> &program)
{
    map<string, double> grade{
        {"A+", 4.5},
        {"A", 4.0},
        {"B+", 3.5},
        {"B", 3.0},
        {"C+", 2.5},
        {"C", 2.0},
        {"D+", 1.5},
        {"D", 1.0},
        {"F", 0.0}};
    double avg = 0;
    for (const string &s : program)
    {
        avg += grade[s];
    }
    return avg / program.size();
}

int main()
{
    vector<string> program;
    cout << "6과목의 학점 입력 >> ";
    for (int i = 0; i < 6; i++)
    {
        string sub_;
        cin >> sub_;
        for (char &c : sub_)
            {
                c = toupper(c);
            }
        program.push_back(sub_);
    }
    cout << "학점 평균 : " << cal_avg(program) << endl;
}