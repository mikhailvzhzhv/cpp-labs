#include "context.h"

namespace gameobj
{

int Context::getBulletCount() const {
    return bulletCount_;
}
void Context::addBullet() {
    ++bulletCount_;
}
bool Context::invIsExist() const {
    return invExist_;
}
void Context::setInvExistence(bool e) {
    invExist_ = e;
}

int Context::getUserInput() const {
    return key_;
}

void Context::setUserInput(int key) {
    key_ = key;
}

int Context::getHP() const {
    return hp_;
}

void Context::setHP(int hp) {
    hp_ = hp;
}

void Context::setPoints(int points) {
    points_ = points;
}

void Context::setSeconds(int seconds) {
    time_ = std::chrono::steady_clock::now() - seconds*1000ms;
}

void Context::setBullets(int bullets) {
    bulletCount_ = bullets;
}

int Context::getSeconds() {
    return (std::chrono::steady_clock::now() - time_) / 1000ms;
}

void Context::restart() {
    invExist_ = true;
    time_ = std::chrono::steady_clock::now();
    bulletCount_ = 0;
    points_ = 0;
}

std::vector<std::unique_ptr<DynamicObject>>& Context::data() {
    return objects_;
}

void Context::addPoints(int p) {
    points_ += p;
}

int Context::getPoints() const {
    return points_;
}

void Context::action() {
    for (int i = 0; i < objects_.size(); ++i) {
        objects_.at(i)->move(*this);
    }
    for (int i = 0; i < objects_.size();) {
        objects_.at(i)->removeCollisions(*this, i);
    }
}

std::string Context::getName() const {
    return username_;
}

void Context::setName(std::string& name) {
    username_ = name;
}

}