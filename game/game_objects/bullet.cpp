#include "bullet.h"

namespace gameobj
{

void Bullet::move(Context& ctx) {
    for (auto& b : bs_) {
        b.y_ -= 1;
    }
}

void InvBullet::move(Context& ctx) {
    for (auto& b : bs_) {
        b.y_ += 1;
    }
    
    ctx.setInvExistence(true);
}

int Bullet::attack() {
    return damage_;
}

bool Bullet::isInvader() {
    return false;
}

bool InvBullet::isInvader() {
    return true;
}

bool Bullet::isBullet() {
    return true;
}

}
