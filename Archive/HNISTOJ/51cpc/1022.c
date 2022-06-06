//简单计算器(1)
#include<stdio.h>
main()
{
    float n1,n2;
    float otp;
    char mth;
    scanf("%f%c%f",&n1,&mth,&n2);
    if (mth=='+')
    {
        otp=n1+n2;
    }
    else if(mth=='-')
    {
        otp=n1-n2;
    }
    else if(mth=='*')
    {
        otp=n1*n2;
    }
    else if(mth=='/')
    {
        if (n2!=0)
        {
            otp=n1/n2;
        }
        else
        {
            printf("-1");
            goto flag;
        }
    }
    else
    {
        printf("-1");
        goto flag;
    }
    if (otp-(int)otp==0)
    {
        printf("%d",(int)otp);
    }
    else
    {
        printf("%.1f",otp);
    }
    flag:return 0;
}