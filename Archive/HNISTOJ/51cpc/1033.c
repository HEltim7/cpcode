//判断闰年
#include<stdio.h>
int main()
{
    int year,flag=0;
    scanf("%d",&year);
    if (year%4==0&&year%100!=0)
    {
        flag=1;
    }
    else if (year%400==0&&year%3200!=0)
    {
        flag=1;
    }
    else if (year%80000==0)
    {
        flag=1;
    }
    if (flag==1)
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }
}