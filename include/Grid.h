#ifndef __GRID_H
#define __GRID_H
#include <vector>
#include "Direction.h"

class Grid {
public:
    Grid();
    std::vector<int> getGrid();

    /**
     * Returns whether the game is over
     */
    bool makeTurn(Direction direction);
private:
    std::vector<int> grid;
    int score = 0;
};



#endif