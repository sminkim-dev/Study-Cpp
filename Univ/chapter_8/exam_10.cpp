#include <iostream>
#include <string>
using namespace std;
// 비행기 예약 프로그램 작성, 상속과 protected, 파생 클래스 응용해야하는 문제.
// 26.05.19 00:09 (문제 확인)
// 26.05.19 11:29 (st)
// 26.05.19 13:00 (ed)
// 하위 클래스 묶고, 다중 상속으로 묶으면 꼬임. 여러 클래스로 나누어서 역할을 분담하는 그림으로 나아갸아함.
// 작은 조각부터인 시트, 시트 배열을 묶는 시간, 그리고 콘솔이라는 하나의 묶음.
// 이 클래스를 전부 통합하여 관리하는 클래스로 해당 코드는 구성되어있음.
// cancel 할 때 , 메뉴 선택지에 한해서 예외처리는 들어간 상황.

// 추가 지식 + 포인터 (*)를 매개변수에 넣는 이유는...
// 포인터를 사용하지 않는다면 매개 변수에 해당 값을 복사하기에 데이터 양이 너무 많아져서 속도가 느려짐.
// 포인터를 사용하면 해당 값의 주소만 복사해서 넘기므로, 변수 값을 하나하나 복사하지 않기에 빠르고, 가벼움.
// 최근의 C++에서는 포인터(*)보다는 참조를 더 많이 활용함.
// ex) s->cancelSeat(); <schecules *s> --> s.cancelSeat(); <const schedules &s> 기억해 둘 것.
// const &참조를 하면 읽기만 하고 복사하지 않음.
class Seat{
private:
    string name;
public:
    Seat(string name = "---") : name(name){}
    void reserve(string name){
        this->name = name;
    }
    // bool 처리를 하지 않으면 아래 관리하는 클래스에서 cancel을 할 경우 이름은 중요치 않고, 좌석번호만 일치하면 지우는 문제를 해결하기 위함.
    bool cancel(string name){
        if(this->name == name){
            this->name = "---";
            return true;
        }
        else{
            return false;
        }
    }
    string getName(){return name;}
};
class Schedule{
private:
    string time;
    Seat seat[8];
public:
    Schedule(string time):time(time){}
    string getTime(){return time;}
    Seat* getSeats(){return seat;}

    // airlinebook class에서 seat로 바로 좌표를 찍는 것보단...중개 느낌으로 중간 함수를 하나 만들어놓으면 깔끔해짐.
    // airlinebook -> schedules -> seat (O) , airlinebook -> seat(?) 가능은 함. 하지만 한단계 거치는 과정을 선호하는 듯 함.
    bool cancelSeat(string name, int seatNum){
        if(seatNum < 1 || 3 < seatNum) return false;
        return seat[seatNum - 1].cancel(name);
        // seat class의 cancel 함수에서 반환 값이 여기로 오면 그 값을 바로 bool값으로 반환한다.
        // seat[]자릿수의 취소 여부를 해당 함수를 호출한 곳으로 날린다. airlinebook menu == 2파트 부분.
    }
};
class Console{
public:
    static int getMenu(){
        cout << "예약 : (1) ,  취소 : (2) , 보기 : (3) , 끝내기 : (4) >> ";
        int menu;
        cin >> menu;
        return menu;
    }
    static int getTime(){
        cout << "07시 : (1) , 12시 : (2) , 17시 : (3) >> ";
        int time;
        cin >> time;
        return time;
    }
    static void printSingleSchedule(Schedule *s){
        cout << s->getTime() << " : ";
        Seat *seat = s->getSeats();
        for(int j = 0; j < 8; j++){
            cout << "\t" << seat[j].getName();
        }
        cout << endl;
    }
    static void printSchedule(Schedule *s[], int size){
        for(int i = 0; i < size; i++){
            cout << s[i]->getTime() << " : ";
            Seat *seat = s[i]->getSeats();
            for(int j = 0; j < 8; j++){
                cout << "\t" << seat[j].getName();
            }
            cout << endl;
        }
    }
};
class AirLineBook{
    private:
        Schedule* schedules[3];
    public:
        AirLineBook(){
            schedules[0] = new Schedule("07시");
            schedules[1] = new Schedule("12시");
            schedules[2] = new Schedule("17시");
        }
        ~AirLineBook(){
            for(int i = 0; i < 3; i++){
                delete schedules[i];
            }
        }
        // run()
        void run(){
            cout << "--- 한성 항공에 오신 것을 환영합니다 ---" << endl;
            while(true){
                // Console 클래스의 static 함수를 호출해서 입력을 받아옵니다.
                int menu = Console::getMenu();

                if(menu == 4){
                    cout << "예약 시스템을 종료합니다..." << endl;
                    break;
                }
                if(menu == 3){
                    Console::printSchedule(schedules, 3);
                }
                else if(menu == 1){
                    int timeSel = Console::getTime();
                    if(timeSel < 1 || 3 < timeSel)continue;

                    Schedule * selectedSchedule = schedules[timeSel - 1];
                    Console::printSingleSchedule(selectedSchedule);
                    cout << "좌석 번호 : ";
                    int seat;
                    cin >> seat;
                    cout << "이름 입력 : ";
                    string name;
                    cin >> name;

                    // 데이터 처리
                    selectedSchedule->getSeats()[seat - 1].reserve(name);
                    cout << endl;
                }
                else if(menu == 2){
                    int timeSel = Console::getTime();
                    if(timeSel < 1 || 8 < timeSel)continue;

                    Schedule * selectedSchedule = schedules[timeSel - 1];
                    Console::printSingleSchedule(selectedSchedule);
                    cout << "좌석 번호 : ";
                    int seat;
                    cin >> seat;
                    cout << "이름 입력 : ";
                    string name;
                    cin >> name;

                    // 데이터 처리
                    if(selectedSchedule->cancelSeat(name, seat)){
                        cout << "취소되었습니다." << endl;
                    }
                    else{
                        cout << "좌석 번호 또는 이름이 잘못되었습니다..." << endl;
                    }
                }
            }
        }
};

int main(){
    AirLineBook alb;
    alb.run();
}