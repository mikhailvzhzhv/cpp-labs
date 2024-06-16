#include "save_table.h"

namespace save_table
{

void SaveTable::saveGame(gameobj::Context& ctx) {
    std::string sp = " ";
    std::fstream file(filename_, std::ios::out | std::ios::trunc);
    file << ctx.getName() << sp 
         << ctx.getHP() << sp 
         << ctx.getPoints() << sp 
         << ctx.getSeconds() << sp 
         << ctx.getBulletCount() << std::endl;
    for (auto& obj : ctx.data()) {
        auto pos = obj->getPos();
        file << obj->getName() << sp << pos.first << sp << pos.second << sp << obj->getHP() << std::endl;
    }
}

void SaveTable::loadGame(gameobj::Context& ctx, ObjectFactory& f) {
    std::fstream file(filename_, std::ios::in);
    std::string line;
    std::string spname;
    std::string sphp;
    std::string p;
    std::string s;
    std::string b;

    getline(file, line);
    std::stringstream stream(line);
    stream >> spname;
    stream >> sphp;
    stream >> p;
    stream >> s;
    stream >> b;

    ctx.setName(spname);
    ctx.setHP(std::stoi(sphp));
    ctx.setPoints(std::stoi(p));
    ctx.setSeconds(std::stoi(s));
    ctx.setBullets(std::stoi(b));
    
    std::string objParamsLine;
    std::string name;
    std::string x;
    std::string y;
    std::string hp;
    while (getline(file, objParamsLine)) {
        std::stringstream stream(objParamsLine);
        stream >> name;
        stream >> x;
        stream >> y;
        stream >> hp;
        ctx.data().push_back(f.createObject(name, std::stoi(x), std::stoi(y), std::stoi(hp)));
    }                                                                                                                                                                   
}

void SaveTable::removeSave() {
    std::fstream file(filename_, std::ios::out | std::ios::trunc);
}

bool SaveTable::isSaved() {
    std::fstream file(filename_, std::ios::in);
    file.seekg(0, std::ios::end);  
    return file.tellg() != 0; 
}

}