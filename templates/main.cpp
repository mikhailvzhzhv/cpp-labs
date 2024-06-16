#include "tuple.h"
#include "csv_prs.h"
#include "flatmap.h"
#include <string>
#include <fstream>

using namespace constexpression;
using namespace flatmap;

struct A {

};

int main() {

    // print tuple
    std::fstream f("hih.txt", std::ios::out | std::ios::trunc);
    std::tuple<int, std::string, double, std::string> t = {5, "abcd", 1.2, "hihi"};
    f << t;
    std::cout << t << std::endl;

    // csv parser
    std::fstream f1("file1.csv", std::ios::in);
    CSVParser<int, std::string, double> p1(f1, 0);
    // CSVParser<int, std::string, double> p1(f1, 2);
    // CSVParser<int, std::string, double> p1(std::cin, 0);
    for (std::tuple<int, std::string, double> rs : p1) {
        std::cout << rs << "\n";
    }


    FlatMap<std::string, std::string> student;

    std::string key = "12";
    std::string value = "lol";
    student[key] = value;
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