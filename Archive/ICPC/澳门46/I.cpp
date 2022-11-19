#include <array>
#include <queue>
#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e6+10,M=N*2;
vector<int> adj[M];
vector<pair<int,int>> pos[M];
vector<tuple<int,int,int>> res;
string str[N];
int fa[M];

int findfa(int x) {
    if(fa[x]==x) return x;
    return fa[x]=findfa(fa[x]);
}

struct GeneralSuffixAutomaton {
    constexpr static int A=26;
    constexpr static char B='a';
    using Arr=array<int, A>;
    struct Endpos {
        int link,len;
        Arr ch;
    };
    vector<Endpos> edp;

    void init() { edp.clear(),edp.push_back({-1}); }
    int new_edp() { edp.push_back({}); return edp.size()-1; }

    int split(int p,int c,int len) {
        int q=edp[p].ch[c];
        if(edp[q].len==len) return q;
        else {
            int clone=new_edp();
            edp[clone]=edp[q];
            edp[clone].len=len;
            edp[q].link=clone;
            for(;p!=-1&&edp[p].ch[c]==q;p=edp[p].link)
                edp[p].ch[c]=clone;
            return clone;
        }
    }

    void extend(int p,int c) {
        int cur=edp[p].ch[c];
        edp[cur].len=edp[p].len+1;
        for(;p!=-1&&(edp[p].ch[c]==cur||!edp[p].ch[c]);p=edp[p].link)
            edp[p].ch[c]=cur;
        if(p!=-1) edp[cur].link=split(p, c, edp[p].len+1);
    }

    void insert(string &s) {
        int t=0,c=0;
        for(auto x:s) {
            c=x-B;
            if(!edp[t].ch[c]) edp[t].ch[c]=new_edp();
            t=edp[t].ch[c];
        }
    }

    void build() {
        queue<int> q;
        q.push(0);
        while(q.size()) {
            int p=q.front();
            q.pop();
            for(int c=0;c<A;c++) if(edp[p].ch[c]) 
                extend(p, c),q.push(edp[p].ch[c]);
        }
    }

    int size() { return edp.size(); }
    void clear() { init(); }

    void dfs(int u) {
        for(int v:adj[u]) dfs(v);
        int t=0;
        for(int v:adj[u]) {
            int cur=pos[v].front().second;
            if(t==0) t=cur;
            else if(t!=cur) res.emplace_back(edp[u].len,t,cur);
        }
        
        if(pos[u].empty()) pos[u].emplace_back(edp[u].len,t);
        else {
            for(auto [len,id]:pos[u]) {
                if(t==0) t=id;
                else if(id!=t) res.emplace_back(len,t,id);
            }
        }
    }

    int solve(int n) {
        for(int i=1;i<=n;i++) {
            auto &s=str[i];
            int u=0,len=0;
            for(auto x:s) {
                u=edp[u].ch[x-B];
                pos[u].emplace_back(++len,i);
            }
        }
        for(int i=1;i<size();i++)
            adj[edp[i].link].push_back(i);
        res.reserve(M);
        dfs(0);

        int ans=0;
        for(int i=1;i<=n;i++) fa[i]=i;
        sort(res.begin(),res.end(),greater<>());
        for(auto [len,u,v]:res) {
            if(findfa(u)!=findfa(v)) {
                fa[fa[u]]=fa[v];
                ans+=len;
            }
        }
        return ans;
    }
    
    GeneralSuffixAutomaton() { init(); }
    GeneralSuffixAutomaton(int sz) { edp.reserve(sz),init(); }
} sam(M);

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>str[i],sam.insert(str[i]);
    sam.build();
    cout<<sam.solve(n);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}