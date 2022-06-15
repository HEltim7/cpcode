#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e3+10,INF=0x3f3f3f3f;
bool matrix[N][N];
int up[N],dn[N],l[N][N],r[N][N];

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<debug>
#else
#define debug(...)
#endif

void solve() {
    int n,m;
    cin>>n>>m;
    memset(up,0x3f,sizeof (int)*(m+2));
    memset(dn,-1,sizeof (int)*(m+2));
    for(int i=0;i<=n;i++) {
        memset(l[i],-1,sizeof (int)*(m+2));
        memset(r[i],-1,sizeof (int)*(m+2));
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) {
            char in;
            cin>>in;
            matrix[i][j]=in=='B';
            if(matrix[i][j]) {
                up[j]=min(up[j],i);
                dn[j]=max(dn[j],i);
            }
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) {
            if(l[i][j-1]!=-1) l[i][j]=l[i][j-1]+1;
            if(up[j]!=INF) l[i][j]=max(l[i][j],abs(up[j]-i));
            if(dn[j]!=-1) l[i][j]=max(l[i][j],abs(dn[j]-i));
        }
    for(int i=1;i<=n;i++)
        for(int j=m;j>=1;j--) {
            if(r[i][j+1]!=-1) r[i][j]=r[i][j+1]+1;
            if(up[j]!=INF) r[i][j]=max(r[i][j],abs(up[j]-i));
            if(dn[j]!=-1) r[i][j]=max(r[i][j],abs(dn[j]-i));
        }
    
    pair<int,int> ans={1,1};
    int maxx=n+m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) {
            int res=max(l[i][j],r[i][j]);
            if(res<=maxx) ans={i,j},maxx=res;
        }
    debug(maxx,ans);
    cout<<ans.first<<' '<<ans.second<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}