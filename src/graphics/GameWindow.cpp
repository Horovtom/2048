//
// Created by lactosis on 13.7.19.
//

#include <iostream>
#include "graphics/GameWindow.h"

GameWindow::GameWindow() {
//    set_border_width(10);
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
        area.setText("Pressed left!");
    } else if (key_event->keyval == GDK_KEY_Right) {
        area.setText("Pressed right!");
    } else if (key_event->keyval == GDK_KEY_Up) {
        area.setText("Pressed up!");
    } else if (key_event->keyval == GDK_KEY_Down) {
        area.setText("Pressed down!");
    } else if (key_event->keyval == GDK_KEY_Escape) {
        //close the window, when the 'esc' key is pressed
        hide();
    } else {
        //if the event has not been handled, call the base class
        return Gtk::Window::on_key_press_event(key_event);
    }
    //returning true, cancels the propagation of the event
    return true;
}

GameWindow::~GameWindow() = default;