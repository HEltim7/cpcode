#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

#define endl '\n'
using LL=long long;

const int N=5e5+10;
bool mark[N*2];
int cnt[N*2],ind[N*2];

struct SuffixAutomaton {
    const static int A=26;
    const static char B='a';
    struct Endpos {
        int link,len;
        LL cnt;
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

    void bfs() {
        queue<int> q;
        for(int i=1;i<size();i++) ind[edp[i].link]++;
        for(int i=1;i<size();i++) if(!ind[i]) q.push(i);
        while(q.size()) {
            int u=q.front();
            q.pop();
            cnt[edp[u].link]+=cnt[u];
            if(edp[u].link&&!--ind[edp[u].link]) q.push(edp[u].link);
        }
    }

    int dfs(int u) {
        if(mark[u]) return edp[u].cnt;
        mark[u]=1;
        if(u) edp[u].cnt+=cnt[u];
        for(int i=0;i<A;i++) if(edp[u].ch[i]) edp[u].cnt+=dfs(edp[u].ch[i]);
        return edp[u].cnt;
    }

    void solve(int u,int k,string &s) {
        if(u) k-=cnt[u];
        if(k<=0) return;
        for(int i=0;i<A;i++)
            if(edp[u].ch[i]) {
                if(edp[edp[u].ch[i]].cnt>=k) {
                    s.push_back(B+i);
                    return solve(edp[u].ch[i],k,s);
                }
                else k-=edp[edp[u].ch[i]].cnt;
            }
    }

    void solve(string &s,int k,bool type) {
        build(s);
        if(type) {
            for(int i=0,u=0;i<s.size();i++) u=edp[u].ch[s[i]-B],cnt[u]++;
            bfs();
        }
        else for(int i=0;i<size();i++) cnt[i]=1;
        dfs(0);
        if(edp[0].cnt<k) cout<<-1;
        else {
            string ans;
            solve(0,k,ans);
            cout<<ans;
        }
    }

    void build(string &s) { for(auto x:s) extend(x); }
    void clear() { edp.clear(),edp.push_back({-1}),last=0; }
    int size() { return edp.size(); }
    
    SuffixAutomaton() { edp.push_back({-1}); }
    SuffixAutomaton(int sz) { edp.reserve(sz),edp.push_back({-1}); }
} sam(N*2);

void solve() {
    string s;
    bool type;
    int k;
    cin>>s>>type>>k;
    sam.solve(s,k,type);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}