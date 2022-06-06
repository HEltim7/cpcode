//三角形判断及面积,if和else if中间不能有语句，否则会if断裂
//浮点数型对象计算时如果数据都是整型，可以用0.隐形转换处理
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
    if (a+b<=c||a+c>=b||b+c>=a||a<=0||b<=0||c<=0)
    {
        printf("ERROR");
        goto flag;
    }
    else if(cosa==0||cosb==0||cosc==0)
    {
        printf("直角三角形\n");
    }
    else if(cosa>0&&cosb>0&&cosc>0)
    {
        printf("锐角三角形\n");
    }
    else
    {
        printf("钝角三角形\n");
    }
    p=(a+b+c+0.)/2;
    printf("%.2f",sqrt(p*(p-a)*(p-b)*(p-c)*1.));
    flag:return 0;
}