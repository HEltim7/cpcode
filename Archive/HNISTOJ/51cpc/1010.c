//绝对值求和
#include<stdio.h>
#include<math.h>
main()
{
    float a,b,otp;
    scanf("%f%f",&a,&b);
    otp=fabs(a)+fabs(b);
    printf("%.1f",otp);
}