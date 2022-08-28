#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...)
#endif

#define endl '\n'
using LL=long long;
constexpr int N=1e6+10;

struct SuffixAutomaton {
    constexpr static int A=26;
    constexpr static char B='a';
    struct Endpos {
        int link,len;
        int ch[A];
        bool mark;
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

    void build(string &s) { for(auto x:s) extend(x); }
    void clear() { edp.clear(),edp.push_back({-1}),last=0; }
    int size() { return edp.size(); }
    
    SuffixAutomaton() { edp.push_back({-1}); }
    SuffixAutomaton(int sz) { edp.reserve(sz),edp.push_back({-1}); }
} sam(N),cur(N);

LL count(string &str) {
    cur.clear();
    cur.build(str);
    int u=0,v=0,len=0,tot=0;
    LL res=0;
    auto &s=sam.edp,&t=cur.edp;
    for(char x:str) {
        int c=x-SuffixAutomaton::B;
        tot++;
        while(u&&!s[u].ch[c]) u=s[u].link,len=s[u].len;
        if(s[u].ch[c]) u=s[u].ch[c],len++;

        v=t[v].ch[c];
        int p=v;
        while(p&&!t[p].mark) t[p].mark=1,p=t[p].link;
        res+=tot-max(len,t[p].len);
    }
    return res;
}

void solve() {
    // freopen64("data/in.txt","r",stdin);
    // freopen64("data/out.txt","w",stdout);
    int q;
    string s;
    cin>>s>>q;
    int R=s.size();
    sam.build(s);
    while(q--) {
        int l,r;
        cin>>s>>l>>r;
        if(l!=1||r!=R) assert(0);
        else cout<<count(s)<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}