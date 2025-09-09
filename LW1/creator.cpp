#include "common.h"
using namespace std;
/// @brief creator helper programm
/// @param argc expects to be 3
/// @param argv [name, filename, ammount of entries]
/// @return
int main(int argc, char *argv[])
{
    if (argc != 3)
        return EXIT_FAILURE;

    ofstream file_bin_out(argv[1], ios::binary);
    if (!file_bin_out.is_open())
        EXIT_FAILURE;

    int ammount = atoi(argv[2]);

    for (int index = 0; index < ammount; index++)
    {
        cout << "Enter employee info in the predefined order:\nID NAME WORK_HOURS" << endl;

        employee e_info = {};

        cin >> e_info;
        file_bin_out.write((char *)&e_info, sizeof(employee));
    }

    file_bin_out.close();
    return EXIT_SUCCESS;
}