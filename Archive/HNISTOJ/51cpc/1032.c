//一元二次方程的根
#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c;
    float dlt,x1,x2;
    scanf("%d%d%d",&a,&b,&c);
    dlt=b*b-4*a*c*1.;
    x1=(-b-sqrt(dlt))/(2*a*1.);
    x2=(-b+sqrt(dlt))/(2*a*1.);
    if (dlt<0||a==0)
    {
        printf("error");
    }
    else if(dlt!=0)
    {
        printf("%.0f ",x1);
        printf("%.0f",x2);
    }
    else
    {
        printf("%.0f",x1);
    }
    return 0;
}