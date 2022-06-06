//计算平均值
#include<stdio.h>
int main()
{
    int num,i;
    float otp;
    scanf("%d",&num);
    int dat[num];
    for (i = 0; i < num; i++)
    {
        scanf("%d",&dat[i]);
        otp+=dat[i];
    }
    otp=otp*1./num;
    printf("%.2f",otp);
    return 0;
}