#include <stdio.h>
#include <string.h>
char str[10000];
char insert;

int main()
{
    int output = 0;
    scanf("%s", &str);
    scanf("%s", &insert);
    for (int i = 0; i < strlen(str); i++)
    {
        if (insert <= str[i] && !output)
        {
            printf("%c", insert);
            output = 1;
        }
        printf("%c", str[i]);
    }
    return 0;
}