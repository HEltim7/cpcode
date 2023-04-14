#include <array>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e6+10;

struct GeneralSuffixAutomaton {
    constexpr static int A=26;
    constexpr static char B='a';
    using Arr=array<int, A>;
    struct Endpos {
        int link,len,cnt;
        Arr ch;
        bool mark;
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
        int t=0,c=0;
        for(auto x:s) {
            c=x-B;
            if(!edp[t].ch[c]) edp[t].ch[c]=new_edp();
            t=edp[t].ch[c];
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

    void markup(const string &s) {
        vector<int> q;
        int u=0;
        for(auto x:s) {
            int c=x-B;
            u=edp[u].ch[c];
            q.push_back(u);
            edp[u].mark=1;
        }
        for(int i=0;i<q.size();i++) {
            int u=q[i],p=edp[u].link;
            edp[u].cnt++;
            if(p&&!edp[p].mark) q.push_back(p),edp[p].mark=1;
        }
        for(int u:q) edp[u].mark=0;
    }

    LL count() {
        LL ans=0;
        for(int i=1;i<size();i++)
            if(edp[i].cnt==2) 
                ans+=edp[i].len-edp[edp[i].link].len;
        return ans;
    }

    int size() { return edp.size(); }
    void clear() { edp.clear(),edp.push_back({-1}); }
    
    GeneralSuffixAutomaton(int sz=0) { edp.reserve(sz),clear(); }
} sam;

void solve() {
    string s,t;
    cin>>s>>t;
    sam.insert(s);
    sam.insert(t);
    sam.build();
    sam.markup(s);
    sam.markup(t);
    cout<<sam.count();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}