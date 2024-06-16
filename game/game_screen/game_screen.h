#pragma once
#include <curses.h>
#include <iostream>
#include "../context/context.h"
#include "../score_table/score_table.h"

namespace game_screen
{

class GameScreen {
private:
    const int width_;
    const int height_;
    const int gameScreenWidth_;
    const int gameScreenHeight_;

public:
    GameScreen(int w, int h) : width_(104), height_(27), gameScreenWidth_(80), gameScreenHeight_(24) {
        if (w < 104 || h < 27) {
            endwin();
            std::cout << "WINDOW too small" << std::endl;
            std::cout << "need : width 104, height 27" << std::endl;
            std::cout << "have : width " << w << ", height " << h << std::endl;
            exit(0);
        }
        start_color();
        init_pair(1, COLOR_CYAN, COLOR_BLACK);
        init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(3, COLOR_RED, COLOR_BLACK);
    };

    ~GameScreen() = default;
    void print(gameobj::Context& ctx, score_table::ScoreTable& tb);
    void printGameScreen();
    void printStars(int pair);
    void printValues(gameobj::Context& ctx);
    int getW() const;
    int getH() const;
    void startMenu(score_table::ScoreTable &tb);
    void winScreen();
    void loseScreen();
    void scoreScreen();
    void printScoreTable(score_table::ScoreTable& tb);
    void setNameMenu(gameobj::Context& ctx);
    void printObjects(gameobj::Context& ctx);
};

}
