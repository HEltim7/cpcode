//统计元音
#include <stdio.h>
#include <string.h>
int main()
{
    char str[1024];
    gets(str);
    int size = strlen(str), a = 0, e = 0, i = 0, o = 0, u = 0;
    for (int j = 0; j < size; j++)
    {
        switch (str[j])
        {
        case 'a':
            a++;
            break;
        case 'e':
            e++;
            break;
        case 'i':
            i++;
            break;
        case 'o':
            o++;
            break;
        case 'u':
            u++;
            break;
        default:
            break;
        }
    }
    printf("a:%d\n", a);
    printf("e:%d\n", e);
    printf("i:%d\n", i);
    printf("o:%d\n", o);
    printf("u:%d\n", u);
    return 0;
}