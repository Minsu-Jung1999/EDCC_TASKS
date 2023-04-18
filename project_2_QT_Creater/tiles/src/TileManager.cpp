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
    window.setColor("Yellow");
    window.setLineWidth(10);
    for(auto& tile: tiles)
    {
        if(tile.contains(x,y))
        {
            window.drawRect(tile.getX()-5,tile.getY()-5,tile.getWidth()+5,tile.getHeight()+5);
        }
    }
}
void TileManager::raise(int x, int y)
{
    cout<<"raise()"<<endl;
}
void TileManager::lower(int x, int y)
{
    cout<<"lower()"<<endl;
}
void TileManager::remove(int x, int y)
{
    cout<<"remove()"<<endl;
}
void TileManager::removeAll(int x, int y)
{
    cout<<"removeAll()"<<endl;
}
