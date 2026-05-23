#include <iostream>
#include <string>

using namespace std;

class Picture{
private:
    string place;
    int width;
    int height;
public:
    
    /*Picture(){
        width = 5;
        height = 7;
        place = "모름";
    }
    Picture(int a, int b, string n){
        width = a;
        height = b;
        place = n;
    }*/
   Picture():width(5), height(7), place("모름"){}
   Picture(int a, int b, string n):width(a), height(b), place(n){}

    int getWidth(){return width;}
    int getHeight(){return height;}
    string getPlace(){return place;}
};
int main(){
    Picture pic;
    Picture mt(10, 14, "한라산");
    cout << pic.getWidth() << "*" << pic.getHeight() << " " << pic.getPlace() << "\n";
    cout << mt.getWidth() << "*" << mt.getHeight() << " " << mt.getPlace() << "\n";
    system("pause");
}