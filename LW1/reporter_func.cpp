#include "common.h"
#include "reporter_func.h"
using namespace std;
/// @brief Генерация отчёта
/// @param binary_filename входной бинарный файл
/// @param report_filename выходной текстовый файл отчёта
/// @param hour_salary почасовая ставка
/// @return true если успешно, иначе false
bool generate_report(const char *binary_filename, const char *report_filename, int hour_salary)
{
    ifstream file_bin_in(binary_filename, ios::binary);
    if (!file_bin_in.is_open())
        return false;

    ofstream file_report(report_filename);
    if (!file_report.is_open())
        return false;

    employee info_read = {};
    while (file_bin_in.read((char *)&info_read, sizeof(employee)))
    {
        file_report << info_read << " " << info_read.hours * hour_salary << endl;
    }

    file_bin_in.close();
    file_report.close();
    return true;
}