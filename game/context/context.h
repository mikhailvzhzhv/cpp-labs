#pragma once
#include "../game_objects/dynamic_object.h"

#include <experimental/random>
#include <vector>
#include <memory>
#include <string>
#include <chrono>

using namespace std::chrono_literals;
using steady_clock_t = std::chrono::time_point<std::chrono::steady_clock>;

namespace gameobj
{

class DynamicObject;

class Context {
private:
    std::vector<std::unique_ptr<DynamicObject>> objects_;
    int bulletCount_;
    bool invExist_;
    int key_;
    int hp_;
    int points_;
    steady_clock_t time_;
    std::string username_;

public:
    Context() : bulletCount_(0), invExist_(true), key_(0), hp_(0), points_(0) {};
    ~Context() = default;

    int getBulletCount() const;
    std::vector<std::unique_ptr<DynamicObject>>& data();
    void addBullet();
    bool invIsExist() const;
    void setInvExistence(bool e);
    int getUserInput() const;
    void setUserInput(int key);
    int getHP() const;
    void setHP(int key);
    int getSeconds();
    void restart();
    void addPoints(int p);
    int getPoints() const;
    void setPoints(int points);
    void setSeconds(int seconds);
    void setBullets(int bullets);
    void action();
    std::string getName() const;
    void setName(std::string& name);
};

}