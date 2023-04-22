/*
 * CS 132 Tiles
 *
 * Description
 * Overall, this file provides an implementation for a Tile class that can be used to create,
 * manipulate, and draw tiles with specific attributes.
 *
 * @author Minsu Jung
 * @version 2023/04/15 - 2023/04/21
 */

#include "Tile.h"
#include "gwindow.h"
#include <iostream>

using namespace std;
using namespace sgl;

// Constructor for the Tile class, takes the x and y coordinates, the width and height of the tile,
// and the color of the tile as parameters
Tile::Tile(int x, int y, int width, int height, string color) : x(x),y(y), width(width), height(height),color(color){}

// Method to print the attributes of the Tile object
void Tile::print()
{
    cout<<"x = "<<x<<", y = "<<y<<", width = "<<width<<", height = "<<height<<", color = "<<color<<endl;
}

// Method to get the x-coordinate of the Tile object
int Tile::getX()
{
    return x;
}

// Method to get the y-coordinate of the Tile object
int Tile::getY()
{
    return y;
}

// Method to get the width of the Tile object
int Tile::getWidth()
{
    return width;
}

// Method to get the height of the Tile object
int Tile::getHeight()
{
    return height;
}

// Method to get the color of the Tile object
string Tile::getColor()
{
    return color;
}

// Method to check whether a point (x,y) is inside the Tile object
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

// Method to draw the Tile object on a GWindow
void Tile::draw(GWindow& window)
{
    window.setColor("Black");
    window.setLineWidth(1);
    window.setFillColor(color);
    // Draw a filled rectangle on the GWindow object with the x and y coordinates, width,
    // and height of the Tile object
    window.fillRect(x,y,width,height);

}
