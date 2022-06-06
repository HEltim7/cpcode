//Fibonacci数列，第一项为第0项
#include<stdio.h>
int main()
{
    int num,a=0,b=1,c=1;
    scanf("%d",&num);
    if(num==0)
    {
        printf("0");
    }
    else
    {
        num-=1;
        for(num; num>0; num--)
        {
            c=a+b;
            a=b;
            b=c;
        }
        printf("%d",c);
    }
    return 0;
}