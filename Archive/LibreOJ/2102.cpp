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

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;

struct SuffixAutomaton {
    constexpr static int A=26;
    constexpr static char B='a';
    struct Endpos {
        int link,len,cnt,path;
        int ch[A];
        vector<int> rev;
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

    void build_rev() {
        for(int i=0;i<size();i++) {
            for(int j=0;j<A;j++) {
                int v=edp[i].ch[j];
                if(v) edp[v].rev.emplace_back(i);
            }
        }
    }

    vector<int> toporder;
    void toposort() {
        vector<int> cnt(size());
        toporder.resize(size()-1);
        for(int i=1;i<size();i++) cnt[edp[i].len]++;
        partial_sum(cnt.rbegin(),cnt.rend(),cnt.rbegin());
        for(int i=1;i<size();i++) toporder[--cnt[edp[i].len]]=i;
    }

    void count(const string &s) {
        int u=0;
        for(auto x:s) {
            int c=x-B;
            u=edp[u].ch[c];
            edp[u].cnt++;
        }
        for(int u:toporder) {
            int p=edp[u].link;
            if(p) edp[p].cnt+=edp[u].cnt;
        }
    }

    void count_path() {
        for(int u:toporder) {
            edp[u].path+=edp[u].cnt;
            for(int p:edp[u].rev) edp[p].path+=edp[u].path;
        }
    }

    string kth(int k) {
        string res;
        int u=0;
        while(edp[u].path>=k) {
            if(edp[u].cnt>=k) return res;
            k-=edp[u].cnt;
            for(int i=0;i<A;i++) {
                int v=edp[u].ch[i];
                if(!v) continue;
                if(edp[v].path>=k) {
                    u=v;
                    res+=B+i;
                    break;
                }
                else k-=edp[v].path;
            }
        }
        return string{"-1"};
    }

    int size() { return edp.size(); }
    void build(const string &s) { for(auto x:s) extend(x); }
    void clear() { edp.clear(),edp.push_back({-1}),last=0; }
    
    SuffixAutomaton(int sz=0) { edp.reserve(sz),clear(); }
    SuffixAutomaton(const string &s) { edp.reserve(s.size()*2),clear(),build(s); }
};

void solve() {
    string s;
    cin>>s;
    SuffixAutomaton sam(s);
    int t,k;
    cin>>t>>k;
    sam.build_rev();
    sam.toposort();
    if(t) sam.count(s);
    else for(int i=1;i<sam.size();i++) sam.edp[i].cnt=1;

    sam.count_path();
    cout<<sam.kth(k)<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}