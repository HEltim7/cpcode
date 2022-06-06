//比较字符串
#include <stdio.h>
int main()
{
    char s1[64], s2[64], *p1 = &s1[0], *p2 = &s2[0];
    scanf("%s", &s1);
    scanf("%s", &s2);
    for (; *p1 != '\0' || *p2 != '\0';)
    {
        if (*p1 > *p2)
        {
            printf("<");
            return 0;
        }
        else if (*p1 < *p2)
        {
            printf(">");
            return 0;
        }
        p1++;
        p2++;
    }
    printf("=");
    return 0;
}