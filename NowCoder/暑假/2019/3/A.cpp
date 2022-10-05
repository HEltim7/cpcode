#include <array>
#include <vector>
#include <random>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;

template<int size,int mux,class T=mt19937> struct HashSet {
    using ULL=unsigned long long;
    using Arr=array<ULL,size>;
    array<Arr,mux> val,xorv;
    T gen;

    void init() {
        for(int i=0;i<mux;i++) {
            for(int j=0;j<size;j++)
                val[i][j]=gen();
        }
    }

    bool equal(int x,int y) {
        x--,y--;
        for(int i=0;i<mux;i++)
            if(xorv[i][x]!=xorv[i][y])
                return 0;
        return 1;
    }

    void modify(int x,int y) {
        x--,y--;
        for(int i=0;i<mux;i++) {
            xorv[i][x]^=val[i][y];
            xorv[i][y]^=val[i][x];
        }
    }

    void reset(int n) {
        for(int i=0;i<mux;i++)
            for(int j=0;j<n;j++)
                xorv[i][j]=0;
    }

    HashSet(T x): gen(x) { init(); }
};
HashSet<N, 10, mt19937_64> hashset(mt19937_64(random_device{}()));

struct SegmentTree {
    struct Node {
        int l,r;
        bool flip,laze;
    };
    vector<Node> tr;

    void modify(int u,int l,int r) {
        if(tr[u].l>=l&&tr[u].r<=r) tr[u].flip^=1,tr[u].laze^=1;
        else {
            int mid=l+r>>1;
            if(mid>=l) modify(u<<1, l, mid);
            if(mid<r) modify(u<<1|1, mid+1, r);
        }
    }
    
} sgt;

void solve() {
    int n,m;
    cin>>n>>m;
    hashset.reset(n);
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        hashset.modify(u, v);
    }
    int q;
    cin>>q;
    while(q--) {
        int op,u,v;
        cin>>op>>u>>v;
        if(op==1) hashset.modify(u, v);
        else cout<<(hashset.equal(u, v)?"1":"0");
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}