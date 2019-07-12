//
// Created by lactosis on 12.7.19.
//

#include "Grid.h"
#include <iostream>
#include <random>

Grid::Grid(int width, int height): w(width), h(height) {
    grid.reserve(w * h);
    for (int i = 0; i < w * h; ++i) {
        grid.push_back(EMPTY);
    }

    addRandomTile();
    addRandomTile();
}

Grid::Grid(std::vector<int> grid, int width, int height): w(width), h(height) {
    setGrid(std::move(grid));
}

void Grid::setGrid(std::vector<int> g) {
    grid = std::move(g);
    if (grid.size() != w * h) {
        std::cerr << "Invalid grid size: " << grid.size() << "! It should be " << w * h << " tiles long!" << std::endl;
        exit(-1);
    }
}

std::vector<int> Grid::getGrid() {
    return std::vector<int>(grid);
}

bool Grid::makeTurn(Direction direction) {
    std::cout << "Making turn to " << direction << std::endl;

    int currentIndex, increment, nextLine, stop, stop2;

    switch(direction) {
        case RIGHT:
            currentIndex = 15;
            increment = nextLine = -1;
            stop = w; stop2 = h;
            break;

        case LEFT:
            currentIndex = 0;
            increment = nextLine = 1;
            stop = w; stop2 = h;
            break;

        case DOWN:
            currentIndex = 15;
            increment = -w;
            nextLine = (w * (h - 1)) - 1;
            stop = h; stop2= w;
            break;

        case UP:
            currentIndex = 0;
            increment = w;
            nextLine = - (w * (h - 1)) + 1;
            stop = h; stop2 = w;
            break;

        default:
            std::cerr<< "Error! Invalid direction!" << std::endl;
            exit(-1);
    }

    bool changedSomething = false;

    for (int r = 0; r < stop2; ++r) {
        int lastIndex = currentIndex;
        int lastValue = grid.at(lastIndex);

        for (int i = stop - 2; i >= 0; --i) {
            currentIndex += increment;
            int currentValue = grid.at(currentIndex);

            if (currentValue == EMPTY)
                continue;

            // CurrentValue is not empty by now
            if (lastValue == EMPTY) {
                // Move
                grid.at(lastIndex) = currentValue;
                grid.at(currentIndex) = EMPTY;
                changedSomething = true;
            } else if (lastValue == currentValue) {
                // Merge
                grid.at(lastIndex) = 2*currentValue;
                grid.at(currentIndex) = EMPTY;
                changedSomething = true;
            } else {
                // They are different. Just snap it to next index
                lastIndex += increment;
                if (lastIndex != currentIndex) {
                    grid.at(lastIndex) = currentValue;
                    grid.at(currentValue) = EMPTY;
                    changedSomething = true;
                }
            }
            lastIndex += increment;
            lastValue = grid.at(lastIndex);
        }
        currentIndex += nextLine;
    }

    if (changedSomething)
        addRandomTile();

    return changedSomething;
}

bool Grid::canMakeTurn() {
    for (int i = 0; i < h - 1; i++) {
        for (int j = 0; j < w - 1 ; j++) {
            int index = grid.at(coordToIndex({i, j}));
            int ahead = grid.at(coordToIndex({i+1, j}));
            int below = grid.at(coordToIndex({i, j+1}));
            if (index == 0 || ahead == 0 || below == 0) return true;
            if (index == ahead || index == below) return true;
        }
    }
    return false;
}

void Grid::addRandomTile() {
    std::vector<int> freePlaces = getFreePlaces();
    if (freePlaces.size() == 0) {
        std::cerr<< "There was no free place to put the tile to!" << std::endl;
        return;
    }

    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(0,freePlaces.size() -1);

    int tile = freePlaces.at(uni(rng));
    std::uniform_int_distribution<int> uni2(1, 4);
    int which = (uni2(rng) / 4 + 1) * 2;
    grid.at(tile) = which;
    std::cout << "Added number: " <<which << " to place: " << tile << std::endl;
}

int Grid::occupiedTiles() {
    int curr = 0;
    for (int i = 0; i < w * h; ++i) {
        if (grid.at(i) != 0) curr++;
    }
    return curr;
}

std::vector<int> Grid::getFreePlaces() {
    std::vector<int> ret;
    for (int i = 0; i < w * h; ++i) {
        if (grid.at(i) == 0) ret.push_back(i);
    }

    return ret;
}

int Grid::coordToIndex(Grid::Coord coord) {
    return coord.x + coord.y * w;
}

Grid::Coord Grid::indexToCoord(int index) {
    return {index % w, index / w};
}