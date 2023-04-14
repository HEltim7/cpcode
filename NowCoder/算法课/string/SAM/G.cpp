#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
string s[N];
int uid[N],len[N];

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
} sam[N];

void solve() {
    int n;
    cin>>n;
    int idx=0,minlen=N;
    for(int i=1;i<=n;i++) {
        cin>>s[i];
        sam[i].build(s[i]);
        if(s[i].size()<minlen) idx=i,minlen=s[i].size();
    }

    int ans=0;
    for(auto x:s[idx]) {
        int c=x-SuffixAutomaton::B;
        int res=N;
        for(int i=1;i<=n;i++) {
            auto &edp=sam[i].edp;
            int &u=uid[i];
            int &l=len[i];
            while(u&&!edp[u].ch[c]) u=edp[u].link,l=edp[u].len;
            if(edp[u].ch[c]) u=edp[u].ch[c],l++;
            res=min(res,l);
        }
        ans=max(ans,res);
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}