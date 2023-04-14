#pragma GCC optimize("O2")
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
using PIL=pair<int,LL>;
constexpr int N=1.5e5+10;
int age[N];

namespace cd {
    constexpr int M=N;
    vector<PII> ori[M],p[M];
    vector<int> ch[M];
    vector<PIL> pre[M][3];
    int sz[M],centroid[2];
    bool del[M];

    void get_centroid(int u,int fa,int tot) {
        int maxx=0;
        sz[u]=1;
        for(auto [v,_]:ori[u]) {
            if(v!=fa&&!del[v]) {
                get_centroid(v,u,tot);
                sz[u]+=sz[v];
                maxx=max(maxx,sz[v]);
            }
        }
        maxx=max(maxx,tot-sz[u]);
        if(maxx<=tot/2) centroid[centroid[0]!=0]=u;
    }

    LL solve(int u,int l,int r) {
        LL ans=0;

        auto cal=[&](int rt,int id,int len) {
            auto &v=pre[rt][id];
            if(v.empty()) return 0LL;
            auto cmp=[](const PIL &x,const PIL &y) {
                return x.first<y.first;
            };
            int L=lower_bound(
                v.begin(),v.end(),PIL(l,1),cmp
            ) -v.begin();
            int R=--lower_bound(
                v.begin(),v.end(),PIL(r+1,0),cmp
            ) -v.begin();
            int cnt=R-L+1;
            LL res=1LL*cnt*(len);
            res+=v[R].second-v[L-1].second;
            return res;
        };

        for(int i=0;i<ch[u].size();i++)
            ans+=cal(u, i, 0);
        int ignore=u;
        for(auto [rt,dis]:p[u]) {
            for(int i=0;i<ch[rt].size();i++)
                if(ch[rt][i]!=ignore) ans+=cal(rt, i, dis);
            if(age[rt]>=l&&age[rt]<=r) ans+=dis;
            ignore=rt;
        }
        return ans;
    }

    void get_dist(int u,int fa,int rt,int id,int dis) {
        pre[rt][id].emplace_back(age[u],dis);
        p[u].emplace_back(rt,dis);
        for(auto [v,l]:ori[u]) {
            if(v!=fa&&!del[v]) {
                get_dist(v, u, rt, id, dis+l);
            }
        }
    }

    int build(int _u,int tot) {
        centroid[0]=centroid[1]=0;
        get_centroid(_u, -1, tot);
        int u=centroid[0];
        get_centroid(u, -1, tot);
        del[u]=1;

        int idx=0;
        for(auto [v,l]:ori[u]) {
            if(del[v]) continue;

            pre[u][idx].emplace_back(-1,0);
            get_dist(v,u,u,idx,l);
            sort(pre[u][idx].begin(),pre[u][idx].end());
            for(int j=1;j<pre[u][idx].size();j++)
                pre[u][idx][j].second+=pre[u][idx][j-1].second;
            ch[u].emplace_back(build(v, sz[v]));
            idx++;
        }
        return u;
    }

    void init(int n) {
        build(1, n);
        for(int i=1;i<=n;i++) reverse(p[i].begin(),p[i].end());
    }
}

void solve() {
    int n,Q,A;
    cin>>n>>Q>>A;
    for(int i=1;i<=n;i++) cin>>age[i];
    for(int i=1;i<n;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        cd::ori[u].emplace_back(v,w);
        cd::ori[v].emplace_back(u,w);
    }
    cd::init(n);

    int idx=0;
    LL ans=0;
    while(Q--) {
        int u,a,b,l,r;
        cin>>u>>a>>b;
        l=min((a+ans)%A,(b+ans)%A);
        r=max((a+ans)%A,(b+ans)%A);
        ans=cd::solve(u, l, r);
        cout<<ans<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}