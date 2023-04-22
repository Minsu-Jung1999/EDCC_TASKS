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
using namespace sgl;
class TileManager
{
private:
    std::vector<Tile> tiles;
public:
    TileManager();
    // Adds a new Tile object to the bottom of the tiles vector.
    void addBottom(Tile& rect);

    //  Adds a new Tile object to the top of the tiles vector.
    void addTop(Tile& rect);

    //  Draws all the Tile objects in the tiles vector on the provided GWindow.
    void drawAll(GWindow& window);

    // Clear the Tile vector.
    void clear();

    // Highlights the Tile at the specified coordinates (x,y) on the provided GWindow.
    void highlight(int x, int y, GWindow& window);

    // Moves the Tile at the specified coordinates (x,y) one position higher in the tiles vector.
    void raise(int x, int y);

    // Moves the Tile at the specified coordinates (x,y) one position lower in the tiles vector.
    void lower(int x, int y);

    //  Removes the Tile at the specified coordinates (x,y) from the tiles vector.
    void remove(int x, int y);

    // Removes all Tile objects at the specified coordinates (x,y) from the tiles vector.
    void removeAll(int x, int y);

};
