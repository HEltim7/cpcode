//求最大公约数
#include<stdio.h>
#include<math.h>
int main()
{
    long a,b,tmp=1;
    scanf("%d%d",&a,&b);
    if(b>a)//make a>b
    {
        tmp=a;
        a=b;
        b=tmp;
    }
    if (a==0)
    {
        printf("%d",b);
        goto exit;
    }
    else if (b==0)
    {
        printf("%d",a);
        goto exit;
    }
    else if (a==b)
    {
        goto exit_alt;
    }
    else
    while (tmp!=0)
    {
        tmp=a%b;
        a=b;
        b=tmp;
    }
    a=fabs(a);
    printf("%d",a);
    exit:return 0;
    exit_alt:printf("%d",a);return 0;
}