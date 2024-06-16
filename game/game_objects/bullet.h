#pragma once
#include "dynamic_object.h"
#include <memory>

namespace gameobj
{

class Bullet : public DynamicObject {
public:
    Bullet(std::string name, int x, int y, const std::string& imgs,
           int damage, int hp) : DynamicObject(name, x, y, imgs, damage, hp) {};
    ~Bullet() = default;

    void move(Context& ctx) override;
    int attack();
    bool isInvader();
    bool isBullet();
};

class InvBullet : public Bullet {
public:
    InvBullet(std::string name, int x, int y, const std::string& imgs,
              int damage, int hp) : Bullet(name, x, y, imgs, damage, hp) {};
    ~InvBullet() = default;

    void move(Context& ctx) override;
    bool isInvader();
};

}