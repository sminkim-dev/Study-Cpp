#include <iostream>
using namespace std;

class Light{
private:
    int light;
public:
    Light(int light = 1) : light(light){}
    ~Light(){
        
    }
    void operator~(){
        cout << "빛의 크기는 " << light << endl;
    }
    Light &operator+=(Light& a){
        this->light += a.light;
        a.light = 0; // 빛을 흡수한다는 개념
        return *this;
    }
    Light &operator+=(int l){
        this->light += l;
        return *this;
    }
    Light &operator=(const Light& a){
        this->light = a.light;
        return *this;
    }
    Light operator--(int m){
        Light tmp = *this; // 원본을 복사해서 저장
        this->light--; // 진짜 원본의 값을 1감소 이래야 c가 0이됨
        return tmp; // 감소하기 전 객체 반환 (후위 증감 연산자)
    }
    bool operator==(int m){
        return (this->light == m);
    }
};

int main(){
    Light a(10) , b(20), c , d(0);
    (a += b) += 10;
    ~a; ~b; ~c;
    d = c--;
    ~d;
    if(c == 0) cout << "빛 c는 꺼져있습니다." << endl;
    if(d == 0) cout << "빛 d는 꺼져있습니다." << endl;
    return 0;
}