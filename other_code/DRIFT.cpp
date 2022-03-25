#include <stdio.h>
using namespace std;

int main()
{
    char ch;
    int n, i, j;
    printf("请输入字符：");
    scanf("%c", &ch);
    printf("n=");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = n - i; j >= 0; j--)
        {
            printf(" ");
        }
        for (j = 1; j <= i; j++)
        {
            printf("%c", ch);
        }
        printf("\n");
    }
    return 0;
}