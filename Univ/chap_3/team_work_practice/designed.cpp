#include "designed.h"

Rect::Rect(int w, int h){
    width = w;
    height = h;
}
int Rect::getWidth(){
    return width;
}
int Rect::getHeight(){
    return height;
}
int Rect::getArea(){
    return height*width;
}