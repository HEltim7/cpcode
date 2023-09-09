#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<tuple>
#include<queue>
#include<cmath>
using namespace std;
// #define debug(x) cout<<"[debug]"#x<<"="<<x<<endl
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const ld eps=1e-8;
const int INF=0x3f3f3f3f,mod=998244353;
const ll INFF=0x3f3f3f3f3f3f3f3f;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

typedef tuple<int,int,int> tp;
const int N=155;
tuple<int,int,int> edg[N][N];
int n,t;
int x[N],y[N];
bool st[N];
int dist[N];
int pre[N];
int main()
{
    scanf("%d%d",&n,&t);
    scanf("%d%d",&x[0],&y[0]);
    scanf("%d%d",&x[n+1],&y[n+1]);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
    }

    //<后继点,代价>
    /*传送门到传送门*/
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            edg[i][j]={x[i],y[j],t};
        }
    }

    /*传送门到点*/
    for(auto ty:vector<int>{0,n+1})
    {
        for(int i=1;i<=n;i++)
        {
            int xl=x[i],yl=y[i];
            int x2=x[ty],y2=y[ty];
            int disx=abs(x2-xl);
            int disy=abs(y2-yl);
            if(disx<disy) edg[i][ty]={x[ty],y[ty],disx};//y相同
            else edg[i][ty]={x[ty],y[ty],disy};//x相同
        }
    }
    /*点到传送门*/
    for(auto ty:vector<int>{0,n+1})
    {
        for(int i=1;i<=n;i++)
        {
            int xl=x[i],yl=y[i];
            int x2=x[ty],y2=y[ty];
            int disx=abs(x2-xl);
            int disy=abs(y2-yl);
            if(disx<disy) edg[ty][i]={x[i],y[ty],disx+t};//y相同
            else edg[ty][i]={x[ty],y[i],disy+t};//x相同
        }
    }
    // /*点到点*/
    // edg[0][n+1]={x[0],y[0],abs(x[0]-x[n+1])+abs(y[0]-y[n+1])};
    edg[0][n+1]=edg[n+1][0]={0,0,INF};
    priority_queue<tp,vector<tp>,greater<tp>> heap;
    memset(dist,0x3f,sizeof dist);
    dist[0]=0;
    heap.push({dist[0],-1,0});
    //代价，前驱，当前点，
    while(!heap.empty())
    {
        auto [_,last,u]=heap.top();
        heap.pop();
        if(st[u]) continue;
        st[u]=true;
        pre[u]=last;
        for(int v=0;v<=n+1;v++)
        {
            if(dist[v]>dist[u]+get<2>(edg[u][v]))
            {
                dist[v]=dist[u]+get<2>(edg[u][v]);
                heap.push({dist[v],u,v});
            }
        }
    }
    if(1ll*dist[n+1]*dist[n+1]>1ll*(x[0]-x[n+1])*(x[0]-x[n+1])+1ll*(y[0]-y[n+1])*(y[0]-y[n+1]))
    {
        long double res=sqrtl(1ll*(x[0]-x[n+1])*(x[0]-x[n+1])+1ll*(y[0]-y[n+1])*(y[0]-y[n+1]));
        printf("%.10Lf\n",res);
        printf("%d\n",1);
        printf("%d %d %d\n",0,x[n+1],y[n+1]);
        return 0;
    }
    printf("%d\n",dist[n+1]);

    vector<tp> path;
    int cur=n+1;
    while(cur!=0)
    {
        int last=pre[cur];
        auto [xx,yy,_]=edg[last][cur];
        if(last>=1&&last<=n&&(cur<1||cur>n))//last->cur
        {
            if(cur==n+1&&(x[last]==x[cur]||y[last]==y[cur]))
            {
                path.push_back({last,xx,yy});
            }
            else
            {
                path.push_back({0,xx,yy});
                if(abs(y[last]-yy)<abs(x[last]-xx)) path.push_back({last,xx,y[last]});
                else path.push_back({last,x[last],yy});
            }
        }
        else
        {
            path.push_back({last,xx,yy});
        }
        cur=last;
    }
    reverse(path.begin(),path.end());
    printf("%d\n",int(path.size()));
    for(auto [t,x,y]:path)
    {
        printf("%d %d %d\n",t,x,y);
    }
}