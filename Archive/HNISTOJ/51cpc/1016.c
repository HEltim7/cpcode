//找零问题
#include<stdio.h>
main()
{
    int cost,charge10,charge1;
    scanf("%d",&cost);
    charge10=(50-cost)/10;
    charge1=(50-cost)%10;
    printf("%d\n%d\n",charge10,charge1);
}