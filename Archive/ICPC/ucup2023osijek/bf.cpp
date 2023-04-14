#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
// #define debug(x) cout<<"[debug]"#x<<"="<<x<<endl
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const double eps=1e-8;
const int INF=0x3f3f3f3f,mod=998244353;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

const int N=100;
int a[N][N];
bool r[N];
bool c[N];
int n;
pii from[N][N];
int dt[8][2]={{1,3},{-1,3},{1,-3},{-1,-3},{3,1},{3,-1},{-3,1},{-3,-1}};
int biao[N][N][2];
bool ok;
void dfs(int x,int y,int lun)
{
    if(lun==n)
    {
        vector<pii> path;
        pii now={x,y};
        while(now.first!=1&&now.first!=1)
        {
            path.push_back(now);
            now=from[now.first][now.second];
        }
        path.push_back(now);
        reverse(path.begin(),path.end());
        debug(n);
        
        printf("{");
        for(int i=0;i<path.size();i++)
        {
            auto &[dx,dy]=path[i];
            printf("{");
            printf("%d,%d",dx,dy);
            printf("}");
            if(i!=path.size()-1) printf(",");
        }
        printf("},");
        ok=true;
    }
    if(lun==n) return ;
    for(int i=0;i<8;i++)
    {
        int dx=x+dt[i][0];
        int dy=y+dt[i][1];
        if(dx>=1&&dx<=n&&dy>=1&&dy<=n&&!r[dx]&&!c[dy]&&!ok)
        {
            a[dx][dy]=1;
            r[dx]=true;
            c[dy]=true;
            from[dx][dy]={x,y};
            dfs(dx,dy,lun+1);
            a[dx][dy]=0;
            r[dx]=false;
            c[dy]=false;
        }
    }
}
int main()
{
    freopen("1.out","w",stdout);
    printf("{");
    for(n=1;n<=57;)
    {
        ok=false;
        for(int i=1;i<=n&&!ok;i++)
        {
            for(int j=1;j<=n&&!ok;j++)
            {
                ok=false;
                a[i][j]=1;
                r[i]=true;
                c[j]=true;
                dfs(i,j,1);
                a[i][j]=0;
                r[i]=false;
                c[j]=false;
            }
        }
        if(!ok) printf("{},");
        n++;
    }
    printf("}");
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}
