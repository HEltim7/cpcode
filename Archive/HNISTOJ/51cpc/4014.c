//词组缩写
#include <stdio.h>
#include <string.h>
int main()
{
    char word[1024] = {0};
    int i = 0, lastspace = 0;
    void print(char);
    gets(word);
    print(word[0]);
    int len = strlen(word);
    for (i = 1; i < len; i++)
    {
        if (word[i] == ' ')
        {
            lastspace = i;
            print(word[lastspace + 1]);
        }
    }
    return 0;
}
void print(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        printf("%c", c - 32);
    }
    else if (c >= 'A' && c <= 'Z')
    {
        printf("%c", c);
    }
}