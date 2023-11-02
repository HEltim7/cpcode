#include <functional>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<set>
#include<vector>
#include<queue>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
template<class... T> void dbg(T... x) {((cerr<<x<<" "),...),cerr<<endl;}
#define __pos__ "["s+__func__+" "+to_string(__LINE__)+"] "
#define debug(...) cerr<<__pos__<<#__VA_ARGS__" = ", dbg(__VA_ARGS__)
#else
#define debug(...) 0
#endif

const int INF=0x3f3f3f3f;
typedef pair<int,int> pii;
const int N=100005,M=20;
double dp[1<<M][M][2];
bool st[1<<M][M][2];
int val[M][M];
int n,m;

vector<int> ver;
int p[N];

vector<pii> edg[N];
bool dij_st[N];
int dist[N];
int t,r;
void get(int x)
{
    for(int i=1;i<=n;i++) dij_st[i]=false,dist[i]=INF;
    priority_queue<pii,vector<pii>,greater<pii>> heap;
    dist[x]=0;
    heap.push({0,x});
    while(!heap.empty())
    {
        auto [_,u]=heap.top();
        heap.pop();
        if(dij_st[u]) continue;
        dij_st[u]=true;
        for(auto [v,w]:edg[u])
        {
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                heap.push({dist[v],v});
            }
        }
    }
}
double dfs(int s,int u,int ty)
{
    if(u==ver.size()-1) return 0.;
    if(st[s][u][ty]) return dp[s][u][ty];
    st[s][u][ty]=true;
    for(int v=0;v<ver.size();v++)
    {
        if(s>>v&1) continue;
        if(val[u][v]==INF) continue;

        int s2=(s^(1<<v));
        if(ty==1)
        {
            double ans=dfs(s2,v,ty)+val[u][v]*1./r;
            dp[s][u][ty]=min(dp[s][u][ty],ans);
        }
        else
        {
            double temp=p[ver[v]]/100.;
            double ans=(dfs(s2,v,1)*temp+dfs(s2,v,0)*(1-temp))+val[u][v]*1./t;
            dp[s][u][ty]=min(dp[s][u][ty],ans);
        }
    }
    return dp[s][u][ty];
}
int main()
{
    scanf("%d%d",&t,&r);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        edg[x].push_back({y,z});
        edg[y].push_back({x,z});
    }
    ver.push_back(1);
    ver.push_back(n);
    int k;
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
    {
        int x,y;
        scanf("%d",&x);
        ver.push_back(x);
        scanf("%d",&p[x]);
        p[x]=100-p[x];
    }
    sort(ver.begin(),ver.end());
    ver.erase(unique(ver.begin(),ver.end()),ver.end());
    for(int i=0;i<ver.size();i++)
    {
        get(ver[i]);
        for(int j=0;j<ver.size();j++)
        {
            val[i][j]=dist[ver[j]];
        }
    }
    if(val[0][ver.size()-1]==INF)
    {
        puts("-1");
        return 0;
    }
    for(int s=0;s<(1<<ver.size());s++)
        for(int i=0;i<ver.size();i++)
            for(int ty=0;ty<2;ty++)
                dp[s][i][ty]=INF;

    double temp=p[1]/100.;
    double res=(temp*dfs(1,0,1))+(1-temp)*dfs(1,0,0);

    printf("%.6lf\n",res);
}