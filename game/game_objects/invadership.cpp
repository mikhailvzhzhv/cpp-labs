#include "invadership.h"
#include <experimental/random>
#include <algorithm>

namespace gameobj
{

void InvaderShip::move(Context& ctx) {
    if ((now() - lastMove_) / 1ms > 1200 + std::experimental::randint(-100, 100)) {
        lastMove_ = now();
        int mv;
        if (bs_.at(0).x_ <= 1) {
            mv = std::experimental::randint(0, 1);
        }
        else if (bs_.at(bs_.size() - 1).x_ >= 78) {
            mv = std::experimental::randint(-1, 0);
        }
        else {
            mv = std::experimental::randint(-1, 1);
        }
        std::swap(img_.at(0), img_.at(bs_.size() - 1));
        for (auto& b : bs_) {
            b.x_ += mv;
            b.y_ += 1;
        }
        head_ = bs_.at(bs_.size()/2);

        if ((now() - lastShot_) / 1ms > 1800 + std::experimental::randint(-200, 100)) {
            ctx.data().push_back(std::make_unique<InvBullet>(InvBullet("invBullet", head_.x_, head_.y_, "\'", damage_, 1)));
            lastShot_ = now();
        }
    }
    
    ctx.setInvExistence(true);
}

void StrongInvader::move(Context& ctx) {
    if ((now() - lastMove_) / 1ms > 700 + std::experimental::randint(-200, 100)) {
        lastMove_ = now();
        int mv;
        if (bs_.at(0).x_ == 1) {
            mv = std::experimental::randint(0, 1);
        }
        else if (bs_.at(bs_.size() - 1).x_ == 78) {
            mv = std::experimental::randint(-1, 0);
        }
        else {
            mv = std::experimental::randint(-1, 1);
        }
        std::swap(img_.at(0), img_.at(bs_.size() - 1));
        for (auto& b : bs_) {
            b.x_ += mv;
            b.y_ += 1;
        }
        head_ = bs_.at(bs_.size()/2);
    }
    if ((now() - lastShot_) / 1ms > 1400 + std::experimental::randint(-200, 100)) {
        ctx.data().push_back(std::make_unique<InvBullet>(InvBullet("sInvBullet", head_.x_, head_.y_, "\"", damage_, 1)));
        lastShot_ = now();
    }
    ctx.setInvExistence(true);
}

bool InvaderShip::isInvader() {
    return true;
}

bool InvaderShip::isBullet() {
    return false;
}

}