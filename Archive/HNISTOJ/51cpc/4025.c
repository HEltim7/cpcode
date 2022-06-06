//汉字统计
#include <stdio.h>
#include <string.h>
int main()
{
    char str[1024] = {0};
    gets(str);
    int size = strlen(str), num = 0;
    for (int i = 0; i < size; i++)
        if (str[i] > 0x4E00 && str[i] < 0x9FA5)
            num++;
    printf("%d", num);
    return 0;
}