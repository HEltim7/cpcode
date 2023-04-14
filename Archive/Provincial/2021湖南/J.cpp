#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=5e7+10;

struct SegmentTree {
    #define lch (u<<1)
    #define rch (u<<1|1)
    constexpr static int MAX_SIZE=N;

    struct Node {
        int l,r;

    } tr[MAX_SIZE<<2];

    void pushup(int u) {

    }

    void pushdn(int u) {

    }

    void modify(int u,int l,int r,int val) {
        if(tr[u].l>=l&&tr[u].r<=r) {}
        else {
            pushdn(u);
            int mid=tr[u].l+tr[u].r>>1;
            if(mid>=l) modify(lch, l, r, val);
            if(mid<r) modify(rch, l, r, val);
            pushup(u);
        }
    }

    int query(int u,int l,int r) {
        if(tr[u].l>=l&&tr[u].r<=r) {}
        else {
            pushdn(u);
            int mid=tr[u].l+tr[u].r>>1;
            
            if(mid>=l) query(lch, l, r);
            if(mid<r) query(rch, l, r);
        }
    }

    void build(int u,int l,int r) {
        tr[u]={l,r};
        if(l==r) {}
        else {
            int mid=l+r>>1;
            build(lch, l, mid);
            build(rch, mid+1, r);
            pushup(u);
        }
    }

    #undef lch
    #undef rch
} sgt;

struct AhoCorasickAutomaton {
    constexpr static int A=26;
    constexpr static char B='a';
    struct Node {
        int link,cnt;
        int ch[A];
    };

    vector<Node> tr;
    int sz=0;

    int insert(string &s) {
        int root=0;
        for(auto x:s) {
            int c=x-B;
            if(!tr[root].ch[c]) 
                tr[root].ch[c]=new_node();
            root=tr[root].ch[c];
        }
        tr[root].cnt++;
        return root;
    }

    void build() {
        queue<int> q;
        for(int i=0;i<A;i++) 
            if(tr[0].ch[i]) {
                q.push(tr[0].ch[i]);

            }
        while(q.size()) {
            auto root=q.front();
            q.pop();
            for(int i=0;i<A;i++) {
                int &cur=tr[root].ch[i];
                int pre=tr[tr[root].link].ch[i];
                if(!cur) cur=pre;
                else {
                    // tr[cur].cnt+=tr[pre].cnt;
                    tr[cur].link=pre;
                    q.push(cur);
                }
            }
        }
    }

    int match() {

    }

    int size() { return tr.size(); }
    int new_node() { tr.push_back({});return ++sz; }
    void clear() { tr.clear();tr.resize(1);sz=0; }

    AhoCorasickAutomaton() { tr.resize(1); }
    AhoCorasickAutomaton(int sz) { tr.reserve(sz+1);tr.push_back({}); }
} acam;

void solve() {
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}