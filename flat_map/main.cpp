#include "flatmap.h"
#include <iostream>
#include <string>


using namespace flatmap;


int main(void) {

    FlatMap<std::string, std::string> student;

    std::string key = "12";
    std::string value = "lol";
    student[key] = value;

    // std::string stop;

    // std::cout << "print \"yes\" to stop" << std::endl;

    // while (stop != "y") {

    //     std::cout << "print \"key\" : ";
    //     std::cin >> key;

    //     std::cout << "print \"value\" : ";
    //     std::cin >> value;


    //     std::cout << std::endl;

    //     student[key] = value;

    //     std::cout << "stop? : ";
    //     std::cin >> stop;
    // }
    student["1"] = "1";
    bool x = student.contains("22") == true;   
    student["3"] = "3";
    student["8"] = "8";
    student["9"] = "9";
    student["2"] = "2";
    student["6"] = "6";
    student["5"] = "5";
    student["0"] = "0";
    std::cout << x << std::endl;


    std::cout << "trying to print all keys and values..." << std::endl;

    for (auto it = student.begin(); it != student.end(); ++it) {
        std::cout << it->first << " : " << it->second << "\n";
    }


    FlatMap<std::string, std::string> student1 = student;
    FlatMap<std::string, std::string> student2(student);
    std::cout << "student1 and student2 was was created using student and its size - " << student2.size() << std::endl;

    std::cout << "student1 obj size : " << student1.size() << std::endl;

    student2.clear();
    std::cout << "student2 obj was cleared and its size : " << student2.size() << std::endl;

    student2["4"] = "5";
    
    student1 = student2;
    std::cout << "student1 copied student2" << std::endl;

    student.erase(key);
    std::cout << "key " << "\"" << key << "\"" << " was erased" << std::endl;

    if (student.contains(key)) {
        std::cout << key << " : " << student[key] << std::endl;
    }
    else {
        std::cout << "not found key " << "\"" << key << "\""  << " size : " << student.size() << std::endl;
    }

    std::cout << "students was deleted..." << std::endl;
    
    return 0;
}