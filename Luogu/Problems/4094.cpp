#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int root[N];

struct MergeSplitSegmentTree {

    #define lch tr[u].ch[0]
    #define rch tr[u].ch[1]
    constexpr static int MAX_SIZE=N*20*2;
    
    struct Node {
        int ch[2];
    } tr[MAX_SIZE];
    int idx;

    int new_node() {
        assert(idx<MAX_SIZE);
        return ++idx;
    }

    int merge(int x,int y) {
        if(!x||!y) return x|y;
        else {
            int u=new_node();
            lch=merge(tr[x].ch[0],tr[y].ch[0]);
            rch=merge(tr[x].ch[1],tr[y].ch[1]);
            return u;
        }
    }

    void build(int &u,int l,int r,int p) {
        u=new_node();
        if(l!=r) {
            int mid=l+r>>1;
            if(p<=mid) build(lch,l,mid,p);
            else build(rch,mid+1,r,p);
        }
    }

    #undef lch
    #undef rch

} sgt;

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

    void merge(int u) {
        for(int v:edp[u].adj) merge(v),root[u]=sgt.merge(root[u], root[v]);
    }

    void build_with_sgt(string &s) {
        build(s);
        for(int i=1;i<size();i++) edp[edp[i].link].adj.push_back(i);
        for(int i=0,u=0;i<s.size();i++) {
            int c=s[i]-B;
            u=edp[u].ch[c];
            sgt.build(root[u], 0, s.size()-1, i);
        }
        merge(0);
    }

    void build(string &s) { for(auto x:s) extend(x); }
    void clear() { edp.clear(),edp.push_back({-1}),last=0; }
    int size() { return edp.size(); }
    
    SuffixAutomaton() { edp.push_back({-1}); }
    SuffixAutomaton(int sz) { edp.reserve(sz),edp.push_back({-1}); }
} sam;

void solve() {
    int n,m;
    string s;
    cin>>n>>m>>s;
    sam.build_with_sgt(s);
    while(m--) {
        int a,b,c,d;
        
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}