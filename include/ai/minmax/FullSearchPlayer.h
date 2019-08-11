//
// Created by lactosis on 19.7.19.
//

#ifndef INC_2048_FULLSEARCHPLAYER_H
#define INC_2048_FULLSEARCHPLAYER_H

#include <ai/Player.h>
#include "GameState.h"

class FullSearchPlayer : public Player {
public:
    explicit FullSearchPlayer(int insight) : INSIGHT(insight) {};
    Direction makeMove(Grid grid) override;

    bool isInteractive() override;

    void userPromptedTurn(Direction direction) override;

private:
    const int INSIGHT;

    double considerDirection(GameState state, Direction direction, int depthLeft);
};


#endif //INC_2048_FULLSEARCHPLAYER_H
