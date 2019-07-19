//
// Created by lactosis on 19.7.19.
//

#ifndef INC_2048_HUMANPLAYER_H
#define INC_2048_HUMANPLAYER_H


#include <ai/Player.h>

class HumanPlayer : public Player {
public:
    Direction makeMove(Grid grid) override;

    bool isInteractive() override;

    void userPromptedTurn(Direction direction) override;

private:
    Direction turnPrompted = UP;
};


#endif //INC_2048_HUMANPLAYER_H
