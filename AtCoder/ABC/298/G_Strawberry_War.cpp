#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=7;
constexpr LL INF=1e18;
LL dp[N][N][N][N][N*N];
bool mark[N][N][N][N][N*N];
LL s[N][N],pre[N][N];

LL get(int l,int r,int u,int d) {
    return pre[r][d]-pre[l-1][d]-pre[r][u-1]+pre[l-1][u-1];
}

#define idx [l][r][u][d][t]
LL dfs(int l,int r,int u,int d,int t,LL b) {
    LL maxx=INF;
    if(mark idx) return dp idx;
    if(t==0) return get(l,r,u,d)<b?INF:get(l,r,u,d);
    if(l==r&&u==d) return INF;
    for(int i=l;i<r;i++) {
        for(int j=0;j<t;j++) {
            LL x=dfs(l,i,u,d,j,b);
            if(x<b) continue;
            LL y=dfs(i+1,r,u,d,t-j-1,b);
            if(y<b) continue;
            maxx=min(maxx,max(x,y));
        }
    }
    for(int i=u;i<d;i++) {
        for(int j=0;j<t;j++) {
            LL x=dfs(l,r,u,i,j,b);
            if(x<b) continue;
            LL y=dfs(l,r,i+1,d,t-j-1,b);
            if(y<b) continue;
            maxx=min(maxx,max(x,y));
        }
    }
    mark idx=1;
    return dp idx=maxx;
}
#undef idx

void solve() {
    int h,w,t;
    cin>>h>>w>>t;
    for(int i=1;i<=h;i++) {
        for(int j=1;j<=w;j++) {
            cin>>s[i][j];
            pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+s[i][j];
        }
    }

    vector<LL> v;
    for(int l=1;l<=h;l++) {
        for(int r=l;r<=h;r++) {
            for(int u=1;u<=w;u++) {
                for(int d=u;d<=w;d++) {
                    LL b=get(l, r, u, d);
                    if(b<=pre[h][w]/(t+1)) v.push_back(b);
                }
            }
        }
    }

    LL ans=INF;
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(LL b:v) {
        memset(mark, 0, sizeof mark);
        LL res=dfs(1, h, 1, w, t, b);
        ans=min(ans,res-b);
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}