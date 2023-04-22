/*
 * CS 132 Tiles
 *
 * Description
 * defines the methods of a TileManager class.
 * The TileManager class manages a vector of Tile objects and provides methods
 * to add, draw, highlight, raise, lower, remove and clear them from a graphical window using
 * the Simple Graphics Library (sgl).
 *
 * @author Minsu Jung
 * @version 2023/04/15 - 2023/04/21
 */

#include <iostream>
#include "TileManager.h"
#include "gwindow.h"
using namespace std;
using namespace sgl;

// This constructor is called every time a new tile manager object is created
TileManager::TileManager(){}

// Adds the Tile object passed as argument to the top of the tiles vector.
void TileManager::addBottom(Tile& rect)
{
    tiles.insert(tiles.begin(),rect);

}

// Adds the Tile object passed as argument to the top of the tiles vector.
void TileManager::addTop(Tile& rect)
{
    tiles.push_back(rect);
}

// Draws all Tile objects in the tiles vector on the GWindow object passed as argument.
void TileManager::drawAll(GWindow& window)
{
    for (auto& tile : tiles) {
        tile.draw(window);
    }
}
// Clears all Tile objects in the tiles vector.
void TileManager::clear()
{
    tiles.clear();
}
// Draws a yellow highlight around the top-most Tile object that contains the coordinates (x, y) on the GWindow object passed as argument.
void TileManager::highlight(int x, int y, GWindow& window)
{
    int space =10;
    window.setColor("Yellow");
    window.setLineWidth(space);
    for(int i=tiles.size();i>=0;i--)
    {
        if(tiles[i].contains(x,y))
        {
            window.drawRect(tiles[i].getX()-(space/2),tiles[i].getY()-(space/2),tiles[i].getWidth()+space,tiles[i].getHeight()+space);
            break; // stop when it find a mosttop tile.
        }
    }
}

// Brings the top-most Tile object that contains the coordinates (x, y) to the top of the tiles vector.
void TileManager::raise(int x, int y)
{
    if(tiles.empty()) return;
    for(int i=tiles.size();i>=0;i--)
    {
        if(tiles[i].contains(x,y))
        {
            Tile temp = tiles[i];
            tiles.erase(tiles.begin()+i);
            tiles.push_back(temp);
            break; // stop when it find a mosttop tile.
        }
    }
}

// Sends the top-most Tile object that contains the coordinates (x, y) to the bottom of the tiles vector.
void TileManager::lower(int x, int y)
{
    if(tiles.empty()) return;
    for(int i=tiles.size();i>=0;i--)
    {
        if(tiles[i].contains(x,y))
        {
            Tile temp = tiles[i];
            tiles.erase(tiles.begin()+i);
            tiles.insert(tiles.begin(),temp);
            break; // stop when it find a mosttop tile.
        }
    }
}

// Removes the top-most Tile object that contains the coordinates (x, y) from the tiles vector.
void TileManager::remove(int x, int y)
{
    if(tiles.empty()) return;
    for(int i=tiles.size();i>=0;i--)
    {
        if(tiles[i].contains(x,y))
        {
            tiles.erase(tiles.begin()+i);
            break; // stop when it find a mosttop tile.
        }
    }
}

// Removes all Tile objects that contain the coordinates (x, y) from the tiles vector.
void TileManager::removeAll(int x, int y)
{
    if(tiles.empty()) return;
    for(int i=tiles.size();i>=0;i--)
    {
        if(tiles[i].contains(x,y))
        {
            tiles.erase(tiles.begin()+i);
        }
    }
}
