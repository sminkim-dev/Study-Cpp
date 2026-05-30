#include <iostream>
using namespace std;

class MoneyBox
{
protected:
    int unit;     // 통의 단위 금액, 10000 혹은 50000
    int size = 0; // 현재 통에 들어 있는 매수
public:
    MoneyBox(int unit, int size = 100) : unit(unit), size(size) {}
    int drop(int money) // f_money : 230000 >> total_money = 370000
    {
        // 현재 통에서 money에 가장 가까운 최대 금액 지급, 남은 지급 금액 리턴
        if (money == 0) return 0;

        if (money < 0) return -1;
        int count = money / unit; // 이 단위 지폐로 필요한 매수.

        if(count > size) count = size;
        size -= count;
        return money - count * unit; // 아직 지급하지 못한 금액
    }
    int getUnit() { return unit; }
    int total() { return size * unit; } // 현재 통에 저장된 돈의 액수
    //int available(){} 아래 drop을 하면, drop 조건문만 통과하면 값이 변경되는데 그러면, withdraw 조건에 걸려도 이미 값이 변경된 후라
    // 의도치 않은 값 변경이 일어나서, 해당 함수 넣어서 비교 후 drop으로 하는게 좋아보이는데, 해당 문제는 부모 클래스 변경 X, main X 임으로.
    // 각 값을 비교하는 식으로 해야함.
    virtual void show() = 0;
};
class Box10000 : public MoneyBox
{
public:
    Box10000(int unit, int size) : MoneyBox(unit, size) {}
    void show() override
    {
        cout << unit << "원 : " << size << "매 " << total() << " ";
        for (int i = 0; i < size; i++)
        {
            cout << "+";
        }
        cout << endl;
    }
};
class Box50000 : public MoneyBox
{
public:
    Box50000(int unit, int size) : MoneyBox(unit, size) {}
    void show() override
    {
        cout << unit << "원 : " << size << "매 " << total() << " ";
        for (int i = 0; i < size; i++)
        {
            cout << "^";
        }
        cout << endl;
    }
};
class ATM
{
private:
    Box50000 b5 = Box50000(50000, 10);
    Box10000 b1 = Box10000(10000, 10);
    int getMenu()
    {
        // 메뉴를 출력하고 사용자 선택한 메뉴 번호 리턴
        cout << "인출:1 , ATM 내부보기:2 , 종료:3 >> ";
        int sel;
        cin >> sel;
        return sel;
    }
    void show()
    {
        // 현재 ATM 내부의 돈 현황 출력
        cout << "전체 금액 " << b5.total() + b1.total() << "원" << endl;
        b5.show();
        b1.show();
    }
    void withdraw()
    {
        // 인출처리
        cout << "찾을 금액(단위 : 만원) >> ";
        int f_money;
        cin >> f_money;
        if (f_money % 10000 != 0){
            cout << "만원 단위로만 인출 가능합니다." << endl;
            return;
        }
        if (b5.total() + b1.total() < f_money || f_money < 0)
        {
            cout << "지급 불가!" << endl;
            return;
        }

        int b5Unit = b5.getUnit(); // 각각의 unit (단위)를 복사함.
        int b1Unit = b1.getUnit();

        int b5Count = b5.total() / b5.getUnit(); // 총 금액 / 단위 = 매수 
        int b1Count = b1.total() / b1.getUnit();

        int need5 = f_money / b5Unit; // f_money / 50000 = 몫 >> 현재 단위로 해당 값을 나눌 수 있는 최대 값.(횟수)
        if(need5 > b5Count) need5 = b5Count; 
        // need5 > b5count : 현재 매수 / 가지고 있는 돈보다 많은 매수/돈이 필요한 경우의 조건.
        // 그럴 경우에는 현재 가지고 있는 매수 / 돈 만큼만 뺀다. 그러면 남는 돈은 아래 b1에서 처리하게됨.

        int rest = f_money - need5 * b5Unit; // 인출할 돈 - b5에서 돈 부족 / 매수 부족으로 넘어온 값 = rest
        int need1 = rest / b1Unit; // need1 = b5에서 넘어온 값을 10000 단위로 나눌 때의 몫, 매수를 의미.

        if(rest % b1Unit != 0 || need1 > b1Count){ 
            // b5에서 넘어온 값이 10000 단위로 div 안될 때, 또는 need1 즉 남은 값을
            // 10000 단위로 나눈 매수가 현재 가지고 있는 매수보다 높을 경우, 지급 불가 판정.
            cout << "지급 불가!" << endl;
            return;
        }

        // 위의 과정을 int available로 drop 과 동일하게 계산은 하지만 size 값을 변경하지 않고 값만 넘기면서 해당 조건을 확인한 후
        // 최종적으로 아래와 같이 drop으로 size를 변경하는 식으로 진행할 수 있지만. 현재 문제는 클래스 변경하면 안되기에 이렇게 함.
        rest = b5.drop(f_money);
        rest = b1.drop(rest);
    }

public:
    ATM() {}
    void run()
    {
        // ATM 작동
        show();
        while (true)
        {
            int sel = getMenu();
            if (sel == 3) break;
            if (sel == 1) withdraw();
            else if (sel == 2) show();
        }
    }
};
int main()
{
    ATM richATM;
    richATM.run();
}
