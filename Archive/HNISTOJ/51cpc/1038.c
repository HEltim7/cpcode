//求n的阶乘
#include<stdio.h>
int main()
{
    int n,i,otp=1;
    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        otp*=(n-i);
    }
    printf("%d",otp);
}