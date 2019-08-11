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

    bool canMakeTurn(Direction direction);

    /**
     * Makes turn modifying the current grid
     * @param direction to which we swiped
     * @return whether the turn was valid
     */
    bool makeTurn(Direction direction);

    void setGrid(std::vector<int> g);

    std::string toString();

    double getScore() const;

    std::vector<std::vector<int>> getGrid2D();

    void resetGrid();

    int getWidth() { return w; }

    int getHeight() { return h; }

    int occupiedTilesCount();

protected:
    const double PROB_4 = 0.10;

    /**
     * Will shift tiles in specified direction and merge those that are to be merged.
     * @return Whether any tile has been affected by the shift.
     */
    bool shift(Direction direction);

    std::vector<int> getFreePlaces();

    void setAt(int index, int value);

    int w;
    int h;

private:
    std::vector<int> grid;

    int coordToIndex(Coord coord);
    Coord indexToCoord(int index);
    void addRandomTile();
};



#endif