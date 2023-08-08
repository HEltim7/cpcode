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

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

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

    int size() { return edp.size(); }
    void build(const string &s) { for(auto x:s) extend(x); }
    void clear() { edp.clear(),edp.push_back({-1}),last=0; }
    
    SuffixAutomaton(int sz=0) { edp.reserve(sz),clear(); }
    SuffixAutomaton(const string &s) { edp.reserve(s.size()*2),clear(),build(s); }
} sam;

void solve() {
    string s;
    cin>>s;
    sam.clear();
    sam.build(s);

    const auto &edp=sam.edp;
    constexpr int A=sam.A;
    constexpr int B=sam.B;

    int n=s.size();
    auto dp=vector(n*2,-1);
    auto ri=vector(A,-1);
    auto pre=vector(n+1,array<int,A>());
    auto ne=vector(n+1,array<int,A>());

    for(int i=0;i<n;i++) {
        int c=s[i]-B;
        ri[c]=i;
        if(i) pre[i]=pre[i-1];
        pre[i][c]=i;
    }
    for(int i=0;i<A;i++) ne[n][i]=n+1;
    for(int i=n-1;i>=0;i--) {
        int c=s[i]-B;
        ne[i]=ne[i+1];
        ne[i][c]=i;
    }

    auto toposort=[&]() {
        vector<int> q;
        q.reserve(sam.size());
        vector<int> ind(sam.size());
        for(int i=1;i<sam.size();i++) ind[edp[i].link]++;
        for(int i=1;i<sam.size();i++) if(!ind[i]) q.emplace_back(i);
        for(int i=0;i<q.size();i++) {
            int u=q[i];
            int p=edp[u].link;
            if(p&&!--ind[p]) q.emplace_back(p);
        }

        for(int u:q) {
            for(int c=0;c<A;c++) {
                int v=edp[u].ch[c];
                if(!v) dp[u]=max(dp[u],ri[c]-1);
                else if(dp[v]-1>=0) dp[u]=max(dp[u],pre[dp[v]-1][c]);
            }
        }
    };

    toposort();
    string ans;
    for(int u=0,idx=0;idx<n;) {
        bool ok=false;
        for(int c=0;c<A;c++) {
            if(ne[idx][c]>n) continue;
            int v=edp[u].ch[c];
            if(!v) {
                ans.push_back(char(c+B));
                cout<<ans<<endl;
                return;
            }
            if(ne[idx][c]<=dp[v]) {
                ans.push_back(char(c+B));
                idx=ne[idx][c]+1;
                u=v;
                ok=true;
                break;
            }
        }
        if(!ok) break;
    }
    cout<<-1<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}