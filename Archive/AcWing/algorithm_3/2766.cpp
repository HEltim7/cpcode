#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e6+10;
int cnt[N];
LL ans;
int h[N],e[N],ne[N],idx;

struct SAM {
    const static int A=26;
    const static char B='a';
    struct Endpos {
        int link,len;
        int next[A];
    };
    vector<Endpos> am;
    int last=0;

    int new_node() {
        am.push_back({});
        return am.size()-1;
    }

    void extend(char x) {
        int c=x-B;
        int p=last;
        int cur=last=new_node();
        cnt[cur]++;
        am[cur].len=am[p].len+1;
        while(p!=-1) {
            if(!am[p].next[c]) am[p].next[c]=cur;
            else {
                int q=am[p].next[c];
                if(am[p].len+1==am[q].len) am[cur].link=q;
                else {
                    int clone=new_node();
                    am[clone]=am[q];
                    am[clone].len=am[p].len+1; 
                    am[cur].link=am[q].link=clone;
                    for(;p!=-1&&am[p].next[c]==q;p=am[p].link) 
                        am[p].next[c]=clone;
                }
                break;
            }
            p=am[p].link;
        }
    }

    void build(string &s) { for(auto x:s) extend(x); }
    void clear() { am.clear(),am.push_back({-1}),last=0; }
    int size() { return am.size(); }
    SAM() { am.reserve(N),am.push_back({-1}); }
} sam;

void dfs(int u) {
    for(int i=h[u];~i;i=ne[i])
        dfs(e[i]),cnt[u]+=cnt[e[i]];
    if(cnt[u]>1) ans=max(ans,sam.am[u].len*1LL*cnt[u]);
}

void solve() {
    memset(h, -1, sizeof h);
    string in;
    cin>>in;
    sam.build(in);
    auto add=[](int a,int b){
        e[idx]=b,ne[idx]=h[a],h[a]=idx++;
    };
    for(int i=1;i<sam.am.size();i++) add(sam.am[i].link,i);
    dfs(0);
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}