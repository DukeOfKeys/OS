#include "creator_func.h"
#include <gtest/gtest.h>
#include <sstream>
#include <fstream>
#include <vector>

TEST(CreatorTests, WritesEmployeesCorrectly)
{
    std::string test_file = "test_employees.bin";

    std::istringstream fake_input("1 Alice 40\n2 Bob 35\n");
    std::cin.rdbuf(fake_input.rdbuf());

    ASSERT_TRUE(write_employees_to_file(test_file, 2));

    std::ifstream file(test_file, std::ios::binary);
    ASSERT_TRUE(file.is_open());

    std::vector<employee> emps(2);
    file.read(reinterpret_cast<char *>(emps.data()), sizeof(employee) * 2);

    EXPECT_EQ(emps[0].num, 1);
    EXPECT_STREQ(emps[0].name, "Alice");
    EXPECT_DOUBLE_EQ(emps[0].hours, 40);

    EXPECT_EQ(emps[1].num, 2);
    EXPECT_STREQ(emps[1].name, "Bob");
    EXPECT_DOUBLE_EQ(emps[1].hours, 35);
}

TEST(CreatorTests, ReturnsFalseIfFileCannotBeOpened)
{
    ASSERT_FALSE(write_employees_to_file("/invalid_path/test.bin", 1));
}