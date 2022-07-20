#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
LL ans;

struct SAM {
    const static int A=26;
    const static char start='a';
    struct State {
        int len,link=-1,cnt;
        int next[A];
        vector<int> adj;
    };
    vector<State> dfa;
    int last=0;
    
    void init() {
        dfa.push_back({});
        last=0;
    }

    int new_node() {
        dfa.push_back({});
        return dfa.size()-1;
    }

    void extend(char x) {
        int c=x-start;
        int cur=new_node();
        int p=last;
        dfa[cur].cnt=1;
        dfa[cur].len=dfa[p].len+1;
        while(p!=-1&&!dfa[p].next[c]) {
            dfa[p].next[c]=cur;
            p=dfa[p].link;
        }
        if(p==-1) dfa[cur].link=0;
        else {
            int q=dfa[p].next[c];
            if(dfa[p].len+1==dfa[q].len) dfa[cur].link=q;
            else {
                int clone=new_node();
                dfa[clone]=dfa[q];
                dfa[clone].len=dfa[p].len+1;
                while(p!=-1&&dfa[p].next[c]==q) {
                    dfa[p].next[c]=clone;
                    p=dfa[p].link;
                }
                dfa[q].link=dfa[cur].link=clone;
            }
        }
        last=cur;
    }

    void build_edge() {
        for(int i=1;i<size();i++)
            dfa[dfa[i].link].adj.push_back(i);
    }

    int dfs(int u) {
        for(auto v:dfa[u].adj) dfa[u].cnt+=dfs(v);
        if(dfa[u].cnt>1) ans=max(ans,1LL*dfa[u].cnt*dfa[u].len);
        return dfa[u].cnt;
    }
    
    int size() { return dfa.size(); }
    void clear() { dfa.clear();init(); }
    SAM() { init(); }
} sam;

void solve() {
    string s;
    cin>>s;
    for(auto x:s) sam.extend(x);
    sam.build_edge();
    sam.dfs(0);
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}