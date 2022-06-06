#include <stdio.h>
char *p[10];
int sort(int j)
{
    char *tmp1 = p[j], *tmp2 = p[j + 1];
    for (; *p[j] != '\0' || *p[j + 1] != '\0';)
    {
        if (*p[j] > *p[j + 1])
        {
            p[j + 1] = tmp1;
            p[j] = tmp2;
            return 0;
        }
        else if (*p[j] < *p[j + 1])
        {
            p[j] = tmp1;
            p[j + 1] = tmp2;
            return 0;
        }
        p[j]++;
        p[j + 1]++;
    }
    p[j] = tmp1;
    p[j + 1] = tmp2;
    return 0;
}
int main()
{
    char str[10][32] = {0};
    for (int i = 0; i < 10; i++)
    {
        scanf("%s", &str[i]);
        p[i] = &str[i][0];
    }
    for (int i = 9; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            sort(j);
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; *(p[i] + j) != '\0'; j++)
        {
            printf("%c", *(p[i] + j));
        }
        printf(" ");
    }
    return 0;
}