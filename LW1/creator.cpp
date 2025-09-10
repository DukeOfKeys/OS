#include "common.h"
#include "creator_func.h"
using namespace std;
/// @brief creator helper programm
/// @param argc expects to be 3
/// @param argv [name, filename, ammount of entries]
/// @return
int main(int argc, char *argv[])
{
    if (argc != 3)
        return EXIT_FAILURE;
    int amount = 0;
    try
    {
        amount = stoi(argv[2]);
    }
    catch (...)
    {
        return EXIT_FAILURE;
    }

    if (amount <= 0)
        return EXIT_FAILURE;

    if (!write_employees_to_file(argv[1], amount))
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
