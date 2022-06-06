//大小写字母转换
#include<stdio.h>
int main()
{
    char alpha;
    alpha=getchar();
    if (alpha>='A'&&alpha<='Z')
    {
        putchar(alpha-'A'+'a');
    }
    else if (alpha>='a'&&alpha<='z')
    {
        putchar(alpha-'a'+'A');
    }
    else
    {
        putchar('#');
    }
    return 0;
}