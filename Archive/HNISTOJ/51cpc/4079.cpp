//form 1022
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    float n1,n2;
    float otp;
    char mth;
    cin>>n1>>n2>>mth;
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