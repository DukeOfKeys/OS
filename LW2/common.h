#pragma once
#define WIN32_LEAN_AND_MEAN
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;
// TO PREVENT BOILARPLATE CODE, USAGE OF A PARTICULAR STANDART WILL BE IMPLEMENTED AS FOLLOWS
// #define USED_STANDART_WIN_API
#define USED_CXX_THREADS

#if defined(USED_STANDART_WIN_API)
#include <windows.h>
DWORD WINAPI min_max(LPVOID lpParam);
DWORD WINAPI avarage(LPVOID lpParam);

#elif defined(USED_CXX_THREADS)

#endif
struct arrayData
{
    int *array;
    int size;
    long long result;
};
long long min_max(int *array, int size);
void min_max(arrayData *data);
void avarage(arrayData *data);
