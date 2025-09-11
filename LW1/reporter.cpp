#include "common.h"
#include "reporter_func.h"
using namespace std;

/// @brief reporter helper program
/// @param argc expects to be 4
/// @param argv [name, binary_filename, to_be_created_report_name.txt, hour_salary]
/// @return
int main(int argc, char *argv[])
{
    if (argc != 4)
        return EXIT_FAILURE;

    int hour_salary = atoi(argv[3]);

    if (!generate_report(argv[1], argv[2], hour_salary))
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
