#include <iostream>
#include "TileManager.h"
#include "gwindow.h"
using namespace std;
using namespace sgl;
TileManager::TileManager()
{

}

void TileManager::addBottom(Tile& rect)
{
    tiles.insert(tiles.begin(),rect);

}
void TileManager::addTop(Tile& rect)
{
    tiles.push_back(rect);
}
void TileManager::drawAll(GWindow& window)
{
    for (auto& tile : tiles) {
        tile.draw(window);
    }
}
// clear all of the rectangles
void TileManager::clear()
{
    tiles.clear();
}
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
void TileManager::raise(int x, int y)
{
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
void TileManager::lower(int x, int y)
{
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
void TileManager::remove(int x, int y)
{
    for(int i=tiles.size();i>=0;i--)
    {
        if(tiles[i].contains(x,y))
        {
            tiles.erase(tiles.begin()+i);
            break; // stop when it find a mosttop tile.
        }
    }
}
void TileManager::removeAll(int x, int y)
{
    for(int i=tiles.size();i>=0;i--)
    {
        if(tiles[i].contains(x,y))
        {
            tiles.erase(tiles.begin()+i);
        }
    }
}
