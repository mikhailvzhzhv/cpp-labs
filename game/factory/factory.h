#pragma once
#include "../game_objects/spaceship.h"
#include "../game_objects/invadership.h"
#include "../game_objects/bullet.h"
#include <string>
#include <map>
#include <memory>
#include <iostream>

class ObjectFactory {
public:
    std::unique_ptr<gameobj::DynamicObject> createObject(std::string& name, int x, int y, int hp);
};
