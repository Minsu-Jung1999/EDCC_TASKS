/*
 * CS 132 Tiles
 *
 * Description
 * The TileManager class provides methods for manipulating and drawing a collection of Tile objects
 * in a GWindow, including adding, removing, raising, lowering, highlighting, and clearing tiles.
 *
 * @author Minsu Jung
 * @version 2023/04/15 - 2023/04/21
 */

#include <iostream>
#include "gwindow.h"

using namespace sgl;

class Tile
{
private:
    int x,y, width, height;
    std::string color;
public:
    // Constructor that takes in the x,y position, width, height, and color of the tile
    Tile(int x, int y, int width, int height, std::string color);
    // Prints out information about the tile's position, dimensions, and color
    void print();

    // Accessor methods for getting the x,y position, width, height, and color of the tile
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    std::string getColor();

    // Checks whether a given point (x,y) is within the boundaries of the tile
    bool contains(int x, int y);

    // Draws the tile on a given GWindow reference
    void draw(GWindow& window);

};
