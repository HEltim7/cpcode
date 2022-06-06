//十进制转八进制
#include<stdio.h>
int main()
{
    int d,o[32],i=0,neg=0;
    scanf("%d",&d);
    if(d<0)
    {
        neg=1;
        d=-d;
    }
    if(d!=0)
    {
        for(; d>0; d/=8)
        {
            o[i]=d%8;
            i++;
        }
        i--;
        if(neg)
        {
            printf("-");
            for(; i>=0; i--)
            {
                printf("%d",o[i]);
            }
        }
        else
        {
            for(; i>=0; i--)
            {
                printf("%d",o[i]);
            }
        }
    }
    else if(d==0)
    {
        printf("0");
    }
    return 0;
}