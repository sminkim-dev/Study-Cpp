#include <iostream>
#include <string>
using namespace std;
// 교재는 28inch -> 58cm로 나오는데 오타인듯. 1인치에 2.54센티미터이므로 28인치는 71.12센티미터가 맞음.
class Converter{
    private:
    string srcUnit, dsetUnit; // 단위를 나타내는 문자열(예: "원", "달러", "엔")
    protected:
    double ratio;
    virtual double convert(double src) {return 0.0;}
    public:
    Converter(string sUnit, string dUnit, double ratio){
        srcUnit = sUnit;
        dsetUnit = dUnit;
        this->ratio = ratio;
    }
    void run(){
        cout << srcUnit << "을 " << dsetUnit << "로 변환합니다." << endl;
        cout << srcUnit << "을 입력하세요: ";
        double src;
        cin >> src;
        cout << convert(src) << dsetUnit << "입니다." << endl;
    }
};
class Inch2Cm : public Converter{
    public:
    Inch2Cm(string sUnit, string dUnit, double ratio) : Converter(sUnit,dUnit,ratio) {}
    double convert(double src) override {
        return src * ratio;
    }
};
int main(){
    Inch2Cm i2c("inch", "centimeter", 2.54); // 1인치에 2.54센티미터
    i2c.run();
}