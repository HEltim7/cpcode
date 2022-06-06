//ASCII码排序
#include <stdio.h>
#include <string.h>
int main()
{
    int alpha[128] = {0}, i;
    char *p, str[1000];
    gets(str);
    int size = strlen(str);

    for (p = &str[0]; p < &str[size]; p++)
    {
        for (i = 0; i < 128; i++)
        {
            if (*p == i)
            {
                alpha[i]++;
                break;
            }
        }
    }

    for (int i = 0; i < 128; i++)
    {
        if (alpha[i] > 0)
        {
            for (; alpha[i] > 0; alpha[i]--)
            {
                printf("%c ", i);
            }
        }
    }

    return 0;
}