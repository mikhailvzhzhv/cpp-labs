#pragma once
#include <curses.h>
#include <fstream>
#include <vector>
#include <bits/stdc++.h> 

namespace score_table
{

class ScoreTable {
private:
    std::string filename_;
    std::vector<std::pair<std::string, int>> scoreTable_;

public:
    ScoreTable(std::string filename) : filename_(filename) {
        scoreTable_.resize(0);
    };
    ~ScoreTable() = default;
    void writeScoreTable();
    void addScore(std::string name, int score);
    void parseScoreTable();
    std::pair<std::string, int> getPairbyIndex(int idx);
    int size() const;
};

}