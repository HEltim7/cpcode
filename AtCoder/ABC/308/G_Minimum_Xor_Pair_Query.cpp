#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int H=4;

template<typename I> struct BinaryTrie {
    // constexpr static int H=sizeof(I)*8-2;
    struct Node {
        int ch[2];
        int cnt;
        I base;
        I maxx;
    };
    vector<Node> tr;

    int new_node(int b) {
        tr.push_back({});
        int idx=tr.size()-1;
        if(b>=0) tr[idx].base=1<<b;
        return tr.size()-1;
    }

    void pushup(int u) {
        int lc=tr[u].ch[0];
        int rc=tr[u].ch[1];
        I res=tr[u].cnt>=2?tr[u].base:0;
        I lres=(lc&&tr[lc].cnt>=2)?tr[lc].base:0;
        I rres=(rc&&tr[rc].cnt>=2)?tr[rc].base:0;
        tr[u].maxx=res+max(lres,rres);
        debug(tr[u].cnt,tr[u].maxx);
    }

    void insert(int v) {
        vector<int> path(1,0);
        for(int i=H,u=0;i>=0;i--) {
            bool x=v>>i&1;
            if(!tr[u].ch[x]) tr[u].ch[x]=new_node(i);
            u=tr[u].ch[x];
            tr[u].cnt++;
            path.emplace_back(u);
        }
        reverse(path.begin(),path.end());
        debug(path);
        for(int u:path) pushup(u);
    }

    void erase(int v) {
        vector<int> path(1,0);
        for(int i=H,u=0;i>=0;i--) {
            bool x=v>>i&1;
            u=tr[u].ch[x];
            tr[u].cnt--;
            path.emplace_back(u);
        }
        reverse(path.begin(),path.end());
        for(int u:path) pushup(u);
    }

    I xor_max(int v) {
        I res{};
        for(int i=H,u=0;i>=0;i--) {
            bool x=v>>i&1^1;
            if(tr[tr[u].ch[x]].cnt) {
                res|=1<<i;
                u=tr[u].ch[x];
            }
            else u=tr[u].ch[x^1];
        }
        return res;
    }

    void clear() {
        tr.clear();
        new_node(-1);
    }

    explicit BinaryTrie(int size=0) {
        tr.reserve(size*(H+1));
        clear();
    }
};

BinaryTrie<int> tr;

void solve() {
    int q;
    cin>>q;
    while(q--) {
        int op,x;
        cin>>op;
        if(op!=3) cin>>x;
        if(op==1) {
            tr.insert(x);
        }
        else if(op==2) tr.erase(x);
        else {
            int ans=(1<<H)-1;
            int res=tr.tr[0].maxx;
            debug(ans,res);
            ans-=res;
            cout<<ans<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}