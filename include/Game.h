#ifndef __GAME_H
#define __GAME_H
#include "Grid.h"

class Game {
public:
    Game();
    void run();
    void init();
private: 
    Grid grid;
};

#endif