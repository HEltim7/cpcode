#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <map>
#include <cstring>
#include <array>
using namespace std;

#define endl '\n'
using LL=long long;
using ARR=array<int,4>;
const int N=1e5+10,M=N*70;
int arr[N];
map<int,pair<int,bool>> mp;

ARR unify(ARR l,ARR r) {
    ARR res;
    auto get=[](int x,int y) {
        return !x||!y?0:x+y;
    };
    res[0]=max({get(l[0],r[2]),get(l[1],r[0]),l[0],r[0]});
    res[1]=max({get(l[0],r[3]),get(l[1],r[1]),l[1],r[1]});
    res[2]=max({get(l[2],r[2]),get(l[3],r[0]),l[2],r[2]});
    res[3]=max({get(l[2],r[3]),get(l[3],r[1]),l[3],r[3]});
    return res;
}

void reverse(ARR &x) {
    swap(x[1],x[2]);
}

struct SegmentTree {
    struct Node {
        int l,r;
        ARR f;
    } tr[N*4];
    
    void pushup(int u) {
        tr[u].f=unify(tr[u<<1].f,tr[u<<1|1].f);
    }

    void modify(int u,int p,ARR val) {
        if(tr[u].l==tr[u].r) tr[u].f=val;
        else {
            int mid=tr[u].l+tr[u].r>>1;
            if(p<=mid) modify(u<<1,p,val);
            if(p>mid) modify(u<<1|1,p,val);
            pushup(u);
        }
    }

    ARR query(int u,int l,int r) {
        if(tr[u].l>=l&&tr[u].r<=r) return tr[u].f;
        int mid=tr[u].l+tr[u].r>>1;
        if(mid>=l&&mid<r) return unify(query(u<<1,l,r),query(u<<1|1,l,r));
        else if(mid>=l) return query(u<<1,l,r);
        return query(u<<1|1,l,r);
    }

    void build(int u,int l,int r) {
        tr[u]={l,r};
        if(l==r) tr[u].f[arr[l]&1?3:0]=1;
        else {
            int mid=l+r>>1;
            build(u<<1,l,mid);
            build(u<<1|1,mid+1,r);
            pushup(u);
        }
    }

} segtr;

struct MergeSplitSegmentTree {
    struct Node {
        int l,r;
        int cnt;
        ARR f;
    } tr[M];
    int idx;

    int new_node() {
        assert(idx<M);
        return ++idx;
    }

    void pushup(int u) {
        Node &p=tr[u],&l=tr[tr[u].l],&r=tr[tr[u].r];
        if(tr[u].l&&tr[u].r) p.cnt=l.cnt+r.cnt,p.f=unify(l.f,r.f);
        else if(tr[u].l) p.cnt=l.cnt,p.f=l.f;
        else if(tr[u].r) p.cnt=r.cnt,p.f=r.f;
        else assert(0);
    }

    void merge(int &u,int v) {
        if(!u||!v) u=u+v;
        else {
            merge(tr[u].l,tr[v].l);
            merge(tr[u].r,tr[v].r);
            pushup(u);
        }
    }

    void split(int u,int &v,int k) {
        if(!u) return;
        v=new_node();
        if(k<=tr[tr[u].l].cnt) swap(tr[u].r,tr[v].r);
        if(k<tr[tr[u].l].cnt) split(tr[u].l, tr[v].l, k);
        else if(k>tr[tr[u].l].cnt) split(tr[u].r, tr[v].r, k-tr[tr[u].l].cnt);
        pushup(u),pushup(v);
    }

    void try_split(int p) {
        auto it=prev(mp.upper_bound(p));
        int l=it->first;
        if(l==p) return;
        auto [u,type]=it->second;
        int v=0;
        int r=next(it)->first;
        split(u, v, type?r-p:p-l);
        if(type) swap(u,v);
        mp.erase(it);
        mp.insert({l,{u,type}});
        mp.insert({p,{v,type}});
        ARR tmp=tr[u].f;
        if(type) reverse(tmp);
        segtr.modify(1, l, tmp);
        tmp=tr[v].f;
        if(type) reverse(tmp);
        segtr.modify(1, p, tmp);
    }

    void modify(int &u,int l,int r,int p) {
        u=new_node();
        if(l==r) {
            tr[u].cnt=1;
            tr[u].f[p&1?3:0]=1;
            return;
        }
        int mid=l+r>>1;
        if(p<=mid) modify(tr[u].l, l, mid, p);
        else modify(tr[u].r, mid+1, r, p);
        pushup(u);
    }

    int kth(int u,int l,int r,int k) {
        if(l==r) return l;
        int mid=l+r>>1;
        if(k<=tr[tr[u].l].cnt) return kth(tr[u].l,l,mid,k);
        return kth(tr[u].r,mid+1,r,k-tr[tr[u].l].cnt);
    }
    
    ARR query(int u,int l,int r,int L,int R) {
        if(l>=L&&r<=R) return tr[u].f;
        int mid=l+r>>1;
        if(mid>=L&&mid<R) 
            return unify(query(tr[u].l,l,mid,L,R),query(tr[u].r,mid+1,r,L,R));
        else if(mid>=L) return query(tr[u].l,l,mid,L,R);
        return query(tr[u].r,mid+1,r,L,R);
    }

} tr;

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        int u=0;
        tr.modify(u, 1, n, arr[i]);
        mp.insert({i,{u,0}});
    }
    mp.insert({0,{0,0}});
    mp.insert({n+1,{0,0}});
    segtr.build(1, 1, n);
    while(m--) {
        int op,l,r;
        cin>>op>>l>>r;
        op--;
        if(op==0||op==1) {
            tr.try_split(l);
            tr.try_split(r+1);
            auto L=mp.lower_bound(l);
            auto R=next(L);
            int u=L->second.first;
            for(;R->first<=r;R=next(R)) {
                tr.merge(u,R->second.first);
                segtr.modify(1, R->first, {});
            }
            mp.erase(L,R);
            mp.insert({l,{u,op}});
            ARR tmp=tr.tr[u].f;
            if(op) reverse(tmp);
            segtr.modify(1, l, tmp);
        }
        else {
            auto get=[&](int l,int r) {
                auto it=prev(mp.upper_bound(l));
                auto [u,type]=it->second;
                int pre=it->first-1;
                int suf=next(it)->first;
                int cnt=tr.tr[u].cnt;
                int lcnt=l-pre;
                int rcnt=cnt-(suf-r)+1;
                if(type) lcnt=cnt-lcnt+1,rcnt=cnt-rcnt+1;
                int L=tr.kth(u, 1, n, lcnt);
                int R=tr.kth(u, 1, n, rcnt);
                if(L>R) swap(L,R);
                ARR res=tr.query(u, 1, n, L, R);
                if(type) reverse(res);
                return res;
            };

            auto lit=mp.upper_bound(l);
            auto rit=prev(mp.upper_bound(r));
            ARR res={};
            if(prev(lit)==rit) res=get(l,r);
            else {
                res=get(l,lit->first-1);
                if(lit!=rit) res=unify(res, segtr.query(1, lit->first, rit->first-1));
                res=unify(res, get(rit->first,r));
            }
            cout<<max({res[0],res[1],res[2],res[3]})<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}