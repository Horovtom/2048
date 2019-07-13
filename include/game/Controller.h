//
// Created by lactosis on 13.7.19.
//

#ifndef INC_2048_CONTROLLER_H
#define INC_2048_CONTROLLER_H


#include <game/logic/Game.h>
#include <graphics/GameWindow.h>

class Controller {

public:
    Controller(Game *pGame, GameWindow *pWindow);

    void onUserAction(Direction direction);

    void update();

    void rollback();

    void spacePressed();

private:
    Game *game;
    GameWindow *window;
};


#endif //INC_2048_CONTROLLER_H
