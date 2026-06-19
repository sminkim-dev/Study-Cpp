#include <iostream>
#include <string>
using namespace std;

class Converter{
    protected:
        double ratio;
    public:
        Converter(double ratio){this->ratio = ratio;}
        virtual double convert(double src) = 0;
        virtual string getSrcString()=0;
        virtual string getDesString()=0;
};
class WonToDollar : public Converter{
    string won = "원";
    string dollor = "달러";
    public:
        WonToDollar(double ratio):Converter(ratio){}
        double convert(double src)override{
            // ratio 1130 >> 1 dollor -> 1130won
            cout << getSrcString() << "을 " << getDesString() << "(으)로 바꿉니다. 입력된 " << getSrcString() << "은 " << src << "원입니다." << endl;
            cout << "변환 결과 : " << src / ratio << getDesString() << endl;
            return src/ratio;
        }
        string getSrcString()override{return won;}
        string getDesString()override{return dollor;}
};
class WonTOYen : public Converter{
    string won = "원";
    string yen = "엔";
    public:
        WonTOYen(double ratio):Converter(ratio){}
        double convert(double src)override{
            cout << getSrcString() << "을 " << getDesString() << "(으)로 바꿉니다. 입력된 " << getSrcString() << "은 " << src << "원입니다." << endl;
            cout << "변환 결과 : " << src / ratio << getDesString() << endl;
            return src/ratio;
        }
        string getSrcString()override{return won;}
        string getDesString()override{return yen;}
};

int main(){
    WonToDollar wd(1130);
    Converter *cv;
    cv = &wd;
    cv->convert(10000);
    WonTOYen wy(100.6);
    cv=&wy;
    cv->convert(10000);
}