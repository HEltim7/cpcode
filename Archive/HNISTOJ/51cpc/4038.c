//水仙花
#include<stdio.h>
int main()
{
    int num,n1,n2,n3,flag,tmp;
    scanf("%d",&num);
    if (num>=100&&num<=999)
    {
        tmp=num;
        n3=num%10;num/=10;
        n2=num%10;num/=10;
        n1=num;
        flag=n1*n1*n1+n2*n2*n2+n3*n3*n3;
        if (flag==tmp)
        {
            printf("YES");
        }
        else
        {
            printf("NO");
        }
    }
    else
    {
        printf("ERROR");
    }
    return 0;
}