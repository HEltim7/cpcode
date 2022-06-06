//运算符与表达式应用2
#include<stdio.h>
int main()
{
    char alpha;
    int num,op[32],*p=&op[0];
    scanf("%c%d",&alpha,&num);
    if(num==0)
        goto zero;
    for(; num!=0; p++)
    {
        *p=num%10;
        num/=10;
    }
    if(alpha>='A'&&alpha<='Z')
        printf("%c\n",alpha+'a'-'A');
    else
        printf("%c\n",alpha+'A'-'a');
    p--;
    for(;; p--)
    {
        printf("%d\n",*p);
        if(p==&op[0])
            break;
    }
    return 0;
zero:
    if(alpha>='A'&&alpha<='Z')
        printf("%c\n",alpha+'a'-'A');
    else
        printf("%c\n",alpha+'A'-'a');
    printf("0");
    return 0;
}