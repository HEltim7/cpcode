#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e6+10;

struct SuffixAutomaton {
    constexpr static int A=26;
    constexpr static char B='a';
    struct Endpos {
        int link,len;
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
        while(p!=-1) {
            if(edp[p].ch.find(c)==edp[p].ch.end()) edp[p].ch[c]=cur;
            else {
                int q=edp[p].ch[c];
                if(edp[p].len+1==edp[q].len) edp[cur].link=q;
                else {
                    int clone=new_node();
                    edp[clone]=edp[q];
                    edp[clone].len=edp[p].len+1; 
                    edp[cur].link=edp[q].link=clone;
                    for(;p!=-1&&edp[p].ch.find(c)!=edp[p].ch.end()&&edp[p].ch[c]==q;p=edp[p].link) 
                        edp[p].ch[c]=clone;
                }
                break;
            }
            p=edp[p].link;
        }
    }
    
    int solve(vector<int> &s) {
        int u=0,len=0,ans=0;
        for(auto x:s) {
            while(u&&edp[u].ch.find(x)==edp[u].ch.end()) u=edp[u].link,len=edp[u].len;
            if(edp[u].ch.find(x)!=edp[u].ch.end()) u=edp[u].ch[x],len++;
            ans=max(ans,len);
        }
        return ans;
    }

    void build(vector<int> &s) { for(auto x:s) extend(x); }
    void clear() { edp.clear(),edp.push_back({-1}),last=0; }
    int size() { return edp.size(); }
    
    SuffixAutomaton() { edp.push_back({-1}); }
    SuffixAutomaton(int sz) { edp.reserve(sz),edp.push_back({-1}); }
} sam(N*2);

void solve() {
    sam.clear();
    int n,m;
    LL p,x,a,b,c;
    cin>>n>>m>>p>>x>>a>>b>>c;
    vector<int> s;
    for(int i=1;i<=n;i++) {
        x=(a*x%p*x%p+b*x%p+c)%p;
        s.push_back(x);
    }
    sam.build(s);
    s.clear();
    for(int i=1;i<=m;i++) {
        x=(a*x%p*x%p+b*x%p+c)%p;
        s.push_back(x);
    }
    cout<<sam.solve(s)<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}