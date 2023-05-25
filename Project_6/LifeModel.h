#pragma once
#include <iostream>
#include <vector>

class LifeModel
{
private:

    int rows;
    int cols;
    std::vector<std::vector<char>> grid;
    std::vector<std::vector<char>> newGenerationGrid;
    std::string fileName;

public:

    LifeModel(std::string fileName);
    int getRows() const;
    int getCols() const;
    bool isAlive(int row, int col) const;
    void update();
    int countNeighbors(int row, int col) const;
    friend std::ostream& operator<<(std::ostream& os, const LifeModel& model);

};
