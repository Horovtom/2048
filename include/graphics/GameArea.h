#ifndef __GAME_AREA_H
#define __GAME_AREA_H

#include <gtkmm/drawingarea.h>

class GameArea : public Gtk::DrawingArea {
public:
    GameArea();

    virtual ~GameArea();

    void setText(std::string text);

protected:
    //Override default signal handler:
    bool on_draw(const Cairo::RefPtr<Cairo::Context> &cr) override;

private:
    void draw_rectangle(const Cairo::RefPtr<Cairo::Context> &cr, int x, int y, int width, int height);

    void draw_text(const Cairo::RefPtr<Cairo::Context> &cr, int x, int y, const std::string &text);

    std::string text;
};

#endif //__GAME_AREA_H