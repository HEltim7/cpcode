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
constexpr int N=2e6+10;
int ind[N],cnt[N];

struct SuffixAutomaton {
    constexpr static int A=26;
    constexpr static char B='a';
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

    LL solve(string &s) {
        queue<int> q;
        int cur=0;
        for(auto x:s) {
            cur=edp[cur].ch[x-B];
            cnt[cur]++;
        }
        for(int i=1;i<size();i++) ind[edp[i].link]++;
        for(int i=1;i<size();i++) if(!ind[i]) q.push(i);

        debug(q);
        while(q.size()) {
            int u=q.front();
            q.pop();
            debug(u,cnt[u]);
            cnt[edp[u].link]+=cnt[u];
            if(u&&!--ind[edp[u].link]) q.push(edp[u].link);
        }

        LL ans=0;
        for(int i=1;i<size();i++) {
            int l=edp[edp[i].link].len+1;
            int r=edp[i].len;
            debug(i,l,r,cnt[i]);
            for(int j=l;j<=min(r,cnt[i]);j++) {
                if(cnt[i]%j==0) ans+=cnt[i];
            }
        }
        return ans;
    }

    void build(string &s) { for(auto x:s) extend(x); }
    void clear() { edp.clear(),edp.push_back({-1}),last=0; }
    int size() { return edp.size(); }
    
    SuffixAutomaton() { edp.push_back({-1}); }
    SuffixAutomaton(int sz) { edp.reserve(sz),edp.push_back({-1}); }
} sam(N*2);

void solve() {
    int n;
    string s;
    cin>>n>>s;
    sam.build(s);

    cout<<sam.solve(s);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}