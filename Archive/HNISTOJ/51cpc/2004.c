//运算符与表达式应用1
#include<stdio.h>
int main()
{
    int a,b,c,d;
    int judge1=0,judge2=0,judge3=0,judge4=0,judge5=0;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(a==b)
        judge1=1;
    else
        judge5=1;
    if(a!=b&&c<d)
        judge2=1;
    if(a==b||a==c)
        judge3=1;
    if(c%d!=2)
        judge4=1;
    printf("%d\n%d\n%d\n%d\n%d\n",judge1,judge5,judge2,judge3,judge4);
    return 0;
}