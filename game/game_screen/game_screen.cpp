#include "game_screen.h"

namespace game_screen
{

void GameScreen::print(gameobj::Context& ctx, score_table::ScoreTable& tb) {
    printGameScreen();
    printStars(1);
    printValues(ctx);
    printScoreTable(tb);
    printObjects(ctx);
}

void GameScreen::printValues(gameobj::Context& ctx) {
    wmove(stdscr, gameScreenHeight_ + 1, 1);
    wprintw(stdscr, "HP : %d", ctx.getHP() < 0 ? 0 : ctx.getHP());

    wmove(stdscr, gameScreenHeight_ + 1, gameScreenWidth_ / 4);
    wprintw(stdscr, "Shots : %d", ctx.getBulletCount());

    wmove(stdscr, gameScreenHeight_ + 1, gameScreenWidth_ / 2);
    wprintw(stdscr, "Seconds : %d", ctx.getSeconds());

    wmove(stdscr, gameScreenHeight_ + 1, gameScreenWidth_ / 4 * 3);
    wprintw(stdscr, "Score : %d", ctx.getPoints());
}

void GameScreen::printGameScreen() {
    for (int h = 1; h < gameScreenHeight_ - 1; ++h) {
        mvprintw(h, 0, "|");
        mvprintw(h, gameScreenWidth_-1, "|");
    }
    for (int w = 1; w < gameScreenWidth_ - 1; ++w) {
        mvprintw(0, w, "-");
        mvprintw(gameScreenHeight_-1, w, "-");
    }
    mvprintw(0, 0, "+");
    mvprintw(gameScreenHeight_-1, 0, "+");
    mvprintw(0, gameScreenWidth_-1, "+");
    mvprintw(gameScreenHeight_-1, gameScreenWidth_-1, "+");
}

void GameScreen::printStars(int pair) {
    attron(COLOR_PAIR(pair));
    mvprintw(4, 5, "*");
    mvprintw(18, 10, "*");
    mvprintw(15, 60, "*");
    mvprintw(17, 49, "*");
    mvprintw(5, 39, "*");
    mvprintw(20, 9, "*");
    attroff(COLOR_PAIR(pair));
}

int GameScreen::getW() const {
    return gameScreenWidth_;
}

int GameScreen::getH() const {
    return gameScreenHeight_;
}

void GameScreen::startMenu(score_table::ScoreTable &tb) {
    printScoreTable(tb);
    for (int i = 0; i < gameScreenWidth_; ++i) {
        mvprintw(0, i, "#");
        mvprintw(2, i, "#");
    }
    attron(COLOR_PAIR(2));
    mvprintw(1, gameScreenWidth_/2 - 5, "Space Invaders");
    attroff(COLOR_PAIR(2));
    printStars(1);
    mvprintw(5, 1, "Survival : \'s\'");
    mvprintw(7, 1, "Train : \'t\'");
    mvprintw(9, 1, "Load saved game : \'l\'");
    mvprintw(11, 1, "Quit : \'q\'");
}

void GameScreen::winScreen() {
    std::string str1 = "Invaders are destroyed...";
    std::string str2 = "The Earth is saved...";
    clear();
    printStars(1);
    for (int i = 0; i < str1.length(); ++i) {
        mvprintw(gameScreenHeight_ / 2, gameScreenWidth_/2 - str2.length() / 2 + i, "%c", str1.at(i));
        delay_output(100);
        refresh();
    }
    for (int i = 0; i < str2.length(); ++i) {
        mvprintw(gameScreenHeight_ / 2 + 1, gameScreenWidth_/2 - str2.length() / 2 + i, "%c", str2.at(i));
        delay_output(100);
        refresh();
    }
    delay_output(1000);
    clear();
}

void GameScreen::loseScreen() {
    std::string str1 = "You were defeated...";
    std::string str2 = "The Earth will be destroyed...";
    clear();
    printStars(1);
    for (int i = 0; i < str1.length(); ++i) {
        mvprintw(gameScreenHeight_ / 2, gameScreenWidth_/2 - str2.length() / 2 + i, "%c", str1.at(i));
        delay_output(100);
        refresh();
    }
    for (int i = 0; i < str2.length(); ++i) {
        mvprintw(gameScreenHeight_ / 2 + 1, gameScreenWidth_/2 - str2.length() / 2 + i, "%c", str2.at(i));
        delay_output(100);
        refresh();
    }
    printStars(3);
    refresh();
    delay_output(1000);
    clear();
}

void GameScreen::scoreScreen() {
    clear();
    refresh();
}

void GameScreen::printScoreTable(score_table::ScoreTable& tb) {
    mvprintw(0, 82, "-------Top 10-------");
    for (int i = 0; i < tb.size(); ++i) {
        auto pair = tb.getPairbyIndex(i);
        mvprintw(i+1, 82, "%d)", i+1);
        mvprintw(i+1, 85, "%s", pair.first.c_str());
        mvprintw(i+1, 97, "%d", pair.second);
    }
}

void GameScreen::setNameMenu(gameobj::Context& ctx) {
    clear();
    std::string str = "Your name : ";
    std::string username;
    int yoffset = 11;
    int xoffset = 26;
    mvprintw(yoffset, xoffset, "%s", str.c_str());
    refresh();
    curs_set(1);
    int s;
    int i = 0;
    while ('\n' != (s = getch()) || username.size() == 0) {
        mvprintw(yoffset, xoffset + str.size(), "%s", username.c_str());
        if ((isdigit(s) || isalpha(s)) && username.size() < 10) {
          username.push_back(s);
          ++i;
        }
        if (s == KEY_BACKSPACE) {
            if (!username.empty()) {
                mvprintw(yoffset, xoffset + str.size() + i - 1, "%s", " ");
                username.pop_back();
                --i;
            }
        }
        refresh();
    }
    curs_set(0);
    ctx.setName(username);
}

void GameScreen::printObjects(gameobj::Context& ctx) {
    for (auto& obj : ctx.data()) {
        mvprintw(obj->getPos().second, obj->getPos().first, "%s", obj->getImg().c_str());
    }
}

}