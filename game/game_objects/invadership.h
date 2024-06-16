#pragma once
#include "dynamic_object.h"
#include "bullet.h"
#include <memory>

namespace gameobj
{

class InvaderShip : public DynamicObject {
protected:
    block head_;
    steady_clock_t lastShot_;
    
public:
    InvaderShip(std::string name, int x, int y, const std::string& imgs,
                int damage, int hp) : DynamicObject(name, x, y, imgs, damage, hp) {
        head_.x_ = bs_.at(bs_.size() / 2).x_;
        head_.y_ = bs_.at(bs_.size() / 2).y_;
        head_.img_ = bs_.at(bs_.size() / 2).img_;
        lastShot_ = now();
        points_ = 10;
    };
    ~InvaderShip() = default;

    void move(Context& ctx) override;
    bool isInvader();
    bool isBullet();
};

class StrongInvader : public InvaderShip {
public:
    StrongInvader(std::string name, int x, int y, const std::string& imgs,
                  int damage, int hp) : InvaderShip(name, x, y, imgs, damage, hp) {
        points_ = 20;
    };
    ~StrongInvader() = default;

    void move(Context& ctx) override;
};

}