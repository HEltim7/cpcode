//斜率
#include<stdio.h>
main()
{
    float Xa,Xb,Ya,Yb;
    scanf("%f%f",&Xa,&Ya);
    scanf("%f%f",&Xb,&Yb);
    printf("%.2f\n",(Yb-Ya)/(Xb-Xa));
    return 0;
}