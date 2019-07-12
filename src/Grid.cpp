#include "Grid.h"
#include <iostream>

Grid::Grid(int width, int height): w(width), h(height) {
    std::cout << "I am in the constructor of Grid with w: " << w << " h: " << h  << std::endl;
    grid.reserve(w * h);
    
}



std::vector<int> Grid::getGrid() {
    std::cout << "Getting grid!" << std::endl;
    return std::vector<int>(grid);
}

bool Grid::makeTurn(Direction direction) {
    std::cout << "Making turn to " << direction << std::endl;
    
    return false;
}

int Grid::coordToIndex(Grid::Coord coord) {
    return coord.x + coord.y * w;
}

Grid::Coord Grid::indexToCoord(int index) {
    return {index % w, index / w};
}