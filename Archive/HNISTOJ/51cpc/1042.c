//倍数
#include<stdio.h>
main()
{
    int num,a,b,otp;
    int i;
    scanf("%d",&num);
    //a=num/30;
    //b=num-30*a;
    for(i=1;i<=num;i++)
    {
        if(i%2==0)
            otp+=1;
        else if(i%3==0)
            otp+=1;
        else if(i%5==0)
            otp+=1;
    }
    printf("%d",otp);
}