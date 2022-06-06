//9的个数
//常规解法可以取出各位上的数
//不写n9=0和otp=0会出错？
#include<stdio.h>
int extract(int inp)
{
    int n9=0;
    for (inp; inp > 0 ; inp/=10)
    {
        if (inp%10==9)
        {
            n9++;
        }
    }
    return n9;
}
int main()
{
    int num,i,otp=0,extract(int);
    scanf("%d",&num);
    for (i = 9; i <= num; i++)
    {
        otp+=extract(i);
    }
    printf("%d",otp);
}