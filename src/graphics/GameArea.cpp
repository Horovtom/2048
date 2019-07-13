#include <utility>

#include <iostream>
#include "graphics/GameArea.h"

GameArea::GameArea() {
}

GameArea::~GameArea() {
}

bool GameArea::on_draw(const Cairo::RefPtr<Cairo::Context> &cr) {
    Gtk::Allocation allocation = get_allocation();
    const int width = allocation.get_width();
    const int height = allocation.get_height();

    // Draw a black rectangle
    cr->set_source_rgb(0.0, 0.0, 0.0);
    draw_rectangle(cr, 0, 0, width, height);

    // and some white text
    cr->set_source_rgb(1.0, 1.0, 1.0);
    draw_text(cr, 200, 300, text);

    return true;
}

void GameArea::draw_rectangle(const Cairo::RefPtr<Cairo::Context> &cr,
                              int x, int y, int width, int height) {
    cr->rectangle(x, y, width, height);
    cr->fill();
}

void GameArea::draw_text(const Cairo::RefPtr<Cairo::Context> &cr,
                         int x, int y, const std::string &t) {
    Pango::FontDescription font;

    font.set_family("Monospace");
    font.set_weight(Pango::WEIGHT_BOLD);

    auto layout = create_pango_layout(t);
//    auto layout = create_pango_layout("Hi there!");

    layout->set_font_description(font);

    int text_width;
    int text_height;

    //get the text dimensions (it updates the variables -- by reference)
    layout->get_pixel_size(text_width, text_height);

    // Position the text in the middle
    cr->move_to(x, y);

    layout->show_in_cairo_context(cr);
}

void GameArea::setText(std::string s) {
    text = std::move(s);
    queue_draw();
}