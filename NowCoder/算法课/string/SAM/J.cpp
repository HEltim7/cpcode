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
constexpr int N=1e5+10;

struct SuffixAutomaton {
    constexpr static int A=26;
    constexpr static char B='a';
    struct Endpos {
        int link,len;
        int ch[A];
        int maxlen,cnt;
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

    void count() {
        toposort();
        for(int u:toporder) {
            int p=edp[u].link;
            edp[u].maxlen=max(edp[u].maxlen,edp[u].len);
            edp[p].maxlen=max(edp[p].maxlen,edp[u].len);
            edp[u].cnt=edp[u].maxlen-edp[u].len;
        }
    }

    int get_cnt(string &s) {
        int u=0;
        for(auto x:s) {
            int c=x-B;
            if(!edp[u].ch[c]) return 0;
            u=edp[u].ch[c];
        }
        return edp[u].cnt;
    }

    int size() { return edp.size(); }
    void build(const string &s) { for(auto x:s) extend(x); }
    void clear() { edp.clear(),edp.push_back({-1}),last=0; }
    
    SuffixAutomaton(int sz=0) { edp.reserve(sz),clear(); }
    SuffixAutomaton(const string &s) { edp.reserve(s.size()*2),clear(),build(s); }
} sam(N*2);

void solve() {
    int n;
    string s,t;
    while(cin>>t) {
        sam.clear();
        sam.build(t);
        sam.count();
        cin>>n;
        int xsum=0;
        for(int i=1;i<=n;i++) {
            cin>>s;
            xsum^=sam.get_cnt(s);
            debug(sam.get_cnt(s));
        }
        cout<<(xsum?"Alice":"Bob")<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}