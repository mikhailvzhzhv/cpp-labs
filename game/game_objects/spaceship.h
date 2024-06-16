#pragma once
#include "dynamic_object.h"
#include "bullet.h"
#include <memory>

namespace gameobj
{

class Spaceship : public DynamicObject {
private:
    block head_;
    
public:
    Spaceship(std::string name, int x, int y, const std::string& imgs,
              int damage, int hp) : DynamicObject(name, x, y, imgs, damage, hp) {
        head_.x_ = bs_.at(bs_.size() / 2).x_;
        head_.y_ = bs_.at(bs_.size() / 2).y_;
        head_.img_ = bs_.at(bs_.size() / 2).img_;
        name_ = "spaceship";
    };
    ~Spaceship() = default;

    void move(Context& ctx) override;
    void getDamage(int damage);
    int getHP() const;
    bool isInvader();
    bool isBullet();
};

}