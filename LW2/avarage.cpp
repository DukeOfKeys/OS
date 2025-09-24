#include "common.h"
#if defined(USED_STANDART_WIN_API)
DWORD WINAPI avarage(LPVOID lpParam)
{
        int *array = ((arrayData *)lpParam)->array;
        int size = ((arrayData *)lpParam)->size;
        int answer = 0;
        for (int index = 0; index < size; index++)
        {
                Sleep(12);

                answer += array[index];
        }
        cout << "Avarage: " << answer / size << endl;
        return answer / size;
}
#else
void avarage(arrayData *data)
{
        int *array = ((arrayData *)data)->array;
        int size = ((arrayData *)data)->size;
        int answer = 0;
        for (int index = 0; index < size; index++)
        {
                this_thread::sleep_for(chrono::milliseconds(12));
                answer += array[index];
        }
        cout << "Avarage: " << answer / size << endl;
        data->result = answer / size;
        return;
}
#endif
void avarage(arrayData *data)
{
        int *array = ((arrayData *)data)->array;
        int size = ((arrayData *)data)->size;
        int answer = 0;
        for (int index = 0; index < size; index++)
        {
                this_thread::sleep_for(chrono::milliseconds(12));
                answer += array[index];
        }
        cout << "Avarage: " << answer / size << endl;
        data->result = answer / size;
        return;
}