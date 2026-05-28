#include <iostream>
using namespace std;

class AbstractArray
{
protected:
    int *p;            // 동적 배열을 가리키는 포인터
    int size;          // 동적 배열의 크기
    int nextIndex = 0; // 연속적으로 저장된 배열에서 다음 빈 원소에 대한 인덱스 // 현재 저장된 정수의 개수와 동일

public:
    AbstractArray(int size = 5) : size(size)
    {
        this->p = new int[size];
        if (p == NULL)
        {
            exit(0);
        }
        this->size = size;
    }
    virtual ~AbstractArray() { delete[] p; }
    virtual bool put(int n) = 0;             // nextIndex 위치에 n 저장, 성공하면, true 리턴
    virtual bool put(int index, int n) = 0;  // index 위치에 n저장, 성공하면 true
    virtual bool get(int index, int &n) = 0; // index 위치에 저장된 값을 n에 저장, 성공하면 true
    virtual int length() = 0;                // 배열에 저장된 정수 개수 리턴
    virtual void show() = 0;                 // 배열 정보 출력
};
class InfiniteArray : public AbstractArray
{
public:
    InfiniteArray() {}
    ~InfiniteArray() {delete [] p;}
    bool put(int n) override
    {
        try
        {
            if (size <= nextIndex) // size : capacity, nextIndex : data 허용량을 넘어가면 2배 증가 구현.
            {
                int powerSize = size * 2;
                int *temp = new int[powerSize];
                // 중요...int temp [] != int *temp 이 둘은 서로 다른 구조임. *는 함수가 종료되면 스택에서 제거되지만, []은 메모리에 남아있어서 delete를 해야함.
                // 또한 동적으로 할당할 때는 [] 사용할 수 없음. 정적으로 값을 정해줘야 해서 값을 달라지는 상황에선 사용할 수 없음. 
                for (int i = 0; i < length(); i++)
                    temp[i] = p[i]; // 깊은 복사
                delete[] p; // 얕은 복사 temp 주소를 공유하기 때문에 여기서 delete []temp;를 하면 p 배열의 값이 사라지는 상황이 생김.
                // 그리고 temp는 해당 함수가 종료되면 자동으로 스택에서 제거되기 때문에 delete 하면 안됨. (소멸 X, 변수만 제거, 주소는 p가 넘겨 받음.)
                p = temp; // 그냥 대입, p를 따로 int new[powerSize];를 해서 대입시키면 메모리 누수가 생기는 경우가 있거나, 불필요한 경우가 많음.
                size = powerSize;
            }
            p[nextIndex++] = n;
            return true;
        }
        catch (const exception& e)
        // exception e 가 아닌 const exception &e를 쓰는 이유
        // 1. 불피요한 복사 방지 2. 객체 잘림(object slicing) 방지 3. 예외 객체를 안전하게 읽기 전용으로 받기 위해
        // exception e는 이런 이유로 const exception &e를 c++에서는 권장하거나, 더 선호하는 편이라 함.
        // 1. 객체 복사 발생 2. slicing 가능 3. 비효율적
        {
            return false;
        }
    }
    bool put(int index, int n) override
    {
        try
        {
            if(index < 0 || nextIndex <= index) return false; // < 만 하면, == 이 성립하게 되는데 기억해야 할 건.
            // 원소 개수 != 인덱스 위치 라는 것. 즉, == 성립시키면, 쓰레기 값을 가져오게 됨. 따라서 현재 총 개수랑 index 위치가 서로 같을 경우에도 두배로 늘려야함.
            while(nextIndex >= size){
                int powerSize = size * 2;
                int *temp = new int[powerSize];
                for(int i = 0; i < nextIndex; i++){
                    temp[i] = p[i];
                }
                delete [] p;
                p = temp;
                size = powerSize;
            }

            for (int i = nextIndex; i > index; i--) // size는 capacity 즉, 총량이기에 현재 값을 기준으로 잡아야해서 nextIndex로 시작.
            // index 전까지 감소시킴. 왜? > index까지 범위를 넣으면 p[i -1] 부분에서 배열 범위를 벗어나기 때문에 문제 생김.
            {
                p[i] = p[i - 1];
            }
            p[index] = n; // 해당 인덱스 부분부터 뒤로 미루고, 해당 위치에 값을 넣어야 함.
            nextIndex++; // 여기를 추가 안해주면, nextIndex가 상승 안해서, size가 안늘어나고, 그러면 배열 증가가 안 일어남.
            return true;
        }
        catch (const exception &e)
        {
            // 보통 이렇게 작성한다고 함. 
            return false;
        }
    }
    bool get(int index, int &n) override
    {
        if (index < 0 || size < index)
        {
            return false;
        }
        else
        {
            n = p[index];
            return true;
        }
    }
    int length() override
    {
        return nextIndex;
    }
    void show() override
    {
        cout << "[용량 " << size << ": 현재 크기 " << nextIndex << "]\t";
        for (int i = 0; i < length(); i++)
        {
            cout << p[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    InfiniteArray a;
    for (int i = 0; i < 4; i++)
        a.put(i); // 가변 배열 a에 4개 정수 삽입
    a.show();
    for (int i = 0; i < 4; i++)
        a.put(i, 4 + i); // 가변 배열 a에 4개 정수 삽입 // 배열 크기 2배 증가
    a.show();
    for (int i = 0; i < 15; i++)
        a.put(i, 100 + i); // 가변 배열 a에 15개 정수 삽입 // 배열 크기 2배 증가
    a.show();

    int n;
    for (int i = 0; i < 10; i++)
    {
        // 가변 배열 a에서 10개 읽어 출력
        a.get(i, n);
        cout << n << " ";
    }
    cout << endl;
}