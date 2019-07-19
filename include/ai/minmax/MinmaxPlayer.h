//
// Created by lactosis on 19.7.19.
//

#ifndef INC_2048_MINMAXPLAYER_H
#define INC_2048_MINMAXPLAYER_H

#include <ai/Player.h>

class MinmaxPlayer : public Player {
public:
    Direction makeMove(Grid grid) override;
//    bool isInteractive() override;
//    void userPromptedTurn(Direction direction) override;
};


#endif //INC_2048_MINMAXPLAYER_H
