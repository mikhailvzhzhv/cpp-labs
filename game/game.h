#pragma once

#include "./factory/factory.h"
#include "./game_objects/bullet.h"
#include "./game_objects/spaceship.h"
#include "./game_objects/invadership.h"
#include "./context/context.h"
#include "./game_screen/game_screen.h"
#include "./score_table/score_table.h"
#include "./save_table/save_table.h"

#include <iostream>
#include <stdio.h>
#include <curses.h>
#include <chrono>
#include <vector>
#include <algorithm>

namespace game
{

class Game {
private:
    int width_;
    int height_;
    steady_clock_t time_;

    void createInvader(ObjectFactory& f, gameobj::Context& ctx);
    void train(gameobj::Context& ctx, 
               score_table::ScoreTable& tb, 
               game_screen::GameScreen& gamescr, 
               ObjectFactory& f);
    void survival(gameobj::Context& ctx, 
                  score_table::ScoreTable& tb, 
                  game_screen::GameScreen& gamescr, 
                  ObjectFactory& f, 
                  save_table::SaveTable& svtb);
    void action(gameobj::Context& ctx, 
                game_screen::GameScreen& gamescr, 
                score_table::ScoreTable& tb);

public:
    void run();
};

}