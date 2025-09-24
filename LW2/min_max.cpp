#include "common.h"
#if defined(USED_STANDART_WIN_API)
DWORD WINAPI min_max(LPVOID lpParam)
{

    int *array = ((arrayData *)lpParam)->array;
    int size = ((arrayData *)lpParam)->size;
    long long *answer = &((arrayData *)lpParam)->result;
    if (size < 1)
    {
        return -1;
    }
    int min = size - 1;
    int max = size - 1;
    for (int index = 1; index < size; index += 2)
    {

        if (array[index - 1] > array[index])
        {
            if (array[index - 1] > array[max])
                max = index - 1;
            if (array[index] < array[min])
                min = index;
        }
        else
        {
            if (array[index] > array[max])
                max = index;
            if (array[index - 1] < array[min])
                min = index - 1;
        }

        Sleep(21);
    }
    *((int *)answer) = min;
    *(((int *)answer) + 1) = max;
    cout << "Min: " << array[min] << " Max: " << array[max] << endl;
    return 0;
}

#endif
void min_max(arrayData *data)
{
    int *array = data->array;
    int size = data->size;
    long long *answer = &data->result;
    if (size < 1)
    {
        return;
    }
    int min = size - 1;
    int max = size - 1;
    for (int index = 1; index < size; index += 2)
    {

        if (array[index - 1] > array[index])
        {
            if (array[index - 1] > array[max])
                max = index - 1;
            if (array[index] < array[min])
                min = index;
        }
        else
        {
            if (array[index] > array[max])
                max = index;
            if (array[index - 1] < array[min])
                min = index - 1;
        }

        this_thread::sleep_for(chrono::milliseconds(21));
    }
    *((int *)answer) = min;
    *(((int *)answer) + 1) = max;
    cout << "Min: " << array[min] << " Max: " << array[max] << endl;
    return;
}
long long min_max(int *array, int size)
{
    long long answer = 0;
    if (size < 1)
    {
        return -1;
    }
    int min = array[size - 1];
    int max = array[size - 1];
    for (int index = 1; index < size; index += 2)
    {

        if (array[index - 1] > array[index])
        {
            if (array[index - 1] > max)
                max = array[index - 1];
            if (array[index] < min)
                min = array[index];
        }
        else
        {
            if (array[index] > max)
                max = array[index];
            if (array[index - 1] < min)
                min = array[index - 1];
        }

        this_thread::sleep_for(chrono::milliseconds(21));
    }
    *((int *)&answer) = min;
    *(((int *)&answer) + 1) = max;
    cout << "Min: " << min << " Max: " << max << endl;
    return answer;
}
