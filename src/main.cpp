//
// Created by lactosis on 12.7.19.
//

#include "game/logic/Game.h"
#include "graphics/GameArea.h"
#include "graphics/GameWindow.h"
#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include "game/Controller.h"


int runWithGraphics(int argc, char **argv) {
    Game game(4, 4);

    auto app = Gtk::Application::create(argc, argv, "com.github.horovtom.bot-2048");
    GameWindow window;

    window.set_default_size(640, 660);
    window.set_title("Game: 2048");
    Controller controller(&game, &window);

    return app->run(window);
}

int main(int argc, char *argv[]) {

    return runWithGraphics(argc, argv);
}