#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
vector<int> adj[N];
vector<pair<int,int>> edg[N];
bool del[N];

int sz[N],centroid[2];
void get_centroid(int u,int fa,int tot) {
    int maxx=0;
    sz[u]=1;
    for(int v:adj[u]) {
        if(v!=fa&&!del[v]) {
            get_centroid(v,u,tot);
            sz[u]+=sz[v];
            maxx=max(maxx,sz[v]);
        }
    }
    maxx=max(maxx,tot-sz[u]);
    if(maxx<=tot/2) centroid[centroid[0]!=0]=u;
}

int maxx[N];
void get_maxx(int u,int fa,int dep,int siz) {
    maxx[dep]=max(maxx[dep],siz);
    for(auto [v,s]:edg[u]) {
        if(v!=fa&&!del[v]) {
            get_maxx(v, u, dep+1, s);
        }
    }
}

LL count(int u,int fa,int dep,int len,int siz) {
    LL res=0;
    if(len-dep>=0) res=max(res,1LL*siz*maxx[len-dep]);
    for(auto [v,s]:edg[u]) {
        if(v!=fa&&!del[v]) {
            res=max(res,count(v,u,dep+1,len,s));
        }
    }
    return res;
}

int n;
LL k;

bool solve(int _u,int tot,int len) {
    if(len>tot) return 0;
    centroid[0]=centroid[1]=0;
    get_centroid(_u, -1, tot);
    int u=centroid[0];
    del[u]=1;

    for(int i=0;i<=tot;i++) maxx[i]=0;
    for(auto [v,s]:edg[u]) {
        if(!del[v]) {
            maxx[0]=n-s;
            if(count(v, u, 1, len-1, s)>=k) return 1;
            get_maxx(v, u, 1, s);
        }
    }

    for(auto [v,s]:edg[u]) if(!del[v]) if(solve(v,sz[v],len)) return 1;
    return 0;
}

void build(int u,int fa,int tot) {
    for(int v:adj[u]) {
        if(v!=fa) {
            edg[u].emplace_back(v,sz[v]);
            edg[v].emplace_back(u,tot-sz[v]);
            build(v, u, tot);
        }
    }
}

void solve() {
    cin>>n>>k;
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=1;i<=n;i++) edg[i].clear();
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    get_centroid(1, -1, n);
    build(1, -1, n);

    auto slv=[&](int x) {
        bool res=solve(1,n,x);
        for(int i=1;i<=n;i++) del[i]=0;
        return res;
    };

    auto getr=[&]() {
        auto check=[&](int len) {
            LL x=(n-len+2)/2;
            LL y=(n-len+2+1)/2;
            return k<=x*y;
        };

        int l=1,r=n;
        while(l<r) {
            int mid=l+r+1>>1;
            if(check(mid)) l=mid;
            else r=mid-1;
        }
        return r;
    };

    int l=1,r=getr();
    while(l<r) {
        int mid=l+r+1>>1;
        if(slv(mid)) l=mid;
        else r=mid-1;
    }

    int ans=l;
    if(ans==1) {
        bool valid=0;
        for(int i=1;i<=n;i++) {
            LL res=1,tot=n;
            for(auto [v,s]:edg[i]) {
                tot-=s;
                res+=s*tot;
            }
            if(res>=k) {
                valid=1;
                break;
            }
        }
        if(!valid) ans=0;
    }

    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}