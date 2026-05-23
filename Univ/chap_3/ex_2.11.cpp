#include <iostream>
#include <string>
#include "ex_2.11.h"

using namespace std;

int main(){
    {
    Oval kitae, jane(10, 15);
    kitae.set(3,4);
    kitae.show();
    cout << jane.getWidth() << "x" << jane.getHeight() << ", 면적 " << jane.area() << endl;
    }
    system("pause");
    return 0;
}
