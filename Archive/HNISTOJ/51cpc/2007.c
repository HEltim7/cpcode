//分支程序2
#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c;
    float dlt,x1,x2,ai,bi;
    scanf("%d%d%d",&a,&b,&c);
    dlt=b*b-4*a*c*1.;
    if(a==0)
    {
        x1=-c*1./b;
        printf("x=%.2f",x1);
    }
    else if (dlt<0)
    {
        ai=-b*1./(2*a);
        bi=sqrt(-dlt)/2*a;
        printf("x1=%.2f+%.2fj\n",ai,bi);
        printf("x2=%.2f-%.2fj",ai,bi);
    }
    else if(dlt>=0)
    {
        x1=(-b-sqrt(dlt))/(2*a*1.);
        x2=(-b+sqrt(dlt))/(2*a*1.);
        printf("x1=%.2f\n",x1);
        printf("x2=%.2f",x2);
    }
    return 0;
}