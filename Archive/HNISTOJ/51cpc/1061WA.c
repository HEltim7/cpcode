//单词统计
#include<stdio.h>
#include<string.h>
int main()
{
    int num,judge=0,i=0;
    char str[2000];
    gets(str);
    while (str[i]!='\0')
    {
        if (str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z')
        {
            if (judge<1)
            {
                num++;
                judge=1;
            }
        }
        else
        {
            judge=0;
        }
        i++;
    }
    printf("%d",num);
    return 0;
}