#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2.5e6+10;

struct LinkCutTree {
    
    #define lch tr[u].ch[0]
    #define rch tr[u].ch[1]
    #define wch(u) (tr[tr[u].p].ch[1]==u)
    constexpr static int MAX_SIZE=N;

    struct Node {
        int ch[2],p;
        int val,laze;
    } tr[MAX_SIZE];
    int stk[MAX_SIZE];

    bool is_root(int u) {
        return tr[tr[u].p].ch[0]!=u&&tr[tr[u].p].ch[1]!=u;
    }

    void pushdn(int u) {
        if(lch) tr[lch].val+=tr[u].laze,tr[lch].laze+=tr[u].laze;
        if(rch) tr[rch].val+=tr[u].laze,tr[rch].laze+=tr[u].laze;
        tr[u].laze=0;
    }

    void rotate(int x) {
        int y=tr[x].p,z=tr[y].p,k=wch(x);
        if(!is_root(y)) tr[z].ch[wch(y)]=x;
        tr[y].ch[k]=tr[x].ch[!k],tr[tr[y].ch[k]].p=y;
        tr[x].ch[!k]=y,tr[y].p=x,tr[x].p=z;
    }

    void splay(int u) {
        int top=0,fa=u;
        stk[++top]=fa;
        while(!is_root(fa)) stk[++top]=fa=tr[fa].p;
        while(top) pushdn(stk[top--]);
        for(;!is_root(u);rotate(u))
            if(!is_root(fa=tr[u].p)) rotate(wch(u)==wch(fa)?fa:u);
    }

    void access(int u) {
        int t=u;
        for(int v=0;u;v=u,u=tr[u].p)
            splay(u),rch=v;
        splay(t);
    }

    void insert(int p,int q,int clone) {
        p++,q++,clone++;
        access(q);
        splay(p);
        tr[p].ch[1]=clone;
        tr[q].p=clone;
        tr[clone].ch[1]=q;
        tr[clone].p=p;
        tr[clone].val=tr[q].val;
    }

    void append(int p,int cur) {
        p++,cur++;
        tr[cur].p=p;
        access(cur);
        tr[cur].val=tr[cur].laze=1;
    }
    
    int query(int u) {
        u++;
        access(u);
        return tr[u].val;
    }

    #undef lch
    #undef rch
    #undef wch

} lct;

struct SuffixAutomaton {
    constexpr static int A=2;
    constexpr static char B='A';
    struct Endpos {
        int link,len;
        int ch[A];
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
            if(edp[p].len+1==edp[q].len) edp[cur].link=q,lct.append(q, cur);
            else {
                int clone=new_node();
                edp[clone]=edp[q];
                edp[clone].len=edp[p].len+1; 
                lct.insert(edp[q].link, q, clone);
                lct.append(clone, cur);
                edp[cur].link=edp[q].link=clone;
                for(;p!=-1&&edp[p].ch[c]==q;p=edp[p].link) 
                    edp[p].ch[c]=clone;
            }
        }
        else lct.append(0, cur);
    }

    int query(string &s) {
        int u=0;
        for(auto x:s)
            if(!edp[u].ch[x-B]) return 0;
            else u=edp[u].ch[x-B];
        return lct.query(u);
    }

    void build(string &s) { for(auto x:s) extend(x); }
    void clear() { edp.clear(),edp.push_back({-1}),last=0; }
    int size() { return edp.size(); }
    
    SuffixAutomaton() { edp.push_back({-1}); }
    SuffixAutomaton(int sz) { edp.reserve(sz),edp.push_back({-1}); }
} sam(N);

void decode(string &s,int mask) {
    for(int i=0;i<s.size();i++) {
        mask=(mask*131+i)%s.length();
        swap(s[i], s[mask]);
    }
}

void solve() {
    int Q,mask=0;
    string s;
    cin>>Q>>s;
    sam.build(s);
    while(Q--) {
        string op,str;
        cin>>op>>str;
        decode(str, mask);
        if(op=="ADD") sam.build(str);
        else {
            int res=sam.query(str);
            cout<<res<<endl;
            mask^=res;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}