#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const int N=205;
struct lwy
{
	int type;
	double x;
}a[N];
int n;
bool check()
{
	for(int i=2;i<=n;i++)
	{
		if(a[i].type<=a[i-1].type&&a[i-1].x>a[i].x)
		return false;
		else if(a[i].type>a[i-1].type&&sqrt(2)*a[i-1].x>a[i].x)
		return false;
	}
	return true;
}
int main()
{
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		char op[20];
		scanf("%s",op);
		scanf("%lf",&a[i].x);
		if(op[1]=='u')
		{
			a[i].type=1;//1类型代表正方体 
		}
		else
		{
			a[i].x=a[i].x*2;
			a[i].type=2;//2类型代表圆柱体 
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=2;j<=n-i;j++)
		{
			if(a[j].type<=a[j-1].type&&a[j-1].x>a[j].x)
			{
				swap(a[j-1],a[j]);
			}
			else if(a[j].type>a[j-1].type&&sqrt(2)*a[j-1].x>a[j].x)
			{
				swap(a[j-1],a[j]);
			}
		 } 
	}
	if(!check())
	{
		puts("impossible");
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i].type==1)
			printf("cube %d\n",(int)a[i].x);
			else
			printf("cylinder %d\n",(int)a[i].x/2);
		}
	}
}