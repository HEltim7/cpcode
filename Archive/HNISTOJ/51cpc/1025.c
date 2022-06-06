//斜率计算2
#include<stdio.h>
#include<math.h>
int main()
{
    int x1,y1,x2,y2;
    int a,b,tmp=1,key,m,n;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    if (x1!=x2)
    {
	    //辗转相除
		a=y2-y1;b=x2-x1;
	    if(b>a)//make a>b
	    {
	        tmp=a;
	        a=b;
	        b=tmp;
	    }
	    while (tmp!=0)
	    {
	        tmp=a%b;
	        a=b;
	        b=tmp;
	    }
	    key=a;a=y2-y1;b=x2-x1;
	    m=a/key;n=b/key;
	    if(n<0)
	    {
	    	m=-m;n=-n;
		}
		printf("%d/%d",m,n);
    }
    else
    {
        printf("-1");
    }
    return 0;
}