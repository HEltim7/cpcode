#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
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

struct SuffixAutomaton {
    constexpr static int A=2;
    constexpr static char B='(';
    struct Endpos {
        int link,len,cnt;
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

    bool count(const string &s) {
        int u=0;
        for(char x:s) {
            int c=x-B;
            if(!edp[u].ch[c]) return false;
            u=edp[u].ch[c];
        }
        return true;
    }

    int size() { return edp.size(); }
    void build(const string &s) { for(auto x:s) extend(x); }
    void clear() { edp.clear(),edp.push_back({-1}),last=0; }
    
    SuffixAutomaton(int sz=0) { edp.reserve(sz),clear(); }
    SuffixAutomaton(const string &s) { edp.reserve(s.size()*2),clear(),build(s); }
} sam;

void solve() {
    string s;
    cin>>s;
    int n=s.size();
    string x,y;
    for(int i=1;i<=n;i++) x.push_back('(');
    for(int i=1;i<=n;i++) x.push_back(')');
    for(int i=1;i<=n;i++) y+="()";
    sam.clear();
    sam.build(x);
    if(!sam.count(s)) {
        cout<<"YES"<<endl;
        cout<<x<<endl;
        return;
    }
    sam.clear();
    sam.build(y);
    if(!sam.count(s)) {
        cout<<"YES"<<endl;
        cout<<y<<endl;
        return;
    }
    cout<<"NO"<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}