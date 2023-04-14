#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=6e5+10;
constexpr int K=__lg(10000000)+1;
int root[N];

struct PersistentTrie {

    constexpr static int MAX_SIZE=N*30;
    constexpr static int ALPHABET=2;
    
    struct Node {
        int ch[ALPHABET];
        int id;
    } tr[MAX_SIZE];
    int idx;

    int new_node() {
        assert(idx<MAX_SIZE);
        return ++idx;
    }

    template<typename T> void insert(T &&s,int u,int v) {
        int id=u;
        root[u]=new_node();
        u=root[u],v=root[v];
        tr[u]=tr[v];
        tr[u].id=id;
        for(auto x:s) {
            tr[u].ch[x]=new_node();
            tr[tr[u].ch[x]]=tr[tr[v].ch[x]];
            tr[tr[u].ch[x]].id=id;
            u=tr[u].ch[x];
            v=tr[v].ch[x];
        }
    }

    template<typename T> int query(T &&s,int u, int id) {
        int res=0;
        u=root[u];
        for(auto x:s) {
            if(tr[u].ch[!x]&&tr[tr[u].ch[!x]].id>=id) u=tr[u].ch[!x],res=res<<1|1;
            else u=tr[u].ch[x],res=res<<1;
        }
        return res;
    }

} trie;

void solve() {
    auto get=[](int x) {
        vector<int> res;
        while(x) res.push_back(x&1),x>>=1;
        while(res.size()<K) res.push_back(0);
        reverse(res.begin(),res.end());
        return res;
    };

    int n,m,sum=0;
    cin>>n>>m;
    trie.insert(get(0), 0, 0);
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        sum^=in;
        trie.insert(get(sum), i, i-1);
    }
    while(m--) {
        char op;
        cin>>op;
        if(op=='A') {
            int x;
            cin>>x;
            sum^=x;
            trie.insert(get(sum), n+1, n);
            n++;
        }
        else {
            int l,r,x;
            cin>>l>>r>>x;
            cout<<trie.query(get(sum^x), r-1, l-1)<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}