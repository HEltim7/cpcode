//4011
#include<stdio.h>
int prim_num(int i)
{
    for(int j=i/2;j>1; j--)
    {
        if(i%j==0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int l,r,i,sum=0;
    scanf("%d%d",&l,&r);
    if(l%2==0)
    {
        l++;
    }
    for(i=l; i<r; i+=2)
    {
        sum+=prim_num(i);
    }
    printf("%d",sum);
    return 0;
}