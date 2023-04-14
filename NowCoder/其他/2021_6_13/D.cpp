#include<iostream>
#include<algorithm>
using namespace std;
long long n;
long long g[505][505];
long long a[505],idx=2;
long long h,l,pre;
bool st[505];
long long res;
long long newx;
int main()
{
	scanf("%lld",&n);
	
	
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=n;j++)
		{
			scanf("%lld",&g[i][j]);
		}
	 } 
	 
	 for(long long i=1;i<=n;i++)
	 {
	 	for(long long j=1;j<i;j++)
		 {
		 	if(g[i][j]>pre)
		 	{
		 		pre=g[i][j];
		 		h=i;
		 		l=j;
			 }
		  } 
	 }
	 
	 a[1]=h;
	 a[2]=l;
	 st[h]=true;
	 st[l]=true;
	 res+=g[h][l]*2;
	for(long long diedai=1;diedai<=n-3;diedai++)
	{
		pre=0;
	 	for(long long i=1;i<=n;i++)//以这个数为新增的点 
	 	{
	 		long long sum=0;
	 		if(st[i]==true)
	 		continue;
	 	
	 		else
	 		{
	 			for(long long j=1;a[j]!=0;j++)
	 			{
	 				sum+=g[a[j]][i]+g[i][a[j]];
				 }
			 }
		 	if(sum>pre)
		 	{
		 		pre=sum;
		 		newx=i;
		 	}
		 }
		st[newx]=true;
	 	a[++idx]=newx;
	 	res+=pre;
	}

	printf("%lld",res);
	return 0;
}