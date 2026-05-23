#pragma once

class Rect{
    private:
        int width, height;
    public:
        Rect(int w, int h);
        int getWidth();
        int getHeight();
        int getArea();
};