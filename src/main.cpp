//
// Created by lactosis on 12.7.19.
//

#include "game/logic/Game.h"
#include "graphics/GameArea.h"
#include "graphics/GameWindow.h"
#include <gtkmm/application.h>
#include <gtkmm/window.h>


int runGraphics(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "com.github.horovtom.bot-2048");

    GameWindow window;

    window.set_default_size(640, 640);
    window.set_title("Game: 2048");

    return app->run(window);
}

int main(int argc, char *argv[]) {

    return runGraphics(argc, argv);
}