#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;

struct GeneralSuffixAutomaton {
    constexpr static int A=26;
    constexpr static char B='a';
    using Arr=array<int, A>;
    struct Endpos {
        int link,len;
        Arr ch;
    };
    vector<Endpos> edp;

    int new_edp() { edp.push_back({}); return edp.size()-1; }

    int split(int p,int c,int len) {
        int q=edp[p].ch[c];
        if(edp[q].len==len) return q;
        else {
            int clone=new_edp();
            edp[clone]=edp[q];
            edp[clone].len=len;
            edp[q].link=clone;
            for(;p!=-1&&edp[p].ch[c]==q;p=edp[p].link)
                edp[p].ch[c]=clone;
            return clone;
        }
    }

    void extend(int p,int c) {
        int cur=edp[p].ch[c];
        edp[cur].len=edp[p].len+1;
        for(;p!=-1&&(edp[p].ch[c]==cur||!edp[p].ch[c]);p=edp[p].link)
            edp[p].ch[c]=cur;
        if(p!=-1) edp[cur].link=split(p, c, edp[p].len+1);
    }

    void insert(string &s) {
        int u=0;
        vector<int> p;
        for(int i=0;i<s.size();i++) {
            int len=1;
            int c=s[i]-B;
            while(u&&s[i]>s[i-len]) {
                u=p.back();
                p.pop_back();
                len++;
            }
            while(len--) {
                p.push_back(u);
                if(!edp[u].ch[c]) edp[u].ch[c]=new_edp();
                u=edp[u].ch[c];
            }
        }
    }

    void build() {
        queue<int> q;
        q.push(0);
        while(q.size()) {
            int p=q.front();
            q.pop();
            for(int c=0;c<A;c++) if(edp[p].ch[c]) 
                extend(p, c),q.push(edp[p].ch[c]);
        }
    }

    LL count() {
        LL res=0;
        for(int i=1;i<size();i++) {
            res+=edp[i].len-edp[edp[i].link].len;
        }
        return res;
    }

    int size() { return edp.size(); }
    void clear() { edp.clear(),edp.push_back({-1}); }
    
    GeneralSuffixAutomaton(int sz=0) { edp.reserve(sz),clear(); }
} sam(N*2*sam.B);

void solve() {
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    sam.insert(s);
    sam.build();
    cout<<sam.count();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}