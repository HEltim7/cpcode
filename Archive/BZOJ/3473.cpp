#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
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

struct GeneralSuffixAutomaton {
    constexpr static int A=26;
    constexpr static char B='a';
    using Arr=array<int, A>;
    struct Endpos {
        int link,len,cnt;
        Arr ch;
    };
    vector<Arr> tr;
    vector<Endpos> edp;

    int new_tr() { tr.emplace_back(); return tr.size()-1; }
    int new_edp() { edp.emplace_back(); return edp.size()-1; }

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

    void extend(int &p,int &t,char x,int len) {
        int c=x-B;
        int last;
        if(tr[t][c]) last=edp[p].ch[c];
        else {
            tr[t][c]=new_tr();
            if(edp[p].ch[c]) last=split(p, c, len);
            else {
                int cur=last=new_edp();
                edp[cur].len=len;
                for(;p!=-1&&!edp[p].ch[c];p=edp[p].link)
                    edp[p].ch[c]=cur;
                if(p!=-1) edp[cur].link=split(p, c, edp[p].len+1);
            }
        }
        t=tr[t][c];
        p=last;
    }

    vector<int> toporder;
    void toposort(string &s) {
        auto &q=toporder;
        static int cid=0;
        static vector<int> col,ind,vec;
        col.resize(size()),ind.resize(size());
        vec.clear(),q.clear();
        cid++;

        int u=0;
        for(char x:s) {
            int c=x-B;
            u=edp[u].ch[c];
            for(int p=u;p&&col[p]!=cid;p=edp[p].link) {
                col[p]=cid;
                vec.emplace_back(p);
                ind[edp[p].link]++;
            }
        }

        for(int u:vec) if(!ind[u]) q.emplace_back(u);
        for(int u:q) {
            int p=edp[u].link;
            if(p&&!--ind[p]) q.emplace_back(p);
        }
    }

    void update_count(string &s) {
        toposort(s);
        for(int u:toporder) edp[u].cnt++;
    }

    vector<int> cnt;
    LL count(string &s,int k) {
        cnt.resize(size());
        int u=0;
        for(char x:s) {
            int c=x-B;
            u=edp[u].ch[c];
            cnt[u]++;
        }
        LL res=0;
        toposort(s);
        for(int u:toporder) cnt[edp[u].link]+=cnt[u];
        for(int u:toporder) {
            if(edp[u].cnt>=k) res+=1LL*(edp[u].len-edp[edp[u].link].len)*cnt[u];
            cnt[u]=0;
        }
        return res;
    }

    void insert(string &s) {
        for(int p=0,t=0,i=0;i<s.size();i++) extend(p, t, s[i], i+1);
    }

    int size() { return edp.size(); }
    
    void clear() {
        edp.clear(),edp.push_back({-1});
        tr.clear(),tr.push_back({});
    }
    
    GeneralSuffixAutomaton(int sz=0) { edp.reserve(sz),tr.reserve(sz),clear(); }
} sam(1e5+10);

void solve() {
    int n,k;
    cin>>n>>k;
    vector<string> s(n);
    for(string &x:s) cin>>x,sam.insert(x);
    for(string &x:s) sam.update_count(x);
    for(string &x:s) cout<<sam.count(x, k)<<' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}