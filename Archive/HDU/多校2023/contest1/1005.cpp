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

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
string str[N];
vector<pair<int,int>> qry[N];
vector<int> color[N];
bool ans[N],mark[N];

struct AhoCorasickAutomaton {
    constexpr static int A=26;
    constexpr static char B='a';
    struct Node {
        int link,cnt;
        int ch[A];
    };

    vector<Node> tr;
    int sz=0;

    int insert(const string &s,int idx) {
        int root=0;
        for(auto x:s) {
            int c=x-B;
            if(!tr[root].ch[c]) 
                tr[root].ch[c]=new_node();
            root=tr[root].ch[c];
        }
        tr[root].cnt++;
        color[root].push_back(idx);
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

    void match(int idx) {
        string cur=str[idx]+str[idx];
        vector<int> path;
        int u=0;
        for(char x:cur) {
            int c=x-B;
            u=tr[u].ch[c];
            if(u) path.push_back(u);
        }
        sort(path.begin(),path.end());
        path.erase(unique(path.begin(),path.end()),path.end());
        for(int x:path) for(int y:color[x]) mark[y]=1;

        for(int i=0;i<qry[idx].size();i++) {
            int v=qry[idx][i].first;
            int id=qry[idx][i].second;
            if(mark[v]) ans[id]=1;
        }
        for(int x:path) for(int y:color[x]) mark[y]=0;
    }

    int size() { return tr.size(); }
    int new_node() { tr.push_back({});return ++sz; }
    void clear() { tr.clear();tr.resize(1);sz=0; }

    AhoCorasickAutomaton() { tr.resize(1); }
    AhoCorasickAutomaton(int sz) { tr.reserve(sz+1);tr.push_back({}); }
} acam(N);

void solve() {
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++) {
        cin>>str[i];
        acam.insert(str[i],i);
    }
    acam.build();

    int q;
    cin>>q;
    for(int i=1;i<=q;i++) {
        int x,y;
        cin>>x>>y;
        qry[x].emplace_back(y,i);
    }
    for(int i=1;i<=n;i++) {
        if(qry[i].size()) acam.match(i);
    }

    for(int i=1;i<=q;i++) cout<<(ans[i]?"Yes":"No")<<endl;

    for(int i=0;i<acam.size();i++) color[i].clear();
    for(int i=1;i<=q;i++) ans[i]=0;
    for(int i=1;i<=n;i++) qry[i].clear();
    acam.clear();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}