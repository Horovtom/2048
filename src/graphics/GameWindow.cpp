#include <utility>

//
// Created by lactosis on 13.7.19.
//

#include <iostream>
#include <graphics/GameWindow.h>
#include <game/Controller.h>

GameWindow::GameWindow() {
    set_border_width(10);
    add(area);

    // Events.
    // We override the default event signal handler.
    add_events(Gdk::KEY_PRESS_MASK);

    show_all_children();
}

bool GameWindow::on_key_press_event(GdkEventKey *key_event) {
    //GDK_KEY_1 -> the '1' key
    //GDK_KEY_2 -> the '2' key

    //select the first radio button, when we press alt + 1
    if (key_event->keyval == GDK_KEY_Left) {
        controller->onUserAction(LEFT);
    } else if (key_event->keyval == GDK_KEY_Right) {
        controller->onUserAction(RIGHT);
    } else if (key_event->keyval == GDK_KEY_Up) {
        controller->onUserAction(UP);
    } else if (key_event->keyval == GDK_KEY_Down) {
        controller->onUserAction(DOWN);
    } else if (key_event->keyval == GDK_KEY_Escape) {
        //close the window, when the 'esc' key is pressed
        hide();
    } else if (key_event->keyval == GDK_KEY_BackSpace) {
        // TODO: Take back a move!
        controller->rollback();
    } else if (key_event->keyval == GDK_KEY_space) {
        controller->spacePressed();
    } else {
        //if the event has not been handled, call the base class
        return Gtk::Window::on_key_press_event(key_event);
    }
    //returning true, cancels the propagation of the event
    queue_draw();
    return true;
}

GameWindow::~GameWindow() = default;

void GameWindow::registerController(Controller *c) {
    if (controller != nullptr) {
        std::cerr << "Trying to register another controller, while this has already one registered." << std::endl;
        return;
    }
    controller = c;
    controller->update();
}

void GameWindow::setData(std::vector<std::vector<int>> d, int width, int height, int score) {
    area.setData(std::move(d), width, height, score);
}

void GameWindow::showPrompt(std::string promptText) {
    // TODO: IMPLEMENT
}
