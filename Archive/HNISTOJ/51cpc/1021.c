//成绩等级
#include<stdio.h>
main()
{
    int inp;
    scanf("%d",&inp);
    if (inp>=90)
    {
        printf("A");
    }
    else if(inp>=80)
    {
        printf("B");
    }
    else if(inp>=70)
    {
        printf("C");
    }
    else if(inp>=60)
    {
        printf("D");
    }
    else
    {
        printf("E");
    }
}