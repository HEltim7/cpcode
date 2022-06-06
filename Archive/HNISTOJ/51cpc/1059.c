//子串位置
#include<stdio.h>
#include<string.h>
int main()
{
    char str1[32768],str2[32768];
    int judge=1;
    gets(str1);
    gets(str2);
    char *p1,*p2=&str2[0],*tmp=&str1[0];
    for ( p1 = &str1[0]; p1 < &str1[strlen(str1)] ; p1++)
    {
        for (p2; p2 < &str2[strlen(str2)]; p2++)
        {
            if (*p1!=*p2)
            {
                judge=0;
                break;
            }
            p1++;
        }
        if (judge)
        {
            goto end;
        }
        judge=1;
        p2=&str2[0];
    }
    return 0;
    end:printf("%d",p1-strlen(str2)-tmp+1);
    return 0;
}