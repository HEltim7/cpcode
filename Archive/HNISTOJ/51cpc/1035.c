//简单计算器进阶
#include<stdio.h>
int main()
{
    int num,i,otp;
    scanf("%d",&num);
    int data[num];
    for (i=0; i < num; i++)
    {
        scanf("%d",&data[i]);
        otp+=data[i];
    }
    printf("%d",otp);
    return 0;
}