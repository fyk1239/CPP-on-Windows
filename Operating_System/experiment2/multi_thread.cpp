#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <windows.h>
int num[10005];
DWORD WINAPI Function1(LPVOID lpParameter);
int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);
    if (n < 0)
    {
        printf("n不能为负数！\n");
        exit(EXIT_FAILURE);
    }
    HANDLE hThread0 = CreateThread(NULL, 0, Function1, &n, 0, NULL);
    CloseHandle(hThread0);
    Sleep(2000);
    for (int i = 0; i < n; i++)
        printf("%d ", num[i]);
    printf("\n");
    return 0;
}
DWORD WINAPI Function1(LPVOID lpParameter)
{
    int *des = (int *)lpParameter;
    int len = *des;
    num[0] = 0, num[1] = 1;
    for (int i = 2; i < len; i++)
    {
        num[i] = num[i - 1] + num[i - 2];
    }
    return 0;
}