//四舍五入取整
#include<stdio.h>
int main()
{
    float n;
    int n1;
    scanf("%f",&n);
    if (n-(int)n>=0.5)
    {
        n1=(int)n+1;
    }
    else
    {
        n1=(int)n;
    }
    printf("%d",n1);
    return 0;
}