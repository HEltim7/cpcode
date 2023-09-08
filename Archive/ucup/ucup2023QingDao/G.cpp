#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10,M=N*__lg(N)*2;

namespace sgt {
    #define lch tr[u].lc
    #define rch tr[u].rc

    struct Node {
        int minp=N,maxp=0;
        int lc=0,rc=0;
        int cnt=0;
        int add=0;
        LL rev=0;
    };
    vector<Node> tr(M);
    int idx;

    int new_node() {
        assert(++idx<M);
        tr[idx]={};
        return idx;
    }

    void pushup(int u) {
        tr[u].maxp=max(tr[lch].maxp,tr[rch].maxp);
        tr[u].minp=min(tr[lch].minp,tr[rch].minp);
        tr[u].rev=tr[lch].rev+tr[rch].rev;
        tr[u].cnt=tr[lch].cnt+tr[rch].cnt;
    }

    void upd(int u,int add) {
        if(u) {
            tr[u].rev+=1LL*tr[u].cnt*add;
            tr[u].add+=add;
        }
    }

    void pushdn(int u) {
        if(tr[u].add) {
            upd(lch, tr[u].add);
            upd(rch, tr[u].add);
        }
        tr[u].add=0;
    }

    pair<int,int> split(int u,int k) {
        if(tr[u].minp>=k) return {0,u};
        if(tr[u].maxp<k) return {u,0};
        pushdn(u);
        int v=new_node();
        auto [a,b]=split(lch, k);
        auto [c,d]=split(rch, k);
        tr[u].lc=a,tr[u].rc=c;
        tr[v].lc=b,tr[v].rc=d;
        upd(b, -tr[c].cnt);
        pushup(u),pushup(v);
        return {u,v};
    }

    int query(int u,int l,int r,int x,int y) {
        if(!u||l>y||r<x) return {};
        if(l>=x&&r<=y) return tr[u].cnt;
        pushdn(u);
        int mid=(l+r)/2;
        return query(lch, l, mid, x, y)+query(rch, mid+1, r, x, y);
    }

    void build(int &u,int l,int r,int x,int rev,int p) {
        if(!u) u=new_node();
        if(l==r) {
            tr[u].cnt=1;
            tr[u].rev=rev;
            tr[u].minp=tr[u].maxp=p;
            return;
        }
        int mid=(l+r)/2;
        pushdn(u);
        if(x<=mid) build(lch, l, mid, x, rev, p);
        else build(rch, mid+1, r, x, rev, p);
        pushup(u);
    }

    #undef lch
    #undef rch
}

template<class Info=int,typename I=int> struct SegmentSet {
    struct Seg {
        I l;
        mutable I r;
        mutable Info v;
        bool operator<(const Seg &x) const {
            return l<x.l;
        }
        friend ostream &operator<<(ostream &os,const Seg &x) {
            return os<<"["<<x.l<<"->"<<x.r<<"]";
        }
        Seg(I l,I r={},Info v={}): l(l),r(r),v(v) {}
    };
    set<Seg> st;
    using Iter=typename set<Seg>::iterator;
    
    Iter first_inter(I l,I r) {
        Iter it=--st.upper_bound({l});
        if(it->r<l) it++;
        return it;
    }

    Iter last_inter(I l,I r) {
        return --st.upper_bound({r});
    }

    Iter split(I p) {
        Iter it=st.lower_bound({p});
        if(it->l==p) return it;
        if((--it)->r<p) return st.end();
        auto [l,r,v]=*it;
        st.erase(it);
        st.emplace(l,p-1,v);
        return st.emplace(p,r,v).first;
    }

    Iter merge(Iter it) {
        auto work=[&](Iter lit,Iter rit) {
            if(lit->r+1==rit->l&&lit->v==rit->v) {
                lit->r=rit->r;
                st.erase(rit);
                return true;
            }
            return false;
        };
        auto lit=prev(it),rit=next(it);
        if(work(lit,it)) return work(lit,rit),lit;
        return work(it,rit),it;
    }

    Iter erase(I l,I r) {
        split(l),split(r+1);
        auto lit=first_inter(l,r);
        auto rit=++last_inter(l,r);
        return st.erase(lit,rit);
    }

    Iter insert(I l,I r,Info v) {
        erase(l,r);
        return merge(st.emplace(l,r,v).first);
    }

    I first_uncovered() {
        auto it=st.begin();
        if(it->r+2<next(it)->l) return it->r+2;
        else it=next(it);
        for(;;) {
            if(it->r+1<next(it)->l) return it->r+1;
            else it=next(it);
        }
    }

    SegmentSet(I l,I r) {
        st.emplace(l-2,l-2);
        st.emplace(r+2,r+2);
    }
};

void solve() {
    sgt::idx=0;
    int n;
    cin>>n;
    vector<int> arr(n+1);
    vector<pair<int,int>> num;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        num.emplace_back(arr[i],i);
    }
    sort(num.begin(),num.end());
    for(int i=1;i<=n;i++) {
        arr[i]=lower_bound(
            num.begin(),num.end(),pair{arr[i],i}
        )-num.begin()+1;
    }

    SegmentSet<> seg(1,n);
    seg.insert(1, n, 1);
    for(int i=1,rt=0;i<=n;i++) {
        int rev=sgt::query(rt, 0, n+1, arr[i]+1,n);
        sgt::build(rt, 0, n+1, arr[i], rev, i);
    }

    multiset<LL> res;
    res.emplace(sgt::tr[1].rev);
    for(int i=1;i<=n;i++) {
        cout<<*res.rbegin()<<" \n"[i==n];
        LL p;
        cin>>p;
        p^=*res.rbegin();
        auto [l,r,rt]=*seg.first_inter(p, p);
        res.erase(res.find(sgt::tr[rt].rev));
        auto [u,_]=sgt::split(rt, p);
        auto [__,v]=sgt::split(_, p+1);
        res.insert(sgt::tr[u].rev);
        res.insert(sgt::tr[v].rev);
        seg.erase(l, r);
        if(l<=p-1) seg.insert(l, p-1, u);
        if(p+1<=r) seg.insert(p+1, r, v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}