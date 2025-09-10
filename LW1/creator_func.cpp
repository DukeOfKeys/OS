#include "creator_func.h"
using namespace std;

bool write_employees_to_file(const string &_filename, int _amount)
{
    ofstream file_bin_out(_filename, ios::binary);
    if (!file_bin_out.is_open())
        return false;

    for (int index = 0; index < _amount; index++)
    {
        cout << "Enter employee info in the predefined order:\nID NAME WORK_HOURS" << endl;

        employee e_info = {};
        cin >> e_info;

        file_bin_out.write(reinterpret_cast<char *>(&e_info), sizeof(employee));
        if (!file_bin_out)
            return false;
    }

    file_bin_out.close();
    return true;
}