//
// Created by lactosis on 19.7.19.
//

#ifndef INC_2048_PLAYER_H
#define INC_2048_PLAYER_H


#include <game/logic/Direction.h>
#include <game/logic/Grid.h>

class Player {
public:
    virtual Direction makeMove(Grid grid) = 0;

    virtual bool isInteractive() = 0;

    virtual void userPromptedTurn(Direction direction) = 0;
};


#endif //INC_2048_PLAYER_H
