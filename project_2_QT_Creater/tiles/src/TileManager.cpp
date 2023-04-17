#include <iostream>
#include "TileManager.h"
#include "gwindow.h"
using namespace std;
using namespace sgl;
TileManager::TileManager()
{
    cout<<"TileManager() called"<<endl;
}

void TileManager::addBottom(Tile& rect)
{


}
void TileManager::addTop(Tile& rect)
{
    cout<<"addTop()-> rect.y"<<rect.getY()<<endl;
}
void TileManager::drawAll(GWindow& window)
{
    cout<<"drawAll()"<<endl;

}
void TileManager::clear()
{
    cout<<"clear()"<<endl;
}
void TileManager::highlight(int x, int y, GWindow& window)
{
    cout<<"highlight()"<<endl;
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
