#pragma GCC optimize("O2")
#include <bitset>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
using BS=bitset<31>;
constexpr int N=2e5+10;
int arr[N],pre[N];

struct Trie {
    constexpr static int A=2,B=0;
    struct Node {
        int ch[A];
        int cnt;
    };
    vector<Node> tr;

    int new_node() { tr.push_back({}); return tr.size()-1; }

    int extend(int u,int x) {
        if(!tr[u].ch[x-B]) tr[u].ch[x-B]=new_node();
        tr[tr[u].ch[x-B]].cnt++;
        return tr[u].ch[x-B];
    }

    template<typename T> void erase(const T &s,int idx,int u) {
        if(idx<s.size()) {
            int x=s[idx];
            int v=tr[u].ch[x];
            if(!--tr[v].cnt) tr[u].ch[x]=0;
            else erase(s, idx+1, v);
        }
    }

    template<typename T> void insert(const T &s) {
        int u=0;
        for(auto x:s) u=extend(u, x);
    }

    template<typename T> int query(const T &s,int u,int idx,int &r) {
        int res=0;
        if(idx<s.size()) {
            int x=s[idx]-B;
            if(tr[u].ch[x^1]) {
                res=query(s,tr[u].ch[x^1],idx+1,r);
                res|=r;
            }
            else {
                res=query(s,tr[u].ch[x],idx+1,r);
            }
            r<<=1;
        }
        return res;
    }

    void clear() { tr.clear(); new_node(); }
    Trie() { clear(); }
    Trie(int size) { tr.reserve(size); clear(); }
} trie(N);

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arr[i];
    int ans=0;

    auto get=[](int x) {
        BS b(x);
        vector<int> cur;
        for(int i=0;i<b.size();i++) cur.push_back(b[i]);
        reverse(cur.begin(),cur.end());
        return cur;
    };

    trie.insert(get(0));
    for(int i=1;i<=n;i++) {
        pre[i]=pre[i-1]^arr[i];
        if(i>m) trie.erase(get(pre[i-m-1]), 0, 0);
        auto &&cur=get(pre[i]);
        int r=1;
        ans=max(ans,trie.query(cur, 0, 0, r));
        trie.insert(cur);
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}