#pragma GCC optimize("O2")
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
constexpr int N=1e5+10,M=5e4+10;
LL ans[N];
PII p[N],tmp[N],bak[N];
int pos[N];

template<typename T=int> struct Fenwick {
    int size=0;
    vector<T> tr;

    int lowbit(int x) { return x&(-x); }

    void update(T &aim,const T &val) { aim+=val; }

    void add(int pos,T val) {
        while(pos<=size) update(tr[pos],val),pos+=lowbit(pos);
    }

    T query(int pos) {
        T res=0;
        while(pos) update(res,tr[pos]),pos-=lowbit(pos);
        return res;
    }

    T suffix(int pos) {
        return query(size)-query(pos-1);
    }

    Fenwick(int size):size(size) { tr.resize(size+1); }
};
Fenwick<> tr(N);

void solve(int l,int r,bool rev) {
    if(l==r) return;
    int mid=l+r>>1;
    solve(l,mid,rev),solve(mid+1,r,rev);
    for(int i=l,j=mid+1,idx=l;j<=r;) {
        while(i<=mid&&((p[i].first>p[j].first)^rev))
            tr.add(p[i].second,1),tmp[idx++]=p[i++];
        ans[p[j].second-1]+=tr.suffix(p[j].second+1);
        tmp[idx++]=p[j++];
        if(j>r) {
            for(int k=l;k<i;k++) tr.add(p[k].second,-1);
            while(i<=mid) tmp[idx++]=p[i++];
        }
    }
    for(int i=l;i<=r;i++) p[i]=tmp[i];
}

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>p[i].first,pos[p[i].first]=i;
    for(int i=1;i<=m;i++) {
        int in;
        cin>>in;
        p[pos[in]].second=i;
    }
    for(int i=1,j=m;i<=n;i++) if(!p[i].second) p[i].second=++j;

    for(int i=1;i<=n;i++) bak[i]=p[i];
    solve(1,n,0);
    for(int i=1;i<=n;i++) p[i]=bak[i];
    reverse(p+1,p+1+n);
    solve(1,n,1);

    for(int i=n;i>=0;i--) ans[i]+=ans[i+1];
    for(int i=0;i<m;i++) cout<<ans[i]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}