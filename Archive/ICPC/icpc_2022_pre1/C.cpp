#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N=1000006,M=2*N;
int h[N],ne[M],e[M],idx;
ll res;
void add(int x,int y)
{
    e[idx]=y,ne[idx]=h[x],h[x]=idx++;
}
void dfs(int u,int fa)
{
    int deg=0;
    for(int i=h[u];~i;i=ne[i])
    {
        int v=e[i];

        if(v==fa) continue;
        dfs(v,u);
        deg++;
    }

    if(u==1)
    {
        if(deg<=2) res+=2;
        else res+=deg;
    }
    else
    {
        res+=max(deg-1,0);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        res=0;
        int n;
        scanf("%d",&n);

        memset(h,-1,sizeof (int)*(n+2));

        for(int i=1;i<=n-1;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            add(x,y);
            add(y,x);
        }
        if(n==1)
        {
            puts("1");
            continue;
        }
        dfs(1,-1);
        printf("%lld\n",res);
    }
}