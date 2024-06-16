#include "factory.h"


std::unique_ptr<gameobj::DynamicObject> ObjectFactory::createObject(std::string& name, int x, int y, int hp) {
    if (name == "spaceship") {
        return std::make_unique<gameobj::Spaceship>(gameobj::Spaceship(name, x, y, "|-U-|", 2, hp));
    }
    else if (name == "wInvader") {
        return std::make_unique<gameobj::InvaderShip>(gameobj::InvaderShip(name, x, y, "/^@^\\", 1, 2));
    }
    else if (name == "WInvader") {
        return std::make_unique<gameobj::StrongInvader>(gameobj::StrongInvader(name, x, y, "/-T-\\", 2, 2));
    }
    else if (name == "bullet") {
        return std::make_unique<gameobj::Bullet>(gameobj::Bullet(name, x, y, "*", 2, 1));
    }
    else if (name == "invBullet") {
        return std::make_unique<gameobj::InvBullet>(gameobj::InvBullet(name, x, y, "'", 1, 1));
    }
    else if (name == "sInvBullet") {
        return std::make_unique<gameobj::InvBullet>(gameobj::InvBullet(name, x, y, "\"", 2, 1));
    }
    else {
        endwin();
        throw std::runtime_error("unknown object " + name);
    }
}
