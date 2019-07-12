#include "Grid.h"
#include <iostream>

Grid::Grid() {
    std::cout << "I am in the constructor of Grid" << std::endl;
}

std::vector<int> Grid::getGrid() {
    std::cout << "Getting grid!" << std::endl;
    return std::vector<int>(grid);
}

bool Grid::makeTurn(Direction direction) {
    std::cout << "Making turn to " << direction << std::endl;
    return false;
}