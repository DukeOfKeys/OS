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
        cmd.push_back('\0');
        STARTUPINFOA si;
        PROCESS_INFORMATION piApp;

        ZeroMemory(&si, sizeof(STARTUPINFOA));
        si.cb = sizeof(STARTUPINFOA);

        if (!CreateProcessA(NULL, cmd.data(), NULL, NULL, FALSE, 0, NULL, NULL, &si, &piApp))
        {
            cerr << "Couldn't create process" << endl;
            return EXIT_FAILURE;
        }

        WaitForSingleObject(piApp.hProcess, INFINITE);

        DWORD exitCode;
        if (!GetExitCodeProcess(piApp.hProcess, &exitCode))
        {
            cerr << "Failed to get process exit code" << endl;
            CloseHandle(piApp.hThread);
            CloseHandle(piApp.hProcess);
            return EXIT_FAILURE;
        }

        if (exitCode != 0)
        {
            cerr << "creator.exe exited with error code: " << exitCode << endl;
            CloseHandle(piApp.hThread);
            CloseHandle(piApp.hProcess);
            return EXIT_FAILURE;
        }

        CloseHandle(piApp.hThread);
        CloseHandle(piApp.hProcess);
    }
#elif defined(USED_CMD_LAUNCH)
    {
        string launch_name_options = string("creator.exe ") + binary_file_name + " " + to_string(entries_ammount);
        int ret = system(launch_name_options.c_str());
        if (ret != 0)
        {
            cerr << "creator.exe exited with error code: " << ret << endl;
            return EXIT_FAILURE;
        }
        cout << "creator.exe finished successfully" << endl;
    }
#elif defined(USED_STANDART_CROSSPLATFORM_CPP)
#endif
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
        cmd.push_back('\0');
        STARTUPINFOA si;
        PROCESS_INFORMATION piApp;

        ZeroMemory(&si, sizeof(STARTUPINFOA));
        si.cb = sizeof(STARTUPINFOA);

        if (!CreateProcessA(NULL, cmd.data(), NULL, NULL, FALSE, 0, NULL, NULL, &si, &piApp))
        {
            cerr << "Couldn't create process" << endl;
            return EXIT_FAILURE;
        }

        WaitForSingleObject(piApp.hProcess, INFINITE);

        DWORD exitCode;
        if (!GetExitCodeProcess(piApp.hProcess, &exitCode))
        {
            cerr << "Failed to get process exit code" << endl;
            CloseHandle(piApp.hThread);
            CloseHandle(piApp.hProcess);
            return EXIT_FAILURE;
        }

        if (exitCode != 0)
        {
            cerr << "reporter.exe exited with error code: " << exitCode << endl;
            CloseHandle(piApp.hThread);
            CloseHandle(piApp.hProcess);
            return EXIT_FAILURE;
        }

        CloseHandle(piApp.hThread);
        CloseHandle(piApp.hProcess);
    }
#elif defined(USED_CMD_LAUNCH)
    {
        string launch_name_options = string("reporter.exe ") + binary_file_name + " " + to_be_created_report_name + " " + to_string(hour_salary);
        int ret = system(launch_name_options.c_str());
        if (ret != 0)
        {
            cerr << "reporter.exe exited with error code: " << ret << endl;
            return EXIT_FAILURE;
        }
        cout << "reporter.exe finished successfully" << endl;
    }
#elif defined(USED_STANDART_CROSSPLATFORM_CPP)
#endif
    /// end

    ifstream report_print(to_be_created_report_name);
    if (!report_print.is_open())
        return EXIT_FAILURE;

    string line_read = "";
    while (getline(report_print, line_read))
    {
        cout << line_read << endl;
    }

    return EXIT_SUCCESS;
}
