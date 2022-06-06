//整除问题
#include<stdio.h>
main()
{
    int inp1,inp2;
    float judge;
    scanf("%d%d",&inp1,&inp2);
    judge=(float)inp1/(float)inp2;
    if (judge-(int)judge==0)
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }
}