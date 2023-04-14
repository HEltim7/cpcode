#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

struct SegmentTree {
    #define lch (u<<1)
    #define rch (u<<1|1)
    constexpr static int MAXSIZE=2.5e5+10;

    struct Node {
        int l,r;
        int maxx,laz;
    } tr[MAXSIZE<<2];

    void pushup(int u) {
        tr[u].maxx=max(tr[lch].maxx,tr[rch].maxx);
    }

    void pushdn(int u) {
        tr[lch].maxx=max(tr[lch].maxx,tr[u].laz);
        tr[lch].laz=max(tr[lch].laz,tr[u].laz);
        tr[rch].maxx=max(tr[rch].maxx,tr[u].laz);
        tr[rch].laz=max(tr[rch].laz,tr[u].laz);
    }

    void modify(int u,int l,int r,int val) {
        if(tr[u].l>=l&&tr[u].r<=r) {
            tr[u].maxx=max(tr[u].maxx,val);
            tr[u].laz=max(tr[u].laz,val);
        }
        else {
            pushdn(u);
            int mid=tr[u].l+tr[u].r>>1;
            if(mid>=l) modify(lch, l, r, val);
            if(mid<r) modify(rch, l, r, val);
            pushup(u);
        }
    }

    int query(int u,int l,int r) {
        if(tr[u].l>=l&&tr[u].r<=r) { return tr[u].maxx; }
        else {
            pushdn(u);
            int mid=tr[u].l+tr[u].r>>1;
            int res=0;
            if(mid>=l) res=max(res,query(lch, l, r));
            if(mid<r) res=max(res,query(rch, l, r));
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

struct SuffixAutomaton {
    constexpr static int A=26;
    constexpr static char B='a';
    struct Endpos {
        int link,len;
        int ch[A];
        int cnt;
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
        for(;p!=-1&&!edp[p].ch[c];p=edp[p].link) edp[p].ch[c]=cur;
        if(p!=-1) {
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
        }
    }

    vector<int> toporder() {
        vector<int> ind(size()),q;
        q.reserve(size());
        for(int i=1;i<size();i++) ind[edp[i].link]++;
        for(int i=1;i<size();i++) if(!ind[i]) q.push_back(i);
        for(int i=0;i<q.size();i++) {
            int u=q[i];
            int p=edp[u].link;
            if(p&&!--ind[p]) q.push_back(p);
        }
        return q;
    }

    void count(const string &s) {
        int u=0;
        for(auto x:s) {
            int c=x-B;
            u=edp[u].ch[c];
            edp[u].cnt++;
        }
        auto &&v=toporder();
        for(int u:v) {
            int p=edp[u].link;
            edp[p].cnt+=edp[u].cnt;
            sgt.modify(1, edp[p].len+1, edp[u].len, edp[u].cnt);
        }
    }

    int size() { return edp.size(); }
    void build(const string &s) { for(auto x:s) extend(x); }
    void clear() { edp.clear(),edp.push_back({-1}),last=0; }
    
    SuffixAutomaton(int sz=0) { edp.reserve(sz),clear(); }
    SuffixAutomaton(const string &s) { edp.reserve(s.size()*2),clear(),build(s); }
};

void solve() {
    string s;
    cin>>s;
    SuffixAutomaton sam(s);
    sgt.build(1, 1, s.size());
    sam.count(s);
    for(int i=1;i<=s.size();i++) cout<<sgt.query(1, i, i)<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}