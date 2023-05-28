/*
 * Project 6
 * Minsu Jung
 *
 * LifeModel class represents the model for the Game of Life.
 * It stores the grid of cells and provides methods to manipulate and retrieve information about the grid.
 *
 * May 26, 2023
*/

#pragma once
#include <iostream>
#include <vector>

//
class LifeModel
{
private:
    int rows;                                 // Number of rows in the grid
    int cols;                                 // Number of columns in the grid
    std::vector<std::vector<char>> grid;      // Grid of cells represented by a 2D vector
    std::string fileName;                     // File name from which the grid is loaded

public:
    // Constructor that initializes the LifeModel object with the given file name.
    LifeModel(const std::string& fileName);

    // Returns the number of rows in the grid.
    int getRows() const;

    // Returns the number of columns in the grid.
    int getCols() const;

    // Checks if the cell at the specified row and column is alive ('X') or dead ('-').
    bool isAlive(int row, int col) const;

    // Updates the grid to the next generation based on the rules of the Game of Life.
    void update();

    // Counts the number of live neighbors for the cell at the specified row and column.
    int countNeighbors(int row, int col) const;

    // Overloaded << operator to output the grid representation of the LifeModel object.
    friend std::ostream& operator<<(std::ostream& os, const LifeModel& model);
};
