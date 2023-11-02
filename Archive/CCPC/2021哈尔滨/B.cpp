#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

const int N=100005,M=202;

int dp[N];
int prv[N][M/2];
int a[N];
int n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        for(int j=1;j<=100;j++)
        {
            prv[i][j]=prv[i-1][j];
        }
        prv[i][a[i]]=i;
    }

    int res=0;
    for(int w=2;w<=200;w++)
    {
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            dp[i]=0;
        }

        for(int i=1;i<=n;i++)
        {
            dp[i]=max(dp[i],dp[i-1]);
            if(w>a[i])
            {
                int x=w-a[i];

                if(x<=100&&prv[i-1][x])
                {
                    int j=prv[i-1][x];

                    dp[i]=max(dp[i],dp[j-1]+2);
                }
            }
        }
        res=max(res,dp[n]);
    }
    printf("%d\n",res);
}