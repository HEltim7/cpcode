#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=5e4+10,M=12;
int arr[N][M],id[N];

struct Trie {
    constexpr static int A=M,B=0;
    struct Node {
        int ch[A];
        int cnt;
        int res;
    };
    vector<Node> tr;

    int new_node() { tr.push_back({}); return tr.size()-1; }

    int extend(int u,int x) {
        if(!tr[u].ch[x-B]) tr[u].ch[x-B]=new_node();
        tr[tr[u].ch[x-B]].cnt++;
        return tr[u].ch[x-B];
    }

    template<typename T> void insert(const T &s) {
        int u=0;
        for(auto x:s) u=extend(u, x);
    }

    void update(vector<int> &v) {
        int u=0;
        for(int i=0;i<v.size();i++) {
            int cur=tr[u].ch[v[i]-B];
            if(cur) u=cur,tr[u].res=max(tr[u].res,i+1);
            else break;
        }
    }

    void pushdn(int u) {
        for(int i=0;i<A;i++) {
            int cur=tr[u].ch[i];
            if(cur) tr[cur].res=max(tr[cur].res,tr[u].res),pushdn(cur);
        }
    }

    void clear() { tr.clear(); new_node(); }
    Trie() { clear(); }
    Trie(int size) { tr.reserve(size); clear(); }
} trie;

void solve() {
    int n,m;
    cin>>n>>m;
    trie.clear();
    for(int i=1;i<=n;i++) {
        int u=0;
        for(int j=1;j<=m;j++) {
            cin>>arr[i][j];
            u=trie.extend(u, arr[i][j]);
        }
        id[i]=u;
    }

    for(int i=1;i<=n;i++) {
        vector<int> v(m);
        for(int j=1;j<=m;j++) v[arr[i][j]-1]=j;
        trie.update(v);
    }
    trie.pushdn(0);
    for(int i=1;i<=n;i++) cout<<trie.tr[id[i]].res<<" \n"[i==n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}