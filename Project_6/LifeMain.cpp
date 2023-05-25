#include <iostream>
#include <fstream>
#include <string>
#include "LifeModel.h"
#include "LifeGui.h"
#include "console.h"
#include "gwindow.h"
using namespace std;
using namespace sgl;

int main() {

    std::cout << "Welcome to the CS 132 Game of Life," << std::endl;
    std::cout << "a simulation of the lifecycle of a bacteria colony." << std::endl;
    std::cout << "Cells (X) live and die by the following rules:" << std::endl;
    std::cout << "- A cell with 1 or fewer neighbors dies." << std::endl;
    std::cout << "- Locations with 2 neighbors remain stable." << std::endl;
    std::cout << "- Locations with 3 neighbors will create life." << std::endl;
    std::cout << "- A cell with 4 or more neighbors dies." << std::endl << std::endl;

    std::string fileName;
    std::cout << "Grid input file name? ";
    getline(std::cin,fileName);
    LifeModel model("res/"+fileName);
    std::cout << model; // Output initial state of the grid

    char option;
    while (true) {
        std::cout << "a)nimate, t)ick, q)uit? ";
        std::cin >> option;

        if (option == 'a') {
            LifeGui gui(&model);

            // Run animation loop until the user closes the GUI

        }
        else if (option == 't') {
            model.update();
            std::cout << model; // Output updated state of the grid
        }
        else if (option == 'q') {
            std::cout << "Have a nice Life!" << std::endl;
            break;
        }
        else {
            std::cout << "Invalid option. Please try again." << std::endl;
        }
    }

    return 0;
}
