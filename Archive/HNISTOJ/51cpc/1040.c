//非负数的和
#include<stdio.h>
int main()
{
    int num,i,otp;
    scanf("%d",&num);
    int inp[num];
    for (i = 0; i < num; i++)
    {
        scanf("%d",&inp[i]);
        if (inp[i]<0)
        {
            break;
        }
        otp+=inp[i];
    }
    printf("%d",otp);
}