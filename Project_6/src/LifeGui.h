/*
 * Project 6
 * Minsu Jung
 *
 * This is a header file that contains the declaration of the LifeGui class.
 * It provides functionality for visualizing a LifeModel using a graphical window.
 *
 * May 26, 2023
*/
#ifndef LIFEGUI_H
#define LIFEGUI_H

#include <iostream>
#include <string>
#include "LifeModel.h"
#include "gwindow.h"
using namespace sgl;
class LifeGui {
private:
    LifeModel* lifeModel; // Pointer to the LifeModel object
    std::string aliveColor; // Color for representing live cells
    std::string deadColor; // Color for representing dead cells
    GWindow* window; // Pointer to the graphical window
    const int cellSize;
    int width; // Width of the window
    int height; // Height of the window
    int rows; // Number of rows in the LifeModel grid
    int cols; // Number of columns in the LifeModel grid

    void drawRect(std::string color, int x, int y, int cellSize) const; // Draws a rectangle with the specified color at the given position and size.

public:
    // Constructor for the LifeGui class.
    // Initializes the LifeGui object with the given LifeModel pointer.
    LifeGui(LifeModel* modelPointer);

    // Updates the graphical representation of the LifeModel in the window.
    void update() const;

    // Checks if the graphical window is open or not.
    // Returns true if the window is open, false otherwise.
    bool isWindowOpen() const;
};

#endif // LIFEGUI_H
