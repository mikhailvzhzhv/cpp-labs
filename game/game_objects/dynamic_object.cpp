#include "dynamic_object.h"

namespace gameobj
{

steady_clock_t DynamicObject::now() {
    return std::chrono::steady_clock::now();
}

std::string DynamicObject::getName() const {
    return name_;
}

std::pair<int, int> DynamicObject::getPos() const {
    return std::make_pair(bs_.at(0).x_, bs_.at(0).y_);
}

int DynamicObject::getHP() const {
    return hp_;
}

bool DynamicObject::isAbroad() {
    for (auto& b : bs_) {
        if (b.y_ == 0 || b.y_ == 23) {
            return true;
        }
    }
    return false;
}

std::string DynamicObject::getImg() const {
    return img_;
}

int DynamicObject::getPoints() const {
    return points_;
}

bool DynamicObject::isDead() const {
    return hp_ <= 0;
}
int DynamicObject::attack() const {
    return damage_;
}

void DynamicObject::getDamage(int damage) {
    hp_ -= damage;
}

bool DynamicObject::isCollision(DynamicObject* obj) {
    if (this == obj) {return false;}
    if (this->isInvader() && obj->isInvader()) {return false;}
    for (auto& b : obj->bs_) {
        for (auto& bT : this->bs_) {
            if (b.x_ == bT.x_ &&
                b.y_ == bT.y_ &&
                b.img_ != bT.img_) {
                    return true;
            }
        }
    }
    return false;
}

void DynamicObject::removeCollisions(Context& ctx, int& idx) {

    if (ctx.data().at(idx)->isAbroad()) {
        if (!ctx.data().at(idx)->isBullet()) {
            ctx.data().at(0)->getDamage(this->attack());
        }
        ctx.data().erase(ctx.data().begin() + idx);
        return;
    }
    for (auto objIt = ctx.data().begin() + idx; objIt != ctx.data().end();) {
        if (isCollision((*objIt).get())) {
            (*objIt)->getDamage(this->attack());
            (this)->getDamage((*objIt)->attack());
            break;
        }
        else {
            ++objIt;
        }
    }

    if (ctx.data().at(idx)->isDead() && ctx.data().at(0) != ctx.data().at(idx)) {
        if (ctx.data().at(idx)->isInvader() && !ctx.data().at(idx)->isBullet()) {
            ctx.addPoints(ctx.data().at(idx)->getPoints());
        }
        ctx.data().erase(ctx.data().begin() + idx);
    }
    else {
        ++idx;
    }
}

}