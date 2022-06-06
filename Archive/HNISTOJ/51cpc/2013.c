//递归程序设计
#include<stdio.h>
int main()
{
    int num,fn(int);
    scanf("%d",&num);
    fn(num);
    return 0;
}
int fn(int num)
{
    if (num==0)
    {
        return 1;
    }
    printf("%d\n",num%10);
    num/=10;
    return fn(num);
}