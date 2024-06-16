#include "score_table.h"

namespace score_table {

void ScoreTable::writeScoreTable() {;
    std::fstream file(filename_, std::ios::out | std::ios::trunc);
    for (auto& pair : scoreTable_) {
        file << pair.first << " " << pair.second << std::endl;
    }
}

void ScoreTable::addScore(std::string name, int score) {
    scoreTable_.push_back(std::make_pair(name, score));
    std::sort(scoreTable_.begin(), scoreTable_.end(), 
                [](std::pair<std::string, int>& p1, std::pair<std::string, int>& p2) { return p1.second > p2.second; });
    if (scoreTable_.size() >= 10) {
        scoreTable_.resize(10);
    }
}

void ScoreTable::parseScoreTable() {
    std::fstream file(filename_, std::ios::in);
    std::string name;
    int points;
    std::string strPoints;
    std::string line;

    while (getline(file, line)) {
        std::stringstream stream(line);
        stream >> name;
        stream >> strPoints;
        points = atoi(strPoints.c_str());
        scoreTable_.push_back(std::make_pair(name, points));
    }
}

std::pair<std::string, int> ScoreTable::getPairbyIndex(int idx) {
    if (idx < 0 || idx >= scoreTable_.size()) {
        throw std::out_of_range("Out of range in scoreTable container");
    }
    return scoreTable_.at(idx);
}

int ScoreTable::size() const {
    return scoreTable_.size();
}

}