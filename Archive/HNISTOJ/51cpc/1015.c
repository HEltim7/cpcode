//数位和
#include<stdio.h>
main()
{
    int inp,n1,n2,n3;
    scanf("%d",&inp);
    n3=inp%10;inp=inp/10;
    n2=inp%10;inp=inp/10;
    n1=inp%10;inp=inp/10;
    printf("%d %d %d\n",n1,n2,n3);
    printf("%d",n1+n2+n3);
}