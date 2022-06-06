//格式化输入输出1
#include <stdio.h>
#include <string.h>
int main()
{
    int i;
    char y[4], m[2], d[2], str[10];
    gets(str);
    for (i = 0; i < 4; i++)
    {
        y[i] = str[i];
    }
    for (i = 5; i < 7; i++)
    {
        m[i - 5] = str[i];
    }
    for (i = 8; i < 10; i++)
    {
        d[i - 8] = str[i];
    }
    printf("%c%c%c%c", y[0], y[1], y[2], y[3]);
    printf("--");
    printf("%c%c", m[0], m[1]);
    printf("--");
    printf("%c%c", d[0], d[1]);
    return 0;
}