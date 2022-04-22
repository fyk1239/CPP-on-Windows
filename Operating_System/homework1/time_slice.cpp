#include <stdio.h>
#include <windows.h>
#pragma comment(lib,"winmm.lib")

const unsigned long TIMES = 10;

unsigned long data[TIMES];
//unsigned long data2[TIMES];
int cnt = 0;

DWORD WINAPI threadFun(LPVOID lpParameter)
{
    int *p = (int *)lpParameter;
    unsigned long oldTick, newTick;
    oldTick = GetTickCount();
    while(true)
    {
        newTick = GetTickCount();
        if (newTick - oldTick > 2) 
        {
            //printf("%d: %lu\n", *p, newTick);
            data[cnt] = newTick - oldTick;
            cnt++;
            if (cnt >= TIMES)
                break;
        }
        oldTick = newTick;
    }
    return 0;
}

int main()
{
    int cpuIndex = 0;

    HANDLE thread1, thread2;
    int t1 = 1;
    int t2 = 2;

    thread1 = CreateThread(NULL, 0, threadFun, &t1, 0, NULL);
    thread2 = CreateThread(NULL, 0, threadFun, &t2, 0, NULL);
    SetThreadAffinityMask(thread1, 1 << cpuIndex);
    SetThreadAffinityMask(thread2, 1 << cpuIndex);

    WaitForSingleObject(thread1, INFINITE);
    WaitForSingleObject(thread2, INFINITE);

    for (int i = 0; i < cnt; i++) {
        printf("%d\n", data[i]);
    }

    return 0;
}

