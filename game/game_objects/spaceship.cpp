#include "spaceship.h"

namespace gameobj
{

void Spaceship::move(Context& ctx) {

    ctx.setInvExistence(false);
    ctx.setHP(hp_);
    for (int i = 0; i < bs_.size(); ++i) {
        if ((bs_.at(i).x_ == 1 && ctx.getUserInput() == KEY_LEFT) || (bs_.at(i).x_ == 78 && ctx.getUserInput() == KEY_RIGHT)) {
            return;
        }
    }
    if (ctx.getUserInput() == KEY_LEFT) {
        for (int i = 0; i < bs_.size(); ++i) {
            --bs_.at(i).x_;
        }
    }
    else if (ctx.getUserInput() == KEY_RIGHT) {
        for (int i = 0; i < bs_.size(); ++i) {
            ++bs_.at(i).x_;
        }
    }
    else if (ctx.getUserInput() == ' ') {
        ctx.data().push_back(std::make_unique<Bullet>(Bullet("bullet", head_.x_, head_.y_, "*", damage_, 1)));
        ctx.addBullet();
    }
    head_ = bs_.at(bs_.size()/2);
}

int Spaceship::getHP() const {
    return hp_;
}

void Spaceship::getDamage(int damage) {
    hp_ -= damage;
}

bool Spaceship::isInvader() {
    return false;
}

bool Spaceship::isBullet() {
    return false;
}

}
