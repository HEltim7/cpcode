//进制转换
#include<stdio.h>
int main()
{
    int inp,i=0,otp[32];
    scanf("%d",&inp);
    //除二倒取余
    if (inp==0)
    {
        goto flag;
    }
    else if(inp>0)
    {
        while (inp!=0)
        {
        otp [i]=(inp%2);
        i++;
        inp/=2;
        }
        for (i; i > 0 ; i--)
        {
            printf("%d",otp[i-1]);
        }
    }
    else
    {
        inp=-inp;
        while (inp!=0)
        {
        otp [i]=(inp%2);
        i++;
        inp/=2;
        }
        printf("-");
        for (i; i > 0 ; i--)
        {
            printf("%d",otp[i-1]);
        }
    }
    return 0;
    flag:printf("0");return 0;
}