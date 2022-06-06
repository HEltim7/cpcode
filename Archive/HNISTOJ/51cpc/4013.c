//盐荒子孙
#include <stdio.h>
#include <string.h>
int main()
{
    char forsalt[3][1024] = {0};
    for (int i = 0; i < 3; i++)
    {
        gets(forsalt[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        int size = strlen(forsalt[i]);
        for (int j = 0; j < size; j++)
        {
            if (forsalt[i][j] == 's' || forsalt[i][j] == 'S')
            {
                if (forsalt[i][j + 1] == 'a' || forsalt[i][j + 1] == 'A')
                {
                    if (forsalt[i][j + 2] == 'l' || forsalt[i][j + 2] == 'L')
                    {
                        if (forsalt[i][j + 3] == 't' || forsalt[i][j + 3] == 'T')
                        {
                            puts(forsalt[i]);
                            break;
                        }
                    }
                }
            }
        }
    }
    return 0;
}