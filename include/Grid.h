//
// Created by lactosis on 12.7.19.
//

#ifndef __GRID_H
#define __GRID_H
#include <vector>
#include "Direction.h"

class Grid {
public:
    const int EMPTY = 0;

    typedef struct Coord {
        int x, y;
    } Coord;

    Grid(std::vector<int> grid, int width, int height);
    Grid(int width, int height);
    std::vector<int> getGrid();

    /**
     * Makes turn modifying the current grid
     * @param direction to which we swiped
     * @return whether the turn was valid
     */
    bool makeTurn(Direction direction);

    void setGrid(std::vector<int> g);
private:
    std::vector<int> grid;
    int w;
    int h;
    int score = 0;
    int coordToIndex(Coord coord);
    Coord indexToCoord(int index);
    void addRandomTile();
    int occupiedTiles();
    std::vector<int> getFreePlaces();
    bool canMakeTurn();
};



#endif