//字符串对比
#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    char a[256] = {0}, b[256] = {0};
    gets(a);
    gets(b);
    int lena = strlen(a), lenb = strlen(b), flag = 0;
    if (lena != lenb)
    {
        printf("1");
        return 0;
    }
    else
    {
        flag = 2;
        for (int i = 0; i < lena; i++)
        {
            if (a[i] != b[i])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 2)
        {
            printf("2");
            return 0;
        }

        flag = 3;
        for (int i = 0; i < lena; i++)
        {
            if (abs(a[i] - b[i]) != 32 && (a[i] - b[i]) != 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 3)
        {
            printf("3");
            return 0;
        }

        printf("4");
        return 0;
    }
}