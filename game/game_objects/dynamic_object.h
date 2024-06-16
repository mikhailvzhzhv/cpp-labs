#pragma once
#include "../context/context.h"
#include <curses.h>
#include <memory>
#include <vector>
#include <chrono>
#include <string>

using namespace std::chrono_literals;
using steady_clock_t = std::chrono::time_point<std::chrono::steady_clock>;

namespace gameobj
{

class Context;

class DynamicObject {
protected:
    struct block {
        int x_;
        int y_;
        char img_;
    };
    std::vector<block> bs_;
    std::string name_;
    const int damage_;
    int hp_;
    std::string img_;
    int points_ = 0;
    steady_clock_t lastMove_;
    steady_clock_t now();
    bool isCollision(DynamicObject* obj);
    bool isAbroad();
    int attack() const;
    void getDamage(int damage);
    int getPoints() const;

public:
    DynamicObject(std::string name, int x, int y, const std::string& imgs, 
                  int damage, int hp) : name_(name), damage_(damage), hp_(hp), img_(imgs) {
        for (int i = 0; i < imgs.size(); ++i) {
            bs_.push_back(block{x+i, y, imgs.at(i)});
        }
        lastMove_ = now();
    };
    virtual ~DynamicObject() = default;

    void setLastTimeAsNow() {
        lastMove_ = now();
    }
    virtual void move(Context& ctx) = 0;
    virtual bool isInvader() = 0;
    virtual bool isBullet() = 0;
    bool isDead() const;
    void removeCollisions(Context& ctx, int& idx);
    std::string getName() const;
    std::pair<int, int> getPos() const; 
    int getHP() const;
    std::string getImg() const;
};

}