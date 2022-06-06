//相反字符串
#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    gets(str);
    int l=strlen(str),i;
    for(i=l-1;i>=0;i--)
        printf("%c",str[i]);
    return 0;
}