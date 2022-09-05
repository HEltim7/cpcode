#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <array>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
constexpr int N=2e4+10;
int arr[N],root[N];

struct PersistentSegmentTree {

    #define lch tr[u].ch[0]
    #define rch tr[u].ch[1]
    constexpr static int MAX_SIZE=N*20*2;

    struct Node {
        int ch[2];
        int sum,lmax,rmax;
        int id;
    } tr[MAX_SIZE];
    int idx;

    int new_node() {
        assert(idx<MAX_SIZE);
        return ++idx;
    }

    void update(Node &p,const Node &l,const Node &r) {
        p.rmax=max(r.rmax,r.sum+l.rmax);
        p.lmax=max(l.lmax,l.sum+r.lmax);
        p.sum=l.sum+r.sum;
    }

    void pushup(int u) {
        update(tr[u],tr[lch],tr[rch]);
    }

    void modify(int &u,int v,int l,int r,int p,int id) {
        if(!u||tr[u].id!=id) {
            u=new_node();
            tr[u]=tr[v];
            tr[u].id=id;
        }
        if(l==r) tr[u].sum=-1,tr[u].lmax=tr[u].rmax=0;
        else {
            int mid=l+r>>1;
            if(p<=mid) modify(lch, tr[v].ch[0], l, mid, p, id);
            else modify(rch, tr[v].ch[1], mid+1, r, p, id);
            pushup(u);
        }
    }

    Node query(int u,int l,int r,int L,int R) {
        if(l>=L&&r<=R) return tr[u];
        int mid=l+r>>1;
        if(mid>=L&&mid<R) {
            Node res{};
            update(res,query(lch, l, mid, L, R),query(rch, mid+1, r, L, R));
            return res;
        }
        else if(mid>=L) return query(lch, l, mid, L, R);
        return query(rch, mid+1, r, L, R);
    }

    void build(int &u,int l,int r) {
        u=new_node();
        tr[u].sum=tr[u].lmax=tr[u].rmax=1,tr[u].id=-1;
        if(l!=r) {
            int mid=l+r>>1;
            build(lch,l,mid);
            build(rch,mid+1,r);
            pushup(u);
        }
    }

    #undef lch
    #undef rch

} sgt;

void solve() {
    int n,maxv=-1;
    cin>>n;
    vector<PII> num;
    vector<int> val;
    for(int i=0;i<n;i++) cin>>arr[i],num.emplace_back(arr[i],i);
    sort(num.begin(),num.end());
    for(int i=0;i<n;i++) 
        if(i==0||num[i].first>num[i-1].first)
            val.push_back(num[i].first),arr[num[i].second]=++maxv;
        else arr[num[i].second]=maxv;
    
    sgt.build(root[0], 0, n-1);
    for(int i=0,j=0;i<=maxv;i++) {
        while(arr[num[j].second]==i)
            sgt.modify(root[i+1], root[i], 0, n-1, num[j++].second, i);
    }
    
    int Q,last=0;
    array<int,4> q;
    cin>>Q;
    while(Q--) {
        for(int i=0;i<4;i++) cin>>q[i],q[i]=(q[i]+last)%n;
        sort(q.begin(),q.end());

        auto check=[&](int x) {
            int sum=0;
            sum+=sgt.query(root[x], 0, n-1, q[1], q[2]).sum;
            sum+=sgt.query(root[x], 0, n-1, q[0], q[1]-1).rmax;
            sum+=sgt.query(root[x], 0, n-1, q[2]+1, q[3]).lmax;
            return sum>=0;
        };

        int l=0,r=maxv;
        while(l<r) {
            int mid=l+r+1>>1;
            if(check(mid)) l=mid;
            else r=mid-1;
        }
        cout<<val[last=l]<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}