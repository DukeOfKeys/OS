#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

// TO PREVENT BOILARPLATE CODE, USAGE OF A PARTICULAR STANDART WILL BE IMPLEMENTED AS FOLLOWS
// #define USED_STANDART_WIN_API
// #define USED_CMD_LAUNCH
//  #define USED_STANDART_CROSSPLATFORM_CPP
#if defined(USED_STANDART_WIN_API)
#include <windows.h>

#elif defined(USED_CMD_LAUNCH)
#include <stdlib.h>
#elif defined(USED_STANDART_CROSSPLATFORM_CPP)
#endif

struct employee
{
    int num;       // идентификационный номер сотрудника
    char name[10]; // имя сотрудника
    double hours;  // количество отработанных часов
};

std::istream &operator>>(std::istream &in, employee &obj)
{
    in >> obj.num;
    std::string name = "";
    in >> name;
    strncpy(obj.name, name.c_str(), 10);
    in >> obj.hours;
    return in;
}
std::ostream &operator<<(std::ostream &out, const employee &obj)
{
    out << obj.num << " " << obj.name << " " << obj.hours;
    return out;
}