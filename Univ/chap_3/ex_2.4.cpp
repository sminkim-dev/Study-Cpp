#include <iostream>
#include <string>

using namespace std;

class Cube{
    private:
        int width, length, height, Volume;
        //int ingredient[3]; int Volume;
    public:

    Cube(int w, int l, int h):width(w),length(l),height(h){}

    void increase(int w, int l, int h){
        width += w;
        length += l;
        height += h;
    }// char label = {'w', 'l', 'h'};
    /*for(int i = 0; i < ingredient.length(); i++){
        ingredient[i] += label[i];
    }*/
    bool isZero(){
        bool check = false;
        if(width == 0 || length == 0 || height == 0){
            check = true;
            return check;
        }
        else{
            check = false;
            return check;
        }
    }
    int getVolume(){
        Volume = width * length * height;
        return Volume;
    }
};

int main(){
    Cube cube(1, 2, 3);
    cout << "cube의 부피는 " << cube.getVolume() << endl;
    cube.increase(1, 2, 3);
    cout << "cube의 부피는 " << cube.getVolume() << endl;
    if(cube.isZero()){
        cout << "The volume of the cube is 0";
    }
    else{
        cout << "The volume of the cube ins't 0";
    }
    cin.get();
}