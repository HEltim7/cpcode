//多种图形求面积
#include<stdio.h>
main()
{
    int type;
    float a,b;
    scanf("%d",&type);
    if (type==1)
    {
        scanf("%f%f",&a,&b);
        printf("%d",(int)(a*b));
    }
    else if (type==2)
    {
        scanf("%f%f",&a,&b);
        printf("%d",(int)(a*b/2));
    }
    else if (type==3)
    {
        scanf("%f",&a);
        printf("%d",(int)(a*a*3.1415936));
    }
    return 0;
}