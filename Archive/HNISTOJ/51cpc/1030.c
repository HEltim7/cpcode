//水费问题
#include<stdio.h>
main()
{
    int inp;
    scanf("%d",&inp);
    if (inp<=10)
    {
        printf("%d",inp*6);
    }
    else if (inp<=20)
    {
        printf("%d",inp*7-10);
    }
    else
    {
        printf("%d",inp*10-70);
    }
    return 0;
}
