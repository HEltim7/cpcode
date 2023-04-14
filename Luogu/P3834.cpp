#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int root[N],arr[N];

struct PersistentSegmentTree {

    #define lch tr[u].ch[0]
    #define rch tr[u].ch[1]
    constexpr static int MAX_SIZE=N*20*2;

    struct Node {
        int ch[2];
        int cnt;
    } tr[MAX_SIZE];
    int idx;

    int new_node() {
        assert(idx<MAX_SIZE);
        return ++idx;
    }

    void pushup(int u) {
        tr[u].cnt=tr[lch].cnt+tr[rch].cnt;
    }

    void modify(int &u,int v,int l,int r,int p) {
        u=new_node();
        tr[u]=tr[v];
        if(l==r) tr[u].cnt++;
        else {
            int mid=l+r>>1;
            if(p<=mid) modify(lch, tr[v].ch[0], l, mid, p);
            else modify(rch, tr[v].ch[1], mid+1, r, p);
            pushup(u);
        }
    }

    int kth(int u,int v,int l,int r,int k) {
        if(l==r) return l;
        int mid=l+r>>1;
        int lcnt=tr[lch].cnt-tr[tr[v].ch[0]].cnt;
        if(lcnt>=k) return kth(lch, tr[v].ch[0], l, mid, k);
        return kth(rch, tr[v].ch[1], mid+1, r, k-lcnt);
    }

    void build(int &u,int l,int r) {
        u=new_node();
        tr[u]={l,r};
        if(l!=r) {
            int mid=l+r>>1;
            build(lch,l,mid);
            build(rch,mid+1,r);
        }
    }

    #undef lch
    #undef rch

} sgt;

void solve() {
    int n,q;
    cin>>n>>q;
    
    vector<int> num;
    for(int i=1;i<=n;i++) cin>>arr[i],num.push_back(arr[i]);
    n=num.size();
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    for(int i=1;i<=n;i++) 
        arr[i]=lower_bound(num.begin(),num.end(),arr[i])-num.begin()+1;
    
    sgt.build(root[0], 1, n);
    for(int i=1;i<=n;i++) sgt.modify(root[i], root[i-1], 1, n, arr[i]);
    while(q--) {
        int l,r,k;
        cin>>l>>r>>k;
        cout<<num[sgt.kth(root[r], root[l-1], 1, n, k)-1]<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}