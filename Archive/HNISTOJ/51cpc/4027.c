//单词翻转
#include <stdio.h>
#include <string.h>
int main()
{
    char str[1024], word[1024][1024];
    gets(str);
    int size = strlen(str), rank = 0, j = 0;
    for (int i = 0; i < size; i++)
    {
        if (str[i] == ' ')
        {
            rank++;
            j = 0;
            i++;
        }
        word[rank][j] = str[i];
        j++;
    }
    for (; rank >= 0; rank--)
        printf("%s ", word[rank]);
    return 0;
}