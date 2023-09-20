#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
#include <cassert>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e6+10;
int fa[N],sz[N],cnt[N];

int findfa(int x) {
    if(fa[x]==x) return x;
    return fa[x]=findfa(fa[x]);
}

bool join(int x,int y) {
    x=findfa(x),y=findfa(y);
    cnt[y]++;
    if(x==y) return false;
    fa[y]=x;
    sz[x]+=sz[y];
    cnt[x]+=cnt[y];
    return true;
}

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1,cnt[i]=0;
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        join(u, v);
    }

    vector<int> vec;
    LL ans=0;
    for(int i=1;i<=n;i++) if(findfa(i)==i) {
        LL res=1LL*sz[i]*(sz[i]-1)/2-cnt[i];
        if(res>=1) ans+=res;
        else vec.emplace_back(sz[i]);
    }
    if(ans==0) {
        sort(vec.begin(),vec.end());
        if(vec.size()>=2) ans=1LL*vec[0]*vec[1];
    }
    assert(ans);
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}