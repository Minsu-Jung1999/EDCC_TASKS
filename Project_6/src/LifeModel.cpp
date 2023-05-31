/*
 * Project 6
 * Minsu Jung
 *
 * This file provides functionality to initialize,
 * update, and retrieve information from the LifeModel object, as well as outputting its grid representation.
 *
 * May 26, 2023
*/
#include "LifeModel.h"
#include <fstream>
#include <limits>
#include <iostream>

LifeModel::LifeModel(const std::string& fileName) : fileName(fileName), rows(0), cols(0)
{
    std::ifstream file(fileName);
    if (file.is_open())
    {
        file >> rows;
        file >> cols;
        grid.resize(rows, std::vector<char>(cols));

        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        for (int row = 0; row < rows; row++) {
            std::string line;
            std::getline(file, line);
            for (int col = 0; col < cols; col++) {
                grid[row][col] = line[col];
            }
        }
        file.close();
    }
    else
    {
        std::cout << "Failed to open the file." << std::endl;
    }
}

// Returns the number of rows in the grid.
int LifeModel::getRows() const
{
    return rows;
}

// Returns the number of columns in the grid.
int LifeModel::getCols() const
{
    return cols;
}

// Checks if the cell at the specified row and column is alive ('X') or dead ('-').
bool LifeModel::isAlive(int row, int col) const
{
    return grid[row][col] == 'X';
}

// Counts the number of live neighbors for the cell at the specified row and column.
int LifeModel::countNeighbors(int row, int col) const
{
    int count = 0;

    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i >= 0 && i < rows && j >= 0 && j < cols && !(i == row && j == col) && grid[i][j] == 'X') {
                count++;
            }
        }
    }

    return count;
}

// Updates the grid to the next generation based on the rules of the Game of Life.
void LifeModel::update()
{
    std::vector<std::vector<char>> newGenerationGrid(rows, std::vector<char>(cols));

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            int neighbors = countNeighbors(row, col);

            if (neighbors <= 1) {
                newGenerationGrid[row][col] = '-';
            }
            else if (neighbors == 2) {
                // Do nothing, the new grid already contains the same value
                newGenerationGrid[row][col] = grid[row][col];
            }
            else if (neighbors == 3) {
                newGenerationGrid[row][col] = 'X';
            }
            else {
                newGenerationGrid[row][col] = '-';
            }
        }
    }

    // update the new generations and store it into grid
    grid = std::move(newGenerationGrid);
}

// Overloaded << operator to output the grid representation of the LifeModel object.
std::ostream& operator<<(std::ostream& os, const LifeModel& model)
{
    for (int row = 0; row < model.getRows(); row++)
    {
        for (int col = 0; col < model.getCols(); col++) {
            os << model.grid[row][col] << " ";
        }
        os << std::endl;
    }
    return os;
}
