//倒序输出
#include<stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    for (i = 0; i < n-1; i++)
    {
        printf("%d ",n-i);
    }
    printf("1");
}