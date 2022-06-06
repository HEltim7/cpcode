#include<stdio.h>
#include<math.h>
main()
{
    int a,b,c;
    float cosa,cosb,cosc,p;
    scanf("%d%d%d",&a,&b,&c);
    cosa=(a*a+b*b-c*c+0.)/(2*a*b);
    cosb=(a*a+c*c-b*b+0.)/(2*a*c);
    cosc=(c*c+b*b-a*a+0.)/(2*c*b);
    if (a+b<=c||a-b>=c||a<=0||b<=0||c<=0)
    {
        printf("ERROR");
        goto flag;
    }
    else if(cosa>0&&cosb>0&&cosc>0)
    {
        printf("?????\n");
    }
    else if(cosa==0||cosb==0||cosc==0)
    {
        printf("?????\n");
    }
    else
    {
        printf("?????\n");
    }
    p=(a+b+c+0.)/2;
    printf("%.2f",sqrtf(p*(p-a)*(p-b)*(p-c)));
    flag:return 0;
}
