//
// Created by lactosis on 12.7.19.
//

#ifndef __GAME_H
#define __GAME_H

#include <game/logic/Grid.h>

class Game {
public:
    Game(int width = 4, int height = 4);

    std::vector<std::vector<int>> getState();

    int getWidth();

    int getHeight();

    int getScore();

    void makeTurn(Direction direction);


    void resetGame();

    bool gameOver();

private:
    Grid grid;
    int w;
    int h;
};

#endif