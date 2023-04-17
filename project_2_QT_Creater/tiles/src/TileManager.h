#include "Tile.h"
#include "gwindow.h"
using namespace sgl;
class TileManager
{
private:
    std::vector<Tile> tiles;
public:
    TileManager();
    void addBottom(Tile& rect);
    void addTop(Tile& rect);
    void drawAll(GWindow& window);
    void clear();
    void highlight(int x, int y, GWindow& window);
    void raise(int x, int y);
    void lower(int x, int y);
    void remove(int x, int y);
    void removeAll(int x, int y);

};
