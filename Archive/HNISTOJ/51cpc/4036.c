//图形输出
#include <stdio.h>
int main()
{
    int size;
    char type;
    scanf("%c%d", &type, &size);
    switch (type)
    {
    case 90:
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                printf("*");
            }
            printf("\n");
        }
        break;
    case 76:
        for (int i = 1; i <= size * 2; i += 2)
        {
            for (int j = size - 1 - (i - 1) / 2; j > 0; j--)
            {
                printf(" ");
            }
            for (int j = 0; j < i; j++)
            {
                printf("*");
            }
            for (int j = size - 1 - (i - 1) / 2; j > 0; j--)
            {
                printf(" ");
            }
            printf("\n");
        }
        for (int i = size * 2 - 3; i > 0; i -= 2)
        {
            for (int j = size - 1 - (i - 1) / 2; j > 0; j--)
            {
                printf(" ");
            }
            for (int j = 0; j < i; j++)
            {
                printf("*");
            }
            for (int j = size - 1 - (i - 1) / 2; j > 0; j--)
            {
                printf(" ");
            }
            printf("\n");
        }

    default:
        break;
    }
    return 0;
}