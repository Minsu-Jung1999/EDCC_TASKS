#include "Tile.h"
#include "gwindow.h"
#include <iostream>

using namespace std;
using namespace sgl;
Tile::Tile(int x, int y, int width, int height, string color) : x(x),y(y), width(width), height(height),color(color){}

void Tile::print()
{
    cout<<"x = "<<x<<", y = "<<y<<", width = "<<width<<", height = "<<height<<", color = "<<color<<endl;
}
int Tile::getX()
{
    return x;
}
int Tile::getY()
{
    return y;
}
int Tile::getWidth()
{
    return width;
}
int Tile::getHeight()
{
    return height;
}
string Tile::getColor()
{
    return color;
}
bool Tile::contains(int x, int y)
{
    if(this->x<x && x<(width+this->x))
    {
        if(this->y<y && y < (height+this->y))
        {
            return true;
        }
    }
    return false;
}
void Tile::draw(GWindow& window)
{
    window.setFillColor(color);
    window.fillRect(x,y,width,height);
}
