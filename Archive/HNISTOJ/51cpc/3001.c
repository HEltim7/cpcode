#include<stdio.h>
int main()
{
    int ip,op=0;
    scanf("%d",&ip);
    for (int i = 2; i <= ip; i++)
    {
        op*=i;
    }
    
    return 0;
}