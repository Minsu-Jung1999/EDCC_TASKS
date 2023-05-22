#include "LifeModel.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

LifeModel::LifeModel(std::string fileName) : fileName(fileName),rows(0), cols(0)
{
	ifstream file(fileName);
	if (file.is_open())
	{
		file >> rows;
		file >> cols;
		grid.resize(rows, vector<char>(cols));
		// consume the remaining newline character after reading cols
		file.ignore(numeric_limits<streamsize>::max(), '\n');
		// store data into the vector gird
		for (int i = 0; i < rows; i++) {
			string line;
			getline(file, line);
			for (int j = 0; j < cols; j++) {
				grid[i][j] = line[j];
			}
		}
		file.close();
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout << grid[i][j]<<" ";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "Faild to open the file." << endl;
	}

	cout << " Row 3 and Column 4 is = " << grid[2][3] << endl;
}

int LifeModel::getRows() const
{
	return rows;
}

int LifeModel::getCols() const
{
	return cols;
}

bool LifeModel::isAlive(int row, int col) const
{
	return false;
}
int LifeModel::countNeighbors(int row, int col) const
{
	int count = 0;

	// Check the eight neighboring cells
	for (int i = row - 1; i <= row + 1; i++) {
		for (int j = col - 1; j <= col + 1; j++) {
			// Skip the current cell
			if (i == row && j == col) {
				continue;
			}

			// Check if the neighboring cell is within the grid boundaries and contains a cell
			if (i >= 0 && i < rows && j >= 0 && j < cols && grid[i][j] == 'X') {
				count++;
			}
		}
	}

	return count;
}

void LifeModel::update()
{
	vector<vector<char>> newGrid = grid; // Create a new grid to store the updated state

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			int neighbors = countNeighbors(i, j); // Count the number of neighbors for the current cell

			if (neighbors <= 1) {
				// Zero or one neighbor: the cell dies or remains empty
				newGrid[i][j] = '-';
			}
			else if (neighbors == 2) {
				// Two neighbors: the cell remains stable
				// Do nothing, the new grid already contains the same value
			}
			else if (neighbors == 3) {
				// Three neighbors: a new cell is born or the existing cell remains
				if (grid[i][j] == '-') {
					newGrid[i][j] = 'X'; // Birth of a new cell
				}
				// Existing cell remains, no need to modify newGrid
			}
			else {
				// Four or more neighbors: the cell dies of overcrowding
				newGrid[i][j] = '-';
			}
		}
	}

	grid = newGrid; // Update the original grid with the new state
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) {
			cout << newGrid[i][j] << " ";
		}
		cout << endl;
	}
}

std::ostream& operator<<(std::ostream& os, const LifeModel& model)
{
	os << "Rows : " << model.getRows() << endl << "Columns : " << model.getCols() << endl;
	return os;
}
