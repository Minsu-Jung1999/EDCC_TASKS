/*
 * Project 6
 * Minsu Jung
 *
 * This code implements the LifeGui class, which is responsible for visualizing the LifeModel using a graphical window.
 * It creates a graphical window, initializes necessary variables, and provides functions to update and draw the LifeModel grid in the window.
 *
 * May 26, 2023
*/

#include <iostream>
#include <unistd.h>
#include "LifeGui.h"
#include "console.h"
#include "gwindow.h"
using namespace sgl;
using namespace std;


// Constructor for the LifeGui class.
// Initializes the LifeGui object with the given LifeModel pointer.
// It sets up the graphical window and initializes other necessary variables.
LifeGui::LifeGui(LifeModel* modelPointer)
    : lifeModel(modelPointer),
    aliveColor("yellow"),
    deadColor("black"),
    window(nullptr),
    width(0),
    height(0),
    cellSize(10),
    rows(0),
    cols(0)
{
    lifeModel->update();

    rows = lifeModel->getRows();
    cols = lifeModel->getCols();
    width = cols * cellSize;
    height = rows * cellSize;

    // Window settings
    window = new GWindow(width, height);
    window->setExitOnClose(false);
    window->setSize(width, height);
    window->setWindowTitle("LifeGui");
    window->setLineWidth(1);
}

// Draws a rectangle with the specified color at the given position and size.
void LifeGui::drawRect(std::string color, int x, int y, const int cellSize) const
{
    window->setColor(color);
    window->setFillColor(color);
    window->fillRect(x, y, cellSize, cellSize);
}

// Checks if the GUI window is open or not.
// Returns true if the window is open, false otherwise.
bool LifeGui::isWindowOpen() const
{
    return window->isOpen();
}

// Updates the Vector of the LifeModel in the window.
// Clears the window, updates the LifeModel, and redraws the rectangles in the window.
void LifeGui::update() const
{
    lifeModel->update();
    window->clear();

    int x = 0;
    int y = 0;

    // Draw the rectangles in the new window with color
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            string color = lifeModel->isAlive(row, col) ? aliveColor : deadColor;
            drawRect(color, x, y, cellSize);
            x += cellSize;
        }
        y += cellSize;
        x = 0;
    }

    window->repaint();
    usleep(500000);
}
