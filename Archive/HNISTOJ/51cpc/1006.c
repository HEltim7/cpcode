//1006虚数求和
#include<stdio.h>
main()
{
    float a,ai,b,bi;
    scanf("%f%f",&a,&ai);
    scanf("%f%f",&b,&bi);
    printf("%5.2f ",a+b);
    printf("%5.2fi\n",ai+bi);
    return 0;
}