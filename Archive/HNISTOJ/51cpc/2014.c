//递归程序设计2
#include<stdio.h>
int main()
{
    int n,fn(int);
    scanf("%d",&n);
    printf("%d",fn(n));
    return 0;
}
int fn(int n)
{
    int op;
    if (n==1)
    {
        return 1;
    }
    return n+fn(n-1);
}