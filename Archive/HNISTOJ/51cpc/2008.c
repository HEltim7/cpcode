//循环程序1
#include<stdio.h>
int main()
{
    int num,i=0;
    scanf("%d",&num);
    for(;num!=0;i++)
    {
        printf("%d\n",num%10);
        num/=10;
    }
    printf("%d",i);
    return 0;
}