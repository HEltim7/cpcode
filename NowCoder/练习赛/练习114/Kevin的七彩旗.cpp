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
    struct Endpos {
        int link,len,cnt;
        map<int,int> ch;
    };
    vector<Endpos> edp;
    int last=0;

    int new_node() {
        edp.push_back({});
        return edp.size()-1;
    }

    void extend(int c) {
        int p=last;
        int cur=last=new_node();
        edp[cur].len=edp[p].len+1;
        for(;p!=-1&&edp[p].ch.find(c)==edp[p].ch.end();p=edp[p].link) edp[p].ch[c]=cur;
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

    int solve(int m) {
        int ans=1;
        int u=0;
        for(int i=1;i<=m;i++) {
            if(edp[u].ch.find(i)==edp[u].ch.end()) {
                if(u==0) return -1;
                else u=0,ans++;
                if(edp[u].ch.find(i)==edp[u].ch.end()) return -1;
            }
            u=edp[u].ch[i];
        }
        return ans;
    }

    int size() { return edp.size(); }
    void build(const string &s) { for(auto x:s) extend(x); }
    void clear() { edp.clear(),edp.push_back({-1}),last=0; }
    
    SuffixAutomaton(int sz=0) { edp.reserve(sz),clear(); }
    SuffixAutomaton(const string &s) { edp.reserve(s.size()*2),clear(),build(s); }
};

void solve() {
    int n,m;
    cin>>n>>m;
    SuffixAutomaton sam;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        sam.extend(in);
    }
    cout<<sam.solve(m)<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}