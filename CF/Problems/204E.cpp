#include <vector>
#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10,M=20;
int fa[N][M+1],dep[N]={1};
int id[N],ed[N],val[N],idx;
vector<int> adj[N];

void get_lca(int u) {
    for(int v:adj[u]) {
        dep[v]=dep[u]+1;
        fa[v][0]=u;
        for(int i=1;i<=M;i++)
            fa[v][i]=fa[fa[v][i-1]][i-1];
        get_lca(v);
    }
}

int lca(int a,int b) {
    if(dep[a]<dep[b]) swap(a,b);
    for(int k=M;~k;k--)
        if(dep[fa[a][k]]>=dep[b])
            a=fa[a][k];
    if(a==b) return a;
    for(int k=M;~k;k--)
        if(fa[a][k]!=fa[b][k])
            a=fa[a][k],b=fa[b][k];
    return fa[a][0];
}

void relable(int u) {
    id[u]=++idx;
    for(int v:adj[u]) relable(v);
    ed[u]=idx;
}

void sum(int u) {
    for(int v:adj[u]) sum(v),val[u]+=val[v];
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
    vector<Arr> tr;

    void init() {
        edp.clear(),edp.push_back({-1});
        tr.clear(),tr.push_back({});
    }

    int new_tr() { tr.push_back({}); return tr.size()-1; }
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

    void extend(int &p,int &t,char x,int len) {
        int c=x-B;
        int last;
        if(tr[t][c]) last=edp[p].ch[c];
        else {
            tr[t][c]=new_tr();
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

    void extend(string &s) {
        for(int p=0,t=0,i=0;i<s.size();i++) extend(p, t, s[i], i+1);
    }

    void get_adj() {
        for(int i=1;i<size();i++) adj[edp[i].link].push_back(i);
    }

    void mark(string &s) {
        int u=0;
        vector<int> arr;
        for(auto x:s) u=edp[u].ch[x-B],arr.push_back(u),val[u]++;
        sort(arr.begin(),arr.end(),[](int a,int b){
            return id[a]<id[b];
        });
        for(int i=1;i<arr.size();i++) val[lca(arr[i-1], arr[i])]--;
    }

    int size() { return edp.size(); }
    void clear() { init(); }
    
    GeneralSuffixAutomaton() { init(); }
    GeneralSuffixAutomaton(int sz) { edp.reserve(sz),tr.reserve(sz),init(); }
} sam(N);

void solve() {
    int n,k;
    cin>>n>>k;
    vector<string> s(n);
    for(int i=0;i<n;i++) {
        cin>>s[i];
        sam.extend(s[i]);
    }
    sam.get_adj();
    relable(0);
    for(int i=0;i<n;i++) sam.mark(s[i]);
    sum(0);
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}