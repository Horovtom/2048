//
// Created by lactosis on 13.7.19.
//

#ifndef INC_2048_GAMEWINDOW_H
#define INC_2048_GAMEWINDOW_H


#include <gtkmm.h>
#include <graphics/GameArea.h>

class Controller;

class GameWindow : public Gtk::Window {
public:

    GameWindow();

    virtual ~GameWindow();

    void registerController(Controller *controller);

    void setData(std::vector<std::vector<int>> data, int width, int height, int score);

    void showPrompt(std::string promptText);

private:
    //Override default signal handler:
    bool on_key_press_event(GdkEventKey *event) override;

    Controller *controller = nullptr;
    GameArea area;
};

#endif //INC_2048_GAMEWINDOW_H
