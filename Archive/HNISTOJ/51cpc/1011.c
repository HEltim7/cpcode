//三角函数值
#include<math.h>
#include<stdio.h>
//#define PI=3.1415926
main()
{
    float alpha,tmp;
    scanf("%f",&alpha);
    tmp=alpha*3.1415926/180;
    printf("%.2f\n%.2f\n",sinf(tmp ),cosf(tmp));
}