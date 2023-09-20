#include <algorithm>
#include <cassert>
#include <bitset>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

#define endl '\n'
using LL = long long;
constexpr int N=1e5+10;
constexpr int SQ=320;
using BS=bitset<N>;

struct SAM {
    constexpr static int A=26;
    constexpr static char B='a';
    struct Endpos {
        int link,len,cnt;
        int ch[A];
        bool bg;
        vector<int> pos;
    };
    vector<Endpos> edp;
    int last=0;

    int new_node() {
        edp.emplace_back();
        return edp.size()-1;
    }

    void extend(char x) {
        int c=x-B;
        int p=last;
        int cur=last=new_node();
        edp[cur].len=edp[p].len+1;
        for(;p!=-1&&edp[p].ch[c];p=edp[p].link) edp[p].ch[c]=cur;
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

    vector<int> top;
    void topsort() {
        auto &q=top;
        q.clear();
        q.reserve(size());
        vector<int> ind(size());
        for(int i=1;i<size();i++) ind[edp[i].link]++;
        for(int i=1;i<size();i++) if(!ind[i]) q.emplace_back(i);
        for(int i=0;i<q.size();i++) {
            int u=q[i];
            int p=edp[u].link;
            if(p&&!--ind[p]) q.emplace_back(p);
        }
    }

    void build(string &s) {
        for(char x:s) extend(x);
        for(int u=0,i=0;i<s.size();i++) {
            int c=s[i]-B;
            u=edp[u].ch[c];
            edp[u].pos.emplace_back(i);
        }
        topsort();
    }

    int size() { return edp.size(); }
    void clear() { edp.clear(),edp.emplace_back(-1),last=0; }
    SAM(int sz=0) { edp.reserve(sz),clear(); }
};

void solve() {
    string s,t;
    cin>>s>>t;
    SAM sams(N*2),samt(N*2);
    reverse(t.begin(),t.end());
    sams.build(s),samt.build(t);

    int q;
    cin>>q;
    
    for(int i=1;i<=q;i++) {

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}