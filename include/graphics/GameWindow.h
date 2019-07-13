//
// Created by lactosis on 13.7.19.
//

#ifndef INC_2048_GAMEWINDOW_H
#define INC_2048_GAMEWINDOW_H


#include <gtkmm.h>
#include "GameArea.h"

class GameWindow : public Gtk::Window {
public:

    GameWindow();

    virtual ~GameWindow();

private:
    //Override default signal handler:
    bool on_key_press_event(GdkEventKey *event) override;

    GameArea area;
};

#endif //INC_2048_GAMEWINDOW_H
