#include <iostream>
#include <string>
using namespace std;

// --- 구역 나누기 --- //
// Shape // line, circle, rectangle
// Editor -> 도형들을 저장하고 관리
// insert, cancel, show를 가짐
// UI -> 사용자에게 메뉴를 보여주고 입력을 받는 구조.
// 컴파일러는 위에서 아래로 내려감으로... 클래스 위치 신경 쓸 것.
// 처음 시도 때 class Shape를 나중에 선언해서, class Editor에서 해당 클래스를 찾지 못해 에러남.
class Shape
{
public:
    Shape() {}
    virtual string getShape() = 0;
    virtual ~Shape() {}
};
class Circle : public Shape
{
public:
    Circle() {}
    string getShape() override
    {
        string Shape = "Circle";
        return Shape;
    }
};
class Line : public Shape
{
public:
    Line() {}
    string getShape()
    {
        string Shape = "Line";
        return Shape;
    }
};
class Rectangle : public Shape
{
public:
    Rectangle() {}
    string getShape()
    {
        string Shape = "Rectangle";
        return Shape;
    }
};
class Eiditor
{
protected:
    string *repo;
    int data = 0;
    int capacity = 1;
    //string shape[3] = {"Line", "Circle", "Rectangle"};
    Shape *sh;

public:
    Eiditor()
    {
        repo = new string[capacity];
    }
    ~Eiditor() { delete[] repo; }
    void insert()
    {
        if (data >= capacity)
        {
            capacity++;
            string *temp = new string[capacity];
            for (int i = 0; i < (data); i++)
            {
                temp[i] = repo[i];
            }
            delete[] repo;
            repo = temp;
        }
        int target;
        cout << "선:1 , 원:2 , 사각형 3 >> ";
        cin >> target;
        // repo[data] = shape[target - 1]; // index 넘어나는 걸 방지. (index : 0 , 1 , 2) (human : 1 , 2, 3)
        if (target == 1)
        {
            sh = new Line();
            repo[data] = sh->getShape();
        }
        else if(target == 2){
            sh = new Circle();
            repo[data] = sh->getShape();
        }
        else if(target == 3){
            sh = new Rectangle();
            repo[data] = sh->getShape();
        }
        else{
            cout << "조건에 없는 선택입니다..." << endl;
            return;
        }
        data++;
    }
    void cancel()
    {
        cout << "삭제하고자 하는 도형의 인덱스 >> ";
        int sel;
        cin >> sel;
        if (sel > data || data < 0)
        {
            cout << "해당 인덱스는 없거나, 저장된 데이터가 없습니다." << endl;
        }
        else
        {
            for (int i = sel - 1; i < data - 1; i++)
            {
                repo[i] = repo[i + 1];
            }
            data--;
        }
    }
    void show()
    {
        for (int i = 0; i < data; i++)
        {
            cout << i + 1 << ": " << repo[i] << endl;
        }
    }
};
class UI
{
private:
    Eiditor e;

public:
    UI() {}
    void run()
    {
        Eiditor e;
        cout << "그래픽 에디터입니다." << endl;
        while (true)
        {
            cout << "삽입:1 , 삭제:2 , 모두보기:3 , 종료:4 >> ";
            int sel;
            cin >> sel;
            if (sel == 4) break;
            if (sel == 1) e.insert();
            else if (sel == 2) e.cancel();
            else if (sel == 3) e.show();
        }
    }
};
int main()
{
    UI u;
    u.run();
}