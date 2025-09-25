#include "common.h"
#include <iostream>
using namespace std;
int main()
{
    int size_of_array = 0;
    cin >> size_of_array;
    int *array = new int[size_of_array];
    for (int index = 0; index < size_of_array; index++)
        cin >> array[index];
    arrayData info = {};
    info.array = array;
    info.size = size_of_array;
    arrayData info2 = {};
    info2.array = array;
    info2.size = size_of_array;
#if defined(USED_STANDART_WIN_API)
    HANDLE hThread = CreateThread(NULL, 0, min_max, &info, 0, NULL);
    HANDLE hThread2 = CreateThread(NULL, 0, avarage, &info2, 0, NULL);
    DWORD_PTR ret;
    WaitForSingleObject(hThread, INFINITE);
    GetExitCodeThread(hThread, (LPDWORD)&ret);
    CloseHandle(hThread);

    long long result = info.result;
    int min = *((int *)&result);
    int max = *((int *)&result + 1);
    WaitForSingleObject(hThread2, INFINITE);
    ret = 0;
    GetExitCodeThread(hThread2, (LPDWORD)&ret);
    CloseHandle(hThread2);
    array[min] = ret;
    array[max] = ret;
#elif defined(USED_CXX_THREADS)
    std::thread t1((void (*)(arrayData *))min_max, &info);
    std::thread t2((void (*)(arrayData *))avarage, &info2);
    t2.join();
    t1.join();

    long long result = info.result;
    int min = (int)(result & 0xFFFFFFFF);
    int max = (int)((result >> 32) & 0xFFFFFFFF);

    int avg = info2.result;
    array[min] = avg;
    array[max] = avg;

    cout << "Updated array: ";
    for (int i = 0; i < info.size; ++i)
        cout << array[i] << " ";
    cout << std::endl;
#endif

    for (int index = 0; index < size_of_array; index++)
        cout << array[index] << " ";
    cout << endl;
}