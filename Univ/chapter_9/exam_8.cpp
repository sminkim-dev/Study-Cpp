#include <iostream>
#include <cstring>
using namespace std;

class Box
{
protected:
    int width, height; // box w, h
    char ch;           // 박스의 경계선이나 박스 내부에 칠할 문자
    virtual void draw() = 0;

public:
    Box(int width, int height) : width(width), height(height) {}
    virtual ~Box() {} // 교재에는 가상 소멸자가 없음. 임시로 넣어놓음.
    void paint()
    {
        cout << "(" << width << "x" << height << "박스)" << endl;
        draw();
    }
    void set(char c) { ch = c; }
};
class BorderBox : public Box
{
public:
    BorderBox(int width, int height) : Box(width, height) {}
    void draw() override
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (i == 0 || j == 0 || i == height - 1 || j == width - 1)
                {
                    cout << ch;
                }
                else
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
};
class FilledBox : public Box
{
public:
    FilledBox(int width, int height) : Box(width, height) {}
    void draw() override
    {
        for (int h = 0; h < height; h++)
        {
            for (int w = 0; w < width; w++)
            {
                cout << ch;
            }
            cout << endl;
        }
        cout << endl;
    }
};
int main()
{
    Box *bBox = new BorderBox(10, 3); // 10 x 3 box size
    bBox->set('y');                   // box 경계선 문자를 'y'로 설정
    bBox->paint();                    // draw box

    Box *fbox = new FilledBox(20, 4); // 20 x 4 box size
    fbox->set('k');                   // 박스 내부 문자를 'k'로 설정
    fbox->paint();                    // draw box

    delete bBox;
    delete fbox;
    // ----- Memo ----- //
    // 26.05.30 am 1:44
    // 여기 부분 조금 애매함. 주어진 추상 클래스 Box를 수정하지 않고 풀어야 하는 점을 인지.
    // main도 동일하게 유지해야 한다면, 자식 클래스만으로 해결해야 하는 상황임.
    // 하지만 현재 객체를 Box*로 업캐스팅하고 있음.
    //
    // Box* bBox = new BorderBox(...);
    // delete bBox;
    //
    // 이처럼 부모 클래스 포인터로 자식 객체를 delete하면,
    // 컴파일러는 delete 대상의 정적 타입인 Box*를 기준으로 소멸자를 호출하려고 함.
    // 그런데 Box의 소멸자가 virtual이 아니면 실제 객체 타입인 BorderBox의 소멸자로 동적 바인딩되지 않음.
    // 따라서 자식 클래스의 소멸 과정이 제대로 수행되지 않을 수 있고,
    // 자식 클래스가 동적 메모리 같은 자원을 가지고 있다면 메모리 누수 등의 문제가 생길 수 있음.
    //
    // 현재 예제는 자식 클래스가 따로 해제할 자원을 가지고 있지 않아서 결과 출력은 정상처럼 보일 수 있음.
    // 하지만 C++ 설계상 다형적으로 사용할 기반 클래스에는 virtual 소멸자가 필요함.
    // 즉, 부모 클래스 Box를 수정할 수 없다면 자식 클래스만 수정해서 이 경고를 근본적으로 없애기는 어려워 보임.

    // 만일 Box* new BorderBox(...); 부분을 Box* 가 아닌,
    // BorderBox* 와 같은 자식 클래스 포인터에 먼저 저장한 후...
    // Box*에 해당 포인터를 대입해서 upcasting할 수 있음.

    // 이때는 deletesms Box*가 아닌, 원래 자식 클래스 포인터로 수행한다면...?
    // BorderBox* bBox = new BorderBox(...);
    // Box* box = bBox;
    // ...
    // delete bBox;
    // 이런 식으로, 부모 객체 타입 포인터가 아닌 자식 객체 타입 포인터를 삭제하면, 클래스에 가상 소멸자를 생성하지 않고 문제를 해결할 순 있음.
    // 즉, 부모 포인터로 delete로 인한 다형성 소멸 문제를 피할 수 있음.
}