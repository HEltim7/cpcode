#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
constexpr int N=2e5+10;
vector<int> adj[N];
int arr[N],p[N],up[N],dn[N],ans;
int dp[N];

void update(int a[],int idx,int &max1,int &max2) {
    if(a[idx]>=a[max1]) {
        max2=max1;
        max1=idx;
    }
    else if(a[idx]>a[max2]) max2=idx;
}

void dfs1(int u) {
    dn[u]=arr[u];
    for(int v:adj[u]) if(v!=p[u]) {
        p[v]=u;
        dfs1(v);
        dn[u]=max(dn[u],dn[v]+arr[u]);
    }
}

void dfs2(int u) {
    vector<int> cur(1,up[u]);
    int max1=0,max2=0;
    for(int v:adj[u]) if(v!=p[u]) {
        update(dn, v, max1, max2);
        cur.push_back(dn[v]);
    }

    for(int v:adj[u]) if(v!=p[u]) {
        if(v!=max1) up[v]=dn[max1]+arr[u];
        else up[v]=dn[max2]+arr[u];
        up[v]=max(up[v],up[u]+arr[u]);
        dfs2(v);
    }
    
    int res=0;
    sort(cur.begin(),cur.end(),greater<>());
    for(int i=0;i<min(4,int(cur.size()));i++) res+=cur[i];
    ans=max(ans,res);
}

void dfs3(int u) {
    dp[u]=dn[u];
    vector<int> cur,dpv;
    for(int v:adj[u]) if(v!=p[u]) {
        dfs3(v);
        cur.push_back(dn[v]);
        dp[u]=max(dp[u],dp[v]);
        dpv.push_back(dp[v]);
    }

    sort(cur.begin(),cur.end(),greater<>());
    sort(dpv.begin(),dpv.end(),greater<>());

    int res=0;
    for(int i=0;i<min(2,int(cur.size()));i++) res+=cur[i];
    dp[u]=max(dp[u],res+arr[u]);
    ans=max(ans,dp[u]);

    res=0;
    for(int i=0;i<min(2,int(dpv.size()));i++) res+=dpv[i];
    ans=max(ans,res);
}

void dfs4(int u) {
    vector<int> cur;
    for(int v:adj[u]) if(v!=p[u]) dfs4(v),cur.push_back(v);
    sort(cur.begin(),cur.end(),[](int x,int y) {
        return dn[x]>dn[y];
    });
    
    if(cur.size()) {
        for(int v:adj[u]) if(v!=p[u]) {
            int idx=0;
            if(v==cur[0]) {
                if(cur.size()>=2) idx=1;
                else break;
            }
            int res=dn[cur[idx]]+up[u]+arr[u];
            ans=max(ans,res+dp[v]);
        }
        for(int v:adj[u]) if(v!=p[u]) {
            int res=arr[u];
            for(int i=0,cnt=0;i<cur.size()&&cnt<2;i++)
                if(cur[i]!=v) cnt++,res+=dn[cur[i]];
            ans=max(ans,res+dp[v]);
        }
    }
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=2;i<=n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(n==1) {
        cout<<0<<endl;
        return;
    }
    
    dfs1(1);
    dfs2(1);
    dfs3(1);
    dfs4(1);
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}