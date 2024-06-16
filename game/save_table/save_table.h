#pragma once
#include "../context/context.h"
#include "../game_objects/dynamic_object.h"
#include "../factory/factory.h"
#include <string>
#include <fstream>
#include <sstream>


namespace save_table
{

class SaveTable {
private:
    std::string filename_;

public:
    SaveTable(std::string filename) : filename_(filename) {};
    ~SaveTable() = default;
    
    void saveGame(gameobj::Context& ctx);
    void loadGame(gameobj::Context& ctx, ObjectFactory& f);
    bool isSaved();
    void removeSave();
};

}