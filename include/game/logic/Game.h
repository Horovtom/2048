//
// Created by lactosis on 12.7.19.
//

#ifndef __GAME_H
#define __GAME_H

#include <game/logic/Grid.h>
#include <ai/Player.h>
#include <ai/HumanPlayer.h>

class Game {
public:
    explicit Game(int width = 4, int height = 4, Player *player = new HumanPlayer());

    std::vector<std::vector<int>> getState();

    int getWidth();

    int getHeight();

    int getScore();

    void makeTurn(Direction direction);

    void resetGame();

    bool gameOver();

    Player *getPlayer();

    void nextTurn();

private:
    Player *player;
    Grid grid;
    int w;
    int h;
};

#endif