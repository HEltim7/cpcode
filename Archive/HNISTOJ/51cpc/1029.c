//机票打折
#include<stdio.h>
main()
{
    int cost;
    scanf("%d",&cost);
    if (cost<200)
    {
        printf("%.2f",cost*1.);
    }
    else if(cost>=200&&cost<500)
    {
        printf("%.2f",cost*0.9);
    }
    else if(cost>=500&&cost<1000)
    {
        printf("%.2f",cost*0.8);
    }
    else
    {
        printf("%.2f",cost*0.5);
    }
    return 0;
}