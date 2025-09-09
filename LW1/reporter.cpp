#include "common.h"
using namespace std;
/// @brief reporter helper programm
/// @param argc expects to be 4
/// @param argv [name, binary_filename, to_be_created_report_name.txt, hour_salary]
/// @return
int main(int argc, char *argv[])
{
    if (argc != 4)
        return EXIT_FAILURE;

    ifstream file_bin_in(argv[1], ios::binary);
    if (!file_bin_in.is_open())
        EXIT_FAILURE;

    ofstream file_report(argv[2]);
    if (!file_report.is_open())
        EXIT_FAILURE;

    int hour_salary = atoi(argv[3]);

    employee info_read = {};

    while (file_bin_in.read((char *)&info_read, sizeof(employee)))
        file_report << info_read << " " << info_read.hours * hour_salary << endl;

    file_bin_in.close();
    file_report.close();
    return EXIT_SUCCESS;
    return EXIT_SUCCESS;
}