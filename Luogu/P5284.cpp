#include <queue>
#include <cmath>
#include <tuple>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using TIII=tuple<int,int,int>;
constexpr int N=4e5+10,M=20;

LL res[N];
int len[N],ind[N],na,nb;
int fa[N][M+1],dep[N]={0,1};
vector<int> adj[N],st[N];
string s;

struct SuffixAutomaton {
    constexpr static int A=26;
    constexpr static char B='a';
    struct Endpos {
        int link,len;
        int ch[A];
        vector<int> adj;
    };
    vector<Endpos> edp;
    int last=0;

    int new_node() {
        edp.push_back({});
        return edp.size()-1;
    }

    void extend(char x) {
        int c=x-B;
        int p=last;
        int cur=last=new_node();
        edp[cur].len=edp[p].len+1;
        while(p!=-1) {
            if(!edp[p].ch[c]) edp[p].ch[c]=cur;
            else {
                int q=edp[p].ch[c];
                if(edp[p].len+1==edp[q].len) edp[cur].link=q;
                else {
                    int clone=new_node();
                    edp[clone]=edp[q];
                    edp[clone].len=edp[p].len+1; 
                    edp[cur].link=edp[q].link=clone;
                    for(;p!=-1&&edp[p].ch[c]==q;p=edp[p].link) 
                        edp[p].ch[c]=clone;
                }
                break;
            }
            p=edp[p].link;
        }
    }

    void build(string &s) { 
        for(auto x:s) extend(x);
        for(int i=1;i<size();i++) edp[edp[i].link].adj.push_back(i);
    }

    void clear() { edp.clear(),edp.push_back({-1}),last=0; }
    int size() { return edp.size(); }
    
    SuffixAutomaton() { edp.push_back({-1}); }
    SuffixAutomaton(int sz) { edp.reserve(sz),edp.push_back({-1}); }
} sam(N);

const auto &edp=sam.edp;

LL bfs() {
    queue<int> q;
    for(int i=1;i<=na+nb;i++) for(int u:adj[i]) ind[u]++;
    for(int i=1;i<=na+nb;i++) if(!ind[i]) q.push(i);
    int cnt=0;
    LL ans=0;
    while(q.size()) {
        int u=q.front();
        q.pop();
        cnt++;
        for(int v:adj[u]) {
            res[v]=max(res[v],res[u]+(v<=na?len[v]:0));
            if(--ind[v]==0) q.push(v);
        }
        ans=max(ans,res[u]);
    }
    return cnt==na+nb?ans:-1;
}

void build_graph(int u,int b) {
    for(int v:st[u]) {
        if(b) adj[b].push_back(v);
        if(v>na) b=v;
    }
    for(int v:edp[u].adj) build_graph(v, b);
}

void get_st(vector<TIII> &seg) {
    sort(seg.begin(),seg.end());
    for(int i=0,u=0,idx=0;i<s.size();i++) {
        int c=s[i]-'a';
        u=edp[u].ch[c];
        for(int v=u;idx<seg.size();idx++) {
            auto [r,l,id]=seg[idx];
            if(r!=i) break;
            int len=r-l+1;
            for(int i=M;i>=0;i--) if(edp[fa[v][i]].len>=len) v=fa[v][i];
            st[v].push_back(id);
        }
    }
}

void get_lca(int u) {
    for(int v:edp[u].adj) {
        dep[v]=dep[u]+1;
        fa[v][0]=u;
        for(int i=1;i<=M;i++)
            fa[v][i]=fa[fa[v][i-1]][i-1];
        get_lca(v);
    }
}

void init() {
    memset(ind, 0, sizeof(int)*(na+nb+1));
    for(int i=0;i<=na+nb;i++) adj[i].clear();
    for(int i=0;i<sam.size();i++) st[i].clear();
    for(int i=0;i<sam.size();i++) memset(fa[i], 0, sizeof(fa[i]));
}

void solve() {
    cin>>s;
    reverse(s.begin(),s.end());
    sam.clear();
    sam.build(s);
    int slen=s.size();

    vector<TIII> seg;
    cin>>na;
    for(int i=1;i<=na;i++) {
        int l,r;
        cin>>l>>r;
        l=slen-l,r=slen-r;
        swap(l,r);
        seg.emplace_back(r,l,i);
        res[i]=len[i]=r-l+1;
    }

    cin>>nb;
    for(int i=1;i<=nb;i++) {
        int l,r;
        cin>>l>>r;
        l=slen-l,r=slen-r;
        swap(l,r);
        seg.emplace_back(r,l,i+na);
        res[i+na]=0;
        len[i+na]=r-l+1;
    }

    init();
    get_lca(0);
    get_st(seg);
    for(int i=0;i<sam.size();i++)
        sort(st[i].begin(),st[i].end(),[](int a,int b) {
            if(len[a]==len[b]) return a>=b;
            return len[a]<len[b];
        });

    int m;
    cin>>m;
    for(int i=1;i<=m;i++) {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b+na);
    }

    build_graph(0, 0);
    cout<<bfs()<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}