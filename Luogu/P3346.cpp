#include <vector>
#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10,M=N*40;

struct GeneralSuffixAutomaton {
    constexpr static int A=10;
    constexpr static char B='0';
    using Arr=array<int, A>;
    struct Endpos {
        int link,len;
        Arr ch;
    };
    vector<Endpos> edp;
    vector<Arr> tr;

    void init() {
        edp.clear(),edp.push_back({-1});
        tr.clear(),tr.push_back({});
    }

    int new_node() { tr.push_back({}); return tr.size()-1; }
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

    void extend(int &p,int &t,int c,int len) {
        int last;
        if(tr[t][c]) last=edp[p].ch[c];
        else {
            tr[t][c]=new_node();
            if(edp[p].ch[c]) last=split(p, c, len);
            else {
                int cur=last=new_edp();
                edp[cur].len=len;
                for(;p!=-1&&!edp[p].ch[c];p=edp[p].link)
                    edp[p].ch[c]=cur;
                if(p!=-1) edp[cur].link=split(p, c, edp[p].len+1);
            }
        }
        t=tr[t][c];
        p=last;
    }

    void insert(vector<int> &s) {
        for(int p=0,t=0,i=0;i<s.size();i++) extend(p, t, s[i], i+1);
    }

    LL solve() {
        LL res=0;
        for(int i=1;i<size();i++) 
            res+=edp[i].len-edp[edp[i].link].len;
        return res;
    }

    int size() { return edp.size(); }
    void clear() { init(); }
    
    GeneralSuffixAutomaton() { init(); }
    GeneralSuffixAutomaton(int sz) { edp.reserve(sz),tr.reserve(sz),init(); }
} sam(M);

int color[N];
vector<int> adj[N],field;

void dfs(int u,int fa) {
    bool empty=1;
    field.push_back(color[u]);
    for(int v:adj[u]) if(v!=fa) dfs(v,u),empty=0;
    if(empty) sam.insert(field);
    field.pop_back();
}

void solve() {
    int n,c;
    cin>>n>>c;
    for(int i=1;i<=n;i++) cin>>color[i];
    for(int i=2;i<=n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    field.reserve(N);
    for(int u=1;u<=n;u++) if(adj[u].size()==1) dfs(u,-1);
    cout<<sam.solve()<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}