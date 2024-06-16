#include "flatmap.h"
#include "gtest/gtest.h"

namespace {

TEST(Test, AccessAndInsertion) {

    using flatmap::FlatMap;

    FlatMap<int, std::string> student;

    student[2] = "2";
    EXPECT_EQ(student[2], "2");
    
    student[1] = "1";
    EXPECT_EQ(student[1], "1");
}

TEST(Test, ContainsAndSize) {

    using flatmap::FlatMap;

    FlatMap<int, std::string> student;

    student[1] = "2";
    EXPECT_EQ(student.contains(1), true);
    
    student[3] = "1";
    student[8] = "1";
    student[9] = "1";
    student[2] = "1";
    student[6] = "1";
    student[5] = "1";
    student[0] = "1";

    EXPECT_EQ(student.contains(4), false);
    EXPECT_EQ(student.size(), 8);
}

TEST(Test, StandartCopyAndAssignment) {

    using flatmap::FlatMap;

    FlatMap<std::string, std::string> student;

    student["course"] = "2";
    student["lab"] = "1";
    student["proga"] = "1";

    FlatMap<std::string, std::string> student1(student);

    EXPECT_EQ(student1.contains("proga"), true);
    EXPECT_EQ(student1.size(), 3);


    FlatMap<std::string, std::string> student2;
    student2["name"] = "mikhail";
    student2 = student;

    EXPECT_EQ(student2.contains("proga"), true);
    EXPECT_EQ(student2.contains("name"), false);
    EXPECT_EQ(student2.size(), 3);    
}

TEST(Test, ClearAndErase) {

    using flatmap::FlatMap;

    FlatMap<std::string, std::string> student;

    student["course"] = "2";
    student["lab"] = "1";
    student["proga"] = "1";
    student["university"] = "NSU";
    student["lect"] = "rylov";

    student.erase("lect");

    EXPECT_EQ(student.contains("lect"), false);
    EXPECT_EQ(student.size(), 4);


    student.clear();

    EXPECT_EQ(student.contains("proga"), false);
    EXPECT_EQ(student.size(), 0);
}

TEST(Test, Iterator) {

    using flatmap::FlatMap;

    FlatMap<std::string, std::string> student;

    student["course"] = "2";
    student["lab"] = "1";
    student["proga"] = "1";
    student["university"] = "NSU";
    student["lect"] = "rylov";

   for (auto it = student.begin(); it != student.end(); ++it) {

        EXPECT_EQ(it->second, student[it->first]);
    }

    for (auto it = student.find("lab"); it != student.end(); ++it) {

        EXPECT_EQ(it->second, student[it->first]);
    }

    EXPECT_EQ(student.find("aboba"), student.end());
}

TEST(Test, MoveConstructor) {

    using flatmap::FlatMap;

    FlatMap<std::string, std::string> student;

    student["course"] = "2";
    student["lab"] = "1";
    student["proga"] = "1";
    student["university"] = "NSU";
    student["lect"] = "rylov";

    FlatMap<std::string, std::string> student1(std::move(student));

    EXPECT_EQ(student1["course"], "2");
    EXPECT_EQ(student1.size(), 5);

    student1["smth"] = "smb";
    EXPECT_EQ(student1.size(), 6);
}

TEST(Test, MoveAndAssignmentOperator) {

    using flatmap::FlatMap;

    FlatMap<std::string, std::string> student;

    student["course"] = "2";
    student["lab"] = "1";
    student["proga"] = "1";
    student["university"] = "NSU";
    student["lect"] = "rylov";

    FlatMap<std::string, std::string> student1;

    student1 = (std::move(student));

    EXPECT_EQ(student1["course"], "2");
    EXPECT_EQ(student1.size(), 5);
}

}