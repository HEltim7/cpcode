#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> E[200005];
typedef long long ll;
ll k;
int siz[200005];
vector<pair<int,int> > vec[200005];
int c[200005];
int ans = 0 , cnt = 0;
void upd(int &a,int b)
{
    a = max(a , b);
}
void work(int u,ll p,int d)
{
    if(vec[u].size() == 0) return;
    int l = 0 , r = vec[u].size() - 1;
    while(l < r) {
        int md = (l + r >> 1);
        if(vec[u][md].second >= p) r = md;
        else l = md + 1;
    }
    if(vec[u][l].second >= p) {
        ans = max(ans , d + vec[u][l].first);
    }
    return;
}
int Merge(int u,int v,int d)
{
    if(!u) return v;
    if(vec[u].size() < vec[v].size()) swap(u , v);
    for(int i = vec[v].size() - 1;i >= 0;i--) {
        ll p = (k + vec[v][i].second - 1) / vec[v][i].second ;
        work(u , p , vec[v][i].first - 2*d);
    }
    for(int i = vec[v].size() - 1;i >= 0;i--) {
        assert(vec[u].size() - 1 + (i - vec[v].size() + 1) >= 0);
        upd(vec[u][vec[u].size() - 1 + (i - vec[v].size() + 1)].second , vec[v][i].second);
    }
    return u;
}
void dfs(int fa,int u,int d)
{
    siz[u] = 1; c[u] = 0;
    ll dw = 1LL*n*n;
    for(auto v : E[u]) {
        if(v != fa) {
            dfs(u , v , d + 1) , siz[u] += siz[v];
            work(c[v] , (k + n - siz[v] - 1) / (n - siz[v]) , -d) ;
            c[u] = Merge(c[u] , c[v] , d);
            dw -= 1LL*siz[v]*siz[v];
        }
    }
    dw -= 1LL*(n - siz[u])*(n - siz[u]);
    dw = (dw + 1) / 2;
    if(dw >= k) ans = max(ans , 0);
    if(!c[u]) {c[u] = ++cnt;}
    vec[c[u]].push_back(pair<int,int>{d , siz[u]}) ;
    return;
}
void solve()
{
    scanf("%d%lld",&n,&k);
    for(int i = 1;i <= cnt;i++) vec[i].clear();
    for(int i = 1;i <= n;i++) E[i].clear();
    for(int i = 1;i < n;i++) {
        int u , v;scanf("%d%d",&u,&v);
        E[u].push_back(v) ; E[v].push_back(u);
    }
    ans = -1;cnt = 0;
    dfs(0 , 1 , 0);
    printf("%d\n",ans + 1);
    return;
}
void run()
{
    int t;scanf("%d",&t);
    while(t--) solve();
}
int main()
{
    run();
    return 0;
}
