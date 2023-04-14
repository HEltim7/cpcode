#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=5e5+10;

struct SuffixAutomaton {
    constexpr static int A=26;
    constexpr static char B='a';
    struct Endpos {
        int link,len;
        int ch[A];
        vector<int> adj;
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

    LL solve(string &s) {
        build(s);
        for(int u=0;auto x:s) u=edp[u].ch[x-B],edp[u].mark=1;
        for(int i=1;i<size();i++) edp[edp[i].link].adj.push_back(i);

        LL ans=0;
        auto dfs=[&](auto dfs,int u) -> int {
            int cnt=0;
            for(int v:edp[u].adj) {
                auto t=dfs(dfs,v);
                ans+=1LL*cnt*t*edp[u].len;
                cnt+=t;
            }
            if(edp[u].mark) ans+=1LL*cnt*edp[u].len,cnt++;
            return cnt;
        };

        dfs(dfs,0);
        return ans;
    }

    void build(string &s) { for(auto x:s) extend(x); }
    void clear() { edp.clear(),edp.push_back({-1}),last=0; }
    int size() { return edp.size(); }
    
    SuffixAutomaton() { edp.push_back({-1}); }
    SuffixAutomaton(int sz) { edp.reserve(sz),edp.push_back({-1}); }
} sam(N*2);

void solve() {
    string s;
    cin>>s;
    int n=s.size();
    LL ans=1LL*n*(n-1)*(n+1)/2;
    reverse(s.begin(), s.end());
    ans-=2*sam.solve(s);
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}