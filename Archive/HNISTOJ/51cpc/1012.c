//期末成绩
#include<stdio.h>
#include<math.h>
main()
{
    float inp1,inp2,inp3,otp;
    scanf("%f%f%f",&inp1,&inp2,&inp3);
    otp=0.2*inp1+0.3*inp2+0.5*inp3;
    printf("%.1f",otp);
}