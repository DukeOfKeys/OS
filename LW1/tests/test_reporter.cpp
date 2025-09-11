#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include <vector>
#include "common.h"
#include "reporter_func.h"

using namespace std;

void write_test_binary(const char *filename, const vector<employee> &employees)
{
    ofstream out(filename, ios::binary);
    ASSERT_TRUE(out.is_open());
    for (const auto &e : employees)
    {
        out.write(reinterpret_cast<const char *>(&e), sizeof(employee));
    }
}

string read_file(const char *filename)
{
    ifstream in(filename);
    return string((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
}

TEST(GenerateReportTest, SuccessCase)
{
    const char *bin_file = "test_employees.bin";
    const char *report_file = "test_report.txt";

    vector<employee> employees = {
        {1, "Ivanov", 10.0},
        {2, "Petrov", 20.0}};
    write_test_binary(bin_file, employees);

    int salary = 100;
    ASSERT_TRUE(generate_report(bin_file, report_file, salary));

    ifstream f(report_file);
    ASSERT_TRUE(f.is_open());

    string content = read_file(report_file);
    EXPECT_NE(content.find("1 Ivanov 10"), string::npos);
    EXPECT_NE(content.find("1000"), string::npos); // 10 * 100
    EXPECT_NE(content.find("2 Petrov 20"), string::npos);
    EXPECT_NE(content.find("2000"), string::npos); // 20 * 100
}

TEST(GenerateReportTest, MissingBinaryFile)
{
    const char *bin_file = "non_existing.bin";
    const char *report_file = "should_not_exist.txt";

    int salary = 100;
    EXPECT_FALSE(generate_report(bin_file, report_file, salary));
}

TEST(GenerateReportTest, InvalidReportPath)
{
    const char *bin_file = "test_employees2.bin";
    const char *bad_report_file = "/invalid_path/report.txt";

    vector<employee> employees = {
        {3, "Sidorov", 5.0}};
    write_test_binary(bin_file, employees);

    int salary = 50;
    EXPECT_FALSE(generate_report(bin_file, bad_report_file, salary));
}
