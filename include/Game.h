//
// Created by lactosis on 12.7.19.
//

#ifndef __GAME_H
#define __GAME_H
#include "Grid.h"

class Game {
public:
    Game(int width = 4, int height = 4);
    void run();
    void init();
private:
    Grid grid;
    int w;
    int h;
};

#endif