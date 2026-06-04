#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <iterator>
// #include <set>
using namespace std;

// 3개의 벡터 사용, 성으로 사용하는 글자, 이름의 중간 글자들, 이름의 끝 글자들을 각각 입력 받아 저장.
// 각 벡터에서 1개씩 글자들을 랜덤으로 뽑아 , 이들을 연결하여 한 개의 이름을 완성하라.
// 성, 중간, 끝 글자들은 동일한 글자가 입력되면 안된다.

vector<string> first_name_group;
vector<string> middle_name_group;
vector<string> last_name_group;
vector<string> set; // 나는 벡터로 따로 만들어서 저장된 값을 반복문으로 돌려가면서 동일값이 있는지 판단하려고 했는데.
// set<string> createdName; //을 하면 편하게 할 수 있다고 함. 여기서 이미 중복처리를 하고 값이 들어가기 때문.
vector<string> *groups[3] = {
    &first_name_group, &middle_name_group, &last_name_group};

void insert_vec(string names, vector<string> &groups)
{
    stringstream ss(names);
    string tokens;
    while (ss >> tokens)
    {
        groups.push_back(tokens);
    }
}

string random_name(vector<string> &groups)
{
    // 같은 철자 중복 로직 생각해야함.
    // int n = rand() % 10; // 0 ~ 9 random number
    return groups[rand() % groups.size()];
}

// 하나하나 파싱하는게 비효율적, 아래에서 각 벡터의 크기만큼 곱한 값을 바로 int 값에 넣음.
// int limit_check(string f, string m, string l)
// {
//     int first = 0;
//     stringstream ss(f);
//     string tokens;
//     while (ss >> tokens)
//     {
//         first++;
//     }
//     int middle = 0;
//     stringstream mm(m);
//     while (mm >> tokens)
//     {
//         middle++;
//     }
//     int last = 0;
//     stringstream ll(l);
//     while (ll >> tokens)
//     {
//         last++;
//     }
//     int limit_value = first * middle * last;
//     return limit_value;
// }
int main()
{
    srand(unsigned(time(0)));

    // 배열로 각각 반복문으로 입력 가능하게 가능할 듯. 그러면 함수로 insert할 때도 반복문으로 사용 가능해보임.
    // cout << "first name >> ";
    // string first_name;
    // getline(cin, first_name);
    // cout << "middle name >> ";
    // string middle_name;
    // getline(cin, middle_name);
    // string last_name;
    // getline(cin, last_name);

    //
    //  0 : first   1 : middle  2 : last
    // string text[3] = {"성으로 사용할 글자들 입력 >> ", "중간 이름으로 사용할 글자들 입력 >> ", "끝 이름으로 사용할 글자들 입력 >> "};
    // string name_groups[3];
    // for(int i = 0; i < 3; i++){
    //     cout << text[i];
    //     getline(cin, name_groups[i]);
    // }

    // 원래는 입력 받아서 하는 문제인데, 확인할 때 불편해서 임의로 값을 넣어둠.
    string first_name = {
        "황 박 정 이 김 최 배 명" // 8
    };
    string middle_name = {
        "유 진 수 행 채 고 태 민 지 나 송 리 원" // 13
    };
    string last_name = {
        "원 수 민 효 회 재 서 은 현 림 연 정 진 찬" // 14
    };

    // 지금은 일단 진행
    insert_vec(first_name, first_name_group);
    insert_vec(middle_name, middle_name_group);
    insert_vec(last_name, last_name_group);
    // for(int i = 0; i < 3; i++){
    //     insert_vec(name_groups[i], *groups[i]); //역참조.
    // }

    while (true)
    {
        cout << "생성할 이름 수 >> ";
        int numsOfName;
        cin >> numsOfName;
        if (numsOfName == 0)
            break;
        // int limit = limit_check(first_name, middle_name, last_name); // limit 1456
        int limit = (first_name_group.size() * middle_name_group.size() * last_name_group.size());
        if (numsOfName > limit)
        {
            cout << "최대 생성 가능한 이름 개수는 " << limit << endl;
            continue;
        }
        int check = 0;
        while (true)
        {
            if (check == numsOfName)
                break;
            string first = random_name(first_name_group);
            string middle = random_name(middle_name_group);
            string last = random_name(last_name_group);
            if (first == middle || first == last || middle == last)
            {
                continue;
            }
            string name = first + middle + last;
            bool duplication = false;
            for (auto it = set.begin(); it != set.end(); it++)
            {
                if (name == *it)
                {
                    duplication = true;
                    break;
                }
            }

            // if(createdName.insert(name).second){
            //     check++;
            // }
            if (duplication == true)
                continue;
            set.push_back(name);
            check++;
        }
        for (auto it = set.begin(); it != set.end(); it++)
        {
            cout << *it << " ";
        }

        cout << endl;
    }
}