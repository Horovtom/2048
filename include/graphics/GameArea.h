#ifndef __GAME_AREA_H
#define __GAME_AREA_H

#include <gtkmm/drawingarea.h>

#define COLOR_WHITE 1.0, 1.0, 1.0
#define COLOR_BLACK 0.0, 0.0, 0.0
#define EMPTY_TILE_COLOR 0.0, 0.0, 0.0, 0.1

class GameArea : public Gtk::DrawingArea {
public:
    GameArea();

    virtual ~GameArea();

    void setData(std::vector<std::vector<int>> data, int width, int height, int score);

    void enablePrompt(std::string promptText);

    void disablePrompt();

protected:
    //Override default signal handler:
    bool on_draw(const Cairo::RefPtr<Cairo::Context> &cr) override;

private:
    void draw_rectangle(const Cairo::RefPtr<Cairo::Context> &cr, int x, int y, int width, int height);

    void draw_text(const Cairo::RefPtr<Cairo::Context> &cr, int x, int y, const std::string &text, int fontSize = 0);

    const int SIDE_OFFSET = 5;
    const int TEXT_HEIGHT = 15;
    const int CELL_PADDING = 3;
    const float TILE_ALPHA = 0.7;
    int dataWidth = 0;
    int dataHeight = 0;
    std::vector<std::vector<int>> data;
    int score = 0;

    void drawGrid(const Cairo::RefPtr<Cairo::Context> &cr, const int i, int i1);

    void drawNumber(const Cairo::RefPtr<Cairo::Context> &cr, int number, int x, int y, int maxSize);

    const struct {
        double r, g, b;
    } colorList[13] = {
            {0.0, 0.0, 0.0}, //2
            {0.5, 0.0, 0.0}, //4
            {0.0, 0.5, 0.0}, //8
            {0.0, 0.0, 0.5}, //16
            {0.5, 0.5, 0.0}, //32
            {0.0, 0.5, 0.5}, //64
            {0.5, 0.0, 0.5}, //128
            {0.2, 0.5, 0.7}, //256
            {0.7, 0.2, 0.5}, //512
            {0.5, 0.7, 0.2}, //1024
            {0.7, 0.2, 0.7}, //2048
            {0.2, 0.7, 0.2}, //4096
            {0.7, 0.7, 0.2}, //8192
    };

    void setColorForNumber(const Cairo::RefPtr<Cairo::Context> &cr, int number);

    std::string prompt = "";
};

#endif //__GAME_AREA_H