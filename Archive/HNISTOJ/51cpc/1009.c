//线段长度,平方pow，开方sqrt
#include<stdio.h>
#include<math.h>
main()
{
    float Xa,Xb,Ya,Yb,otp;
    scanf("%f%f",&Xa,&Ya);
    scanf("%f%f",&Xb,&Yb);
    otp=sqrt(pow((Yb-Ya),2)+pow((Xb-Xa),2));
    printf("%.2f\n",otp);
    return 0;
}