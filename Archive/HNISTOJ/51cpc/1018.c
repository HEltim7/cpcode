//鸡兔同笼
#include<stdio.h>
main()
{
    int m,n,r,c;
    scanf("%d%d",&m,&n);
    c=2*m-0.5*n,r=0.5*n-m;
    printf("%d %d",c,r);
}