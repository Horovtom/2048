//
// Created by lactosis on 12.7.19.
//

#ifndef __GRID_H
#define __GRID_H
#include <vector>
#include <string>
#include <game/logic/Direction.h>

class Grid {
public:
    const int EMPTY = 0;

    typedef struct Coord {
        int x, y;
    } Coord;

    Grid(std::vector<int> grid, int width, int height);
    Grid(int width, int height);
    std::vector<int> getGrid();

    bool canMakeTurn();

    /**
     * Makes turn modifying the current grid
     * @param direction to which we swiped
     * @return whether the turn was valid
     */
    bool makeTurn(Direction direction);

    void setGrid(std::vector<int> g);

    std::string toString();

    int getScore();

    std::vector<std::vector<int>> getGrid2D();

private:
    std::vector<int> grid;
    int w;
    int h;
    int coordToIndex(Coord coord);
    Coord indexToCoord(int index);
    void addRandomTile();

    int occupiedTilesCount();
    std::vector<int> getFreePlaces();

};



#endif