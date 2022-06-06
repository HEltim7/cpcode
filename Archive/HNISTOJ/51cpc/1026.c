//分段函数
#include<stdio.h>
main()
{
    int x;
    scanf("%d",&x);
    if (x<0)
    {
        printf("%d",x*x-1);
    }
    else if(x>=0&&x<=1)
    {
        printf("%d",x*x);
    }
    else
    {
        printf("%d",x*x+1);
    }
}