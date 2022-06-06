//小鱼游了多久？
#include<stdio.h>
int main()
{
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    printf("%d",(c-a-1)*60+(60-b+d));
    return 0; 
}