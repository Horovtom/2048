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

    void restartPressed();

    void spacePressed();

private:
    Game *game;
    GameWindow *window;
    bool restartPrompt;
    Player *player;
};


#endif //INC_2048_CONTROLLER_H
