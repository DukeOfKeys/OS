#include "common.h"
using namespace std;
int main()
{
    string binary_file_name = "";
    unsigned int entries_ammount = 0;
    cout << "Waiting for binary_file_name:string and entries_ammount:unsigned int" << endl;
    cin >> binary_file_name >> entries_ammount;

    // creator launch block
    /// start
#if defined(USED_STANDART_WIN_API)
    {
        string launch_name_options = string("creator.exe ") + binary_file_name + " " + to_string(entries_ammount);
        vector<char> cmd(launch_name_options.begin(), launch_name_options.end());
        cmd.push_back('\n');
        STARTUPINFOA si;
        PROCESS_INFORMATION piApp;

        ZeroMemory(&si, sizeof(STARTUPINFOA));
        si.cb = sizeof(STARTUPINFOA);

        if (!CreateProcessA(NULL, cmd.data(), NULL, NULL, FALSE, /*not creating a console to keep things compact*/ 0, NULL, NULL, &si, &piApp))
        {
            cerr << "Couldn't create prosses" << endl;
            return EXIT_FAILURE;
        }

        WaitForSingleObject(piApp.hProcess, INFINITE);
        CloseHandle(piApp.hThread);
        CloseHandle(piApp.hProcess);
    }
#elif defined(USED_CMD_LAUNCH)
    {
        string launch_name_options = string("creator.exe ") + binary_file_name + " " + to_string(entries_ammount);
        int ret = system(launch_name_options.c_str());
        if (ret == 0)
            cout << "good" << endl;
    }
#elif defined(USED_STANDART_CROSSPLATFORM_CPP)
#endif

    // creator launch block
    /// end

    cout << "Waiting for to_be_created_report_name.txt:string and hour_salary:unsigned int" << endl;

    string to_be_created_report_name = "";
    unsigned int hour_salary = 0;

    cin >> to_be_created_report_name >> hour_salary;
    // reporter launch block
    /// start
#if defined(USED_STANDART_WIN_API)
    {
        string launch_name_options = string("reporter.exe ") + binary_file_name + " " + to_be_created_report_name + " " + to_string(hour_salary);
        vector<char> cmd(launch_name_options.begin(), launch_name_options.end());
        cmd.push_back('\n');
        STARTUPINFOA si;
        PROCESS_INFORMATION piApp;

        ZeroMemory(&si, sizeof(STARTUPINFOA));
        si.cb = sizeof(STARTUPINFOA);

        if (!CreateProcessA(NULL, cmd.data(), NULL, NULL, FALSE, /*not creating a console to keep things compact*/ 0, NULL, NULL, &si, &piApp))
        {
            cerr << "Couldn't create prosses" << endl;
            return EXIT_FAILURE;
        }

        WaitForSingleObject(piApp.hProcess, INFINITE);
        CloseHandle(piApp.hThread);
        CloseHandle(piApp.hProcess);
    }
#elif defined(USED_CMD_LAUNCH)
    {
        string launch_name_options = string("reporter.exe ") + binary_file_name + " " + to_be_created_report_name + " " + to_string(hour_salary);
        int ret = system(launch_name_options.c_str());
        if (ret == 0)
            cout << "good" << endl;
    }
#elif defined(USED_STANDART_CROSSPLATFORM_CPP)

#endif
    // reporter launch block
    /// end

    ifstream report_print(to_be_created_report_name);
    if (!report_print.is_open())
        return EXIT_FAILURE;

    string line_read = "";
    while (!report_print.eof())
    {
        getline(report_print, line_read);
        cout << line_read << endl;
    }
    return EXIT_SUCCESS;
}