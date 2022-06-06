//判断正负数
#include<stdio.h>
main()
{
    long k;
    scanf("%d",&k);
    if (k>0)
    {
        printf("positive");
    }
    else if (k<0)
    {
        printf("negative");
    }
    else
    {
        printf("zero");
    }

}