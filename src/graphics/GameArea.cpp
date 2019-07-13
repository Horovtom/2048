#include <utility>

#include <utility>

#include <iostream>
#include "graphics/GameArea.h"

GameArea::GameArea() {
}

GameArea::~GameArea() {
}

bool GameArea::on_draw(const Cairo::RefPtr<Cairo::Context> &cr) {
    Gtk::Allocation allocation = get_allocation();
    // Minus padding on the right:
    int width = allocation.get_width() - SIDE_OFFSET;
    int height = allocation.get_height() - SIDE_OFFSET;


    // Draw background
    cr->set_source_rgb(COLOR_WHITE);
    draw_rectangle(cr, 0, 0, width, height);

    cr->translate(SIDE_OFFSET, SIDE_OFFSET);
    width -= SIDE_OFFSET;
    height -= SIDE_OFFSET;

    // Draw score text
    cr->set_source_rgb(COLOR_BLACK);
    draw_text(cr, 0, 0, std::to_string(score));

    // Move to the location of the grid
    cr->translate(0, SIDE_OFFSET + TEXT_HEIGHT);
    height -= SIDE_OFFSET + TEXT_HEIGHT;

    drawGrid(cr, width, height);

    cr->set_source_rgb(COLOR_BLACK);
    if (!prompt.empty()) {
        draw_text(cr, width / 4, height / 2, prompt, width / 32);
    }

    return true;
}

void GameArea::draw_rectangle(const Cairo::RefPtr<Cairo::Context> &cr,
                              int x, int y, int width, int height) {
    cr->rectangle(x, y, width, height);
    cr->fill();
}

void GameArea::draw_text(const Cairo::RefPtr<Cairo::Context> &cr,
                         int x, int y, const std::string &t, int fontSize) {
    Pango::FontDescription font;

    font.set_family("Monospace");
    font.set_weight(Pango::WEIGHT_BOLD);
    if (fontSize != 0) {
        font.set_absolute_size(fontSize * Pango::SCALE);
    }

    auto layout = create_pango_layout(t);

    layout->set_font_description(font);


    // Position the text in the middle
    cr->move_to(x, y);

    layout->show_in_cairo_context(cr);
}

void GameArea::setData(std::vector<std::vector<int>> d, int width, int height, int s) {
    data = std::move(d);
    score = s;
    dataWidth = width;
    dataHeight = height;
    queue_draw();
}

void GameArea::drawGrid(const Cairo::RefPtr<Cairo::Context> &cr, const int width, const int height) {
    if (dataWidth <= 0 || dataHeight <= 0) return;

    int cellSize = std::min(((width - (CELL_PADDING * (dataWidth - 1)) / dataWidth)),
                            ((height - (CELL_PADDING * (dataHeight - 1))) / dataHeight));
    int halfCellSize = cellSize / 2;
//    std::cout << "Width: " << width << " height: " << height << std::endl;
//    std::cout << "cellSize: " << cellSize << std::endl;
//    std::cout << "Total taken width: " << (CELL_PADDING * (dataWidth - 1) + cellSize * dataWidth) << std::endl;
//    std::cout << "Total taken height: " << (CELL_PADDING * (dataHeight - 1)  + cellSize * dataHeight) << std::endl;

    for (int x = 0; x < dataWidth; ++x) {
        for (int y = 0; y < dataHeight; ++y) {
            int startX = x * (cellSize + CELL_PADDING);
            int startY = y * (cellSize + CELL_PADDING);

            int number = data.at(x).at(y);
            if (number == 0)
                cr->set_source_rgba(EMPTY_TILE_COLOR);
            else
                setColorForNumber(cr, number);
            draw_rectangle(cr, startX, startY, cellSize, cellSize);
            if (number != 0) {
                cr->set_source_rgb(COLOR_BLACK);
                drawNumber(cr, number, startX + halfCellSize, startY + halfCellSize, cellSize);
            }
        }
    }
}

void GameArea::setColorForNumber(const Cairo::RefPtr<Cairo::Context> &cr, int number) {
    int index = static_cast<int>(std::log2(number)) - 1;
    int maxIndex = sizeof(colorList) / sizeof(colorList[0]) - 1;
    index %= (maxIndex + 1);
//    std::cout << "  Index at: " << index << std::endl;
    cr->set_source_rgba(colorList[index].r, colorList[index].g, colorList[index].b, TILE_ALPHA);
}

void GameArea::drawNumber(const Cairo::RefPtr<Cairo::Context> &cr, int number, int x, int y, int maxSize) {
    Pango::FontDescription font;

    font.set_family("Monospace");
    font.set_weight(Pango::WEIGHT_BOLD);
    font.set_absolute_size(maxSize / 4 * Pango::SCALE);

    auto layout = create_pango_layout(std::to_string(number));
    layout->set_font_description(font);

    int textWidth;
    int textHeight;

    //get the text dimensions (it updates the variables -- by reference)
    layout->get_pixel_size(textWidth, textHeight);

    x -= textWidth / 2;
    y -= textHeight / 2;
    // Position the text in the middle
    cr->move_to(x, y);

    layout->show_in_cairo_context(cr);
}

void GameArea::enablePrompt(std::string promptText) {
    prompt = promptText;
}

void GameArea::disablePrompt() {
    prompt = "";
}
