//ASCII统计
#include <stdio.h>
#include <string.h>
int main()
{
    int alpha[128] = {0}, max[2] = {0}, i, j = 0;
    char *p, maxalpha = ' ', str[2][1000];
    gets(str[0]);
    gets(str[1]);
    for (j = 0; j < 2; j++)
    {
        for (p = &str[j][0]; p <= &str[j][strlen(str[j])]; p++)
        {
            //头铁查找
            for (i = 0; i < 128; i++)
            {
                if (*p == i)
                {
                    alpha[i]++;
                    break;
                }
            }
        }
        alpha[' '] = 0; //不统计space
        for (i = 126; i > 0; i--)
        {
            if (alpha[i] >= max[j])
            {
                max[j] = alpha[i];
                maxalpha = i;
            }
        }
        printf("%c ", maxalpha);
        printf("%d\n", max[j]);
        for (i = 0; i < 128; i++)
        {
            alpha[i] = 0;
        }
        max[j] = 0;
        maxalpha = ' ';
    }
    return 0;
}