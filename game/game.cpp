#include "game.h"

namespace game
{

void Game::run() {
    setlocale(LC_ALL, "");
    initscr();
    cbreak();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    timeout(50);
    
    getmaxyx(stdscr, height_, width_);
    if (width_ == -1 || height_ == -1) {
        endwin();
        std::cout << "WINDOW is not exist" << std::endl;
        return;
    }
    score_table::ScoreTable tb("score_table.txt");

    tb.parseScoreTable();
    gameobj::Context ctx;
    game_screen::GameScreen gamescr(width_, height_);
    height_ = gamescr.getH();
    width_ = gamescr.getW();

    ObjectFactory f;
    save_table::SaveTable svtb("save_table.txt");

    while (true) {
        gamescr.startMenu(tb);
        ctx.setUserInput(getch());
        if (ctx.getUserInput() == 't') {
            train(ctx, tb, gamescr, f);
        }
        else if (ctx.getUserInput() == 's') {
            gamescr.setNameMenu(ctx);
            survival(ctx, tb, gamescr, f, svtb);
        }
        else if (ctx.getUserInput() == 'l' && svtb.isSaved()) {
            survival(ctx, tb, gamescr, f, svtb);
        }
        else if (ctx.getUserInput() == 'q') {
            tb.writeScoreTable();
            endwin();
            return;
        }
    }
}

void Game::createInvader(ObjectFactory& f, gameobj::Context& ctx) {
    int rd = std::experimental::randint(-500, 0);
    if ((std::chrono::steady_clock::now() - time_) / 1ms > 2000 + rd) {
        int x = std::experimental::randint(1, width_ - 8);
        std::string name;
        if (rd % 2) {
            name  = "wInvader";
            ctx.data().push_back(f.createObject(name, x, 1, 2));
        }
        else {
            name  = "WInvader";
            ctx.data().push_back(f.createObject(name, x, 1, 2));
        }
        time_ = std::chrono::steady_clock::now();
    }
}

void Game::train(gameobj::Context& ctx, score_table::ScoreTable& tb, game_screen::GameScreen& gamescr, ObjectFactory& f) {
    std::string spaceshipName = "spaceship";
    std::string wInv = "wInvader";
    std::string WInv = "WInvader";

    ctx.data().push_back(f.createObject(spaceshipName, (width_ - spaceshipName.size())/2, 22, 10));
    for (int i = 0; i < 7; ++i) {
        if (i % 2) {
            ctx.data().push_back(f.createObject(wInv, 1 + width_ * i / 7, 1, 2));
        }
        else {
            ctx.data().push_back(f.createObject(WInv, 1 + width_ * i / 7, 1, 2));
        }
    }
    time_ = std::chrono::steady_clock::now();
    ctx.restart();
    
    while (true) {
        ctx.setUserInput(getch());
        if (ctx.getUserInput() == 'q') {
            clear();
            return;
        }
        else if (!ctx.invIsExist()) {
            gamescr.winScreen();
            break;
        }
        else if (ctx.data().at(0)->isDead()) {
            gamescr.loseScreen();
            break;
        }
             
        clear();
        action(ctx, gamescr, tb);
        refresh();
    }
    ctx.data().clear();
}

void Game::survival(gameobj::Context& ctx, score_table::ScoreTable& tb, game_screen::GameScreen& gamescr, ObjectFactory& f, save_table::SaveTable& svtb) {
    if (ctx.getUserInput() == 's') {
        std::string spaceshipName = "spaceship";
        ctx.data().push_back(f.createObject(spaceshipName, (width_ - spaceshipName.size())/2, 22, 10));
        time_ = std::chrono::steady_clock::now();
        ctx.restart();
    } 
    else {
        svtb.loadGame(ctx, f);
    }

    while (true) {
        ctx.setUserInput(getch());
        if (ctx.getUserInput() == 'q') {
            clear();
            ctx.data().clear();
            return;
        }
        if (ctx.getUserInput() == 's') {
            svtb.saveGame(ctx);
            ctx.data().clear();
            clear();
            return;
        }
        else if (ctx.data().at(0)->isDead()) {
            gamescr.scoreScreen();
            break;
        }
             
        clear();
        createInvader(f, ctx);
        action(ctx, gamescr, tb);
        refresh();
    }
    svtb.removeSave();
    tb.addScore(ctx.getName(), ctx.getPoints());
    ctx.data().clear();
}

void Game::action(gameobj::Context& ctx, game_screen::GameScreen& gamescr, score_table::ScoreTable& tb) {
    ctx.action();
    gamescr.print(ctx, tb);
}

}