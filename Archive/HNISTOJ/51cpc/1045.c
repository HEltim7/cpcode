//输出图形
#include<stdio.h>
int main()
{
    int alpha,i,print(int,int);
    scanf("%c",&alpha);
    for (i = alpha; i >= 'A'; i--)
    {
        print(alpha,i);
    }
}
int print(int alpha,int var)
{
    int i,space;
    space=alpha-var;
    for (space; space > 0; space--)
    {
        printf(" ");
    }
    for (i = var; i >= 'A'; i--)
    {
        printf("%c",i);
    }
    for (i = 'A'; i < var; i++)
    {
        printf("%c",i);
    }
    printf("\n");
}