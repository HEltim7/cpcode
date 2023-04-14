#include <array>
#include <queue>
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
constexpr int N=7e5+10;
vector<int> adj[N];
int id[N],ed[N],idx;

void dfs(int u) {
    id[u]=++idx;
    for(int v:adj[u]) dfs(v);
    ed[u]=idx;
}

struct SegmentTree {
    #define lch (u<<1)
    #define rch (u<<1|1)
    constexpr static int MAXSIZE=N;

    struct Node {
        int l,r;
        int sum;
        bool del=false;
    } tr[MAXSIZE<<2];

    void pushup(int u) {
        tr[u].sum=tr[lch].sum+tr[rch].sum;
    }

    void pushdn(int u) {
        if(tr[u].del) {
            tr[lch].sum=0;
            tr[lch].del=1;
            tr[rch].sum=0;
            tr[rch].del=1;
            tr[u].del=0;
        }
    }

    void modify(int u,int l,int r,int val,bool del) {
        if(tr[u].l>=l&&tr[u].r<=r) {
            tr[u].sum+=val;
            if(del) {
                tr[u].sum=0;
                tr[u].del=1;
            }
        }
        else {
            pushdn(u);
            int mid=tr[u].l+tr[u].r>>1;
            if(mid>=l) modify(lch, l, r, val, del);
            if(mid<r) modify(rch, l, r, val, del);
            pushup(u);
        }
    }

    int query(int u,int l,int r) {
        if(tr[u].l>=l&&tr[u].r<=r) { return tr[u].sum; }
        else {
            pushdn(u);
            int mid=tr[u].l+tr[u].r>>1;
            int res=0;
            if(mid>=l) res+=query(lch, l, r);
            if(mid<r) res+=query(rch, l, r);
            return res;
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

        for(int i=1;i<size();i++) adj[edp[i].link].push_back(i);
    }

    int find(const string &s) {
        int u=0;
        for(char x:s) {
            int c=x-B;
            u=edp[u].ch[c];
        }
        return u;
    }

    void active(const string &s) {
        int u=find(s);
        sgt.modify(1, id[u], id[u], 1, 0);
    }

    void del(const string &s) {
        int u=find(s);
        sgt.modify(1, id[u], ed[u], 0, 1);
    }

    int query(const string &s) {
        int u=find(s);
        return sgt.query(1, id[u], ed[u]);
    }

    int size() { return edp.size(); }
    void clear() { init(); }
    
    GeneralSuffixAutomaton() { init(); }
    GeneralSuffixAutomaton(int sz) { edp.reserve(sz),init(); }
} sam(N);

void solve() {
    int n;
    cin>>n;
    using PIS=pair<char,string>;
    vector<PIS> q(n);
    for(auto &[op,s]:q) {
        cin>>op>>s;
        if(op=='I') sam.insert(s);
    }
    sam.build();
    dfs(0);
    sgt.build(1, 1, idx);
    for(const auto &[op,s]:q) {
        if(op=='I') sam.active(s);
        else if(op=='D') sam.del(s);
        else cout<<sam.query(s)<<endl;
    }
}

/*
离线，将所有I插入广义sam，预处理dfs序，所有字符串尾贡献设为0。
遍历所有询问，若当前指令为I，找到该串在parent树上的位置，贡献设为1，单点修改。
若当前指令为Q，parent子树区间求和。
若当前指令为D，parent子树区间推平为0。
*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}