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
    constexpr static int A=26;
    constexpr static char B='a';
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

    vector<int> toporder;
    void toposort() {
        auto &q=toporder;
        q.clear();
        q.reserve(size());
        vector<int> ind(size());
        for(int i=1;i<size();i++) ind[edp[i].link]++;
        for(int i=1;i<size();i++) if(!ind[i]) q.push_back(i);
        for(int i=0;i<q.size();i++) {
            int u=q[i];
            int p=edp[u].link;
            if(p&&!--ind[p]) q.push_back(p);
        }
    }

    void count(const string &s) {
        int u=0;
        for(auto x:s) {
            int c=x-B;
            u=edp[u].ch[c];
            edp[u].cnt++;
        }
        for(int u:toporder) {
            int p=edp[u].link;
            edp[p].cnt+=edp[u].cnt;
        }
    }

    int size() { return edp.size(); }
    void build(const string &s) { for(auto x:s) extend(x); }
    void clear() { edp.clear(),edp.push_back({-1}),last=0; }
    
    SuffixAutomaton(int sz=0) { edp.reserve(sz),clear(); }
    SuffixAutomaton(const string &s) { edp.reserve(s.size()*2),clear(),build(s); }
} sam;

void solve() {
    string t1,t2,s;
    cin>>t1>>t2>>s;
    sam.clear();
    sam.build(s);
    sam.toposort();
    sam.count(s);

    LL ans=0;
    const auto &edp=sam.edp;
    int u=0;
    for(int i=0;i<s.size();i++) {
        if(i) {
            int c=s[i]-sam.B;
            u=edp[u].ch[c];
            if(!u) {
                cout<<ans<<endl;
                return;
            }
        }
        
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}