#include <iostream>
#include "gwindow.h"

using namespace sgl;

class Tile
{
private:
    int x,y, width, height;
    std::string color;
public:
    Tile(int x, int y, int width, int height, std::string color);
    void print();
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    std::string getColor();
    bool contains(int x, int y);
    void draw(GWindow& window);

};
