#ifndef __GRID_H
#define __GRID_H
#include <vector>
#include "Direction.h"

class Grid {
public:
    static const int EMPTY = 0;

    typedef struct Coord {
        int x, y;
    } Coord;

    Grid(std::vector<int> grid, int width, int height);
    Grid(int width, int height);
    std::vector<int> getGrid();

    /**
     * Returns whether the game is over
     */
    bool makeTurn(Direction direction);
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