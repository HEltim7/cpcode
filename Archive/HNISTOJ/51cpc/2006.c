//分支程序1
#include<stdio.h>
int main()
{
    int a,b,c,d,i;
    scanf("%d%d%d",&a,&b,&c);
    scanf("%d",&d);
    for(i=0; i<3; i++)
    {
        if(a<=b&&a<=c)
        {   printf("%d\n",a);
            a=32768;
        }
        else if(b<=a&&b<=c)
        {   printf("%d\n",b);
            b=32768;
        }
        else
        {   printf("%d\n",c);
            c=32768;
        }
    }
    switch(d)
    {
    case 1:
        printf("Monday");
        break;
    case 2:
        printf("Tuesday");
        break;
    case 3:
        printf("Wednesday");
        break;
    case 4:
        printf("Tuesday");
        break;
    case 5:
        printf("Friday");
        break;
    case 6:
        printf("Saturday");
        break;
    case 0:
        printf("Sunday");
        break;
    }
    return 0;
}