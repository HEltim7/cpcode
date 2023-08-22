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

template<class S=string> struct KMPAutomaton {
    using C=typename S::value_type;
    vector<int> link;
    S s;
    
    void extend(C c) {
        s.push_back(c);
        if(s.size()==1) {
            link.emplace_back(-1);
            return;
        }
        int i=s.size()-1,j=link[i-1];
        while(j!=-1&&s[i]!=s[j+1]) j=link[j];
        if(s[i]==s[j+1]) j++;
        link.emplace_back(j);
    }

    void append(const S &s) {
        for(C c:s) extend(c);
    }

    int count(const S &t) {
        if(t.size()<s.size()) return 0;
        int res=0;
        for(int i=0,j=-1;i<t.size();i++) {
            while(j!=-1&&t[i]!=s[j+1]) j=link[j];
            if(t[i]==s[j+1]) j++;
            if(j+1==s.size()) {
                res++;
                j=link[j];
            }
        }
        return res;
    }

    vector<int> match(const S &t) {
        if(t.size()<s.size()) return {};
        vector<int> res;
        for(int i=0,j=-1;i<t.size();i++) {
            while(j!=-1&&t[i]!=s[j+1]) j=link[j];
            if(t[i]==s[j+1]) j++;
            if(j+1==s.size()) {
                res.emplace_back(i);
                j=link[j];
            }
        }
        return res;
    }

    void clear() {
        s.clear();
        link.clear();
    }

    KMPAutomaton(const S &s=S{}) { append(s); }
};

struct SuffixAutomaton {
    constexpr static int A=26;
    constexpr static char B='a';
    struct Endpos {
        int link,len;
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
};

void solve() {
    int n,m,q;
    string s,t;
    cin>>n>>m>>q>>s>>t;
    KMPAutomaton<> kmp(s);
    vector<int> border(n+1);
    for(int i=kmp.link.back();~i;i=kmp.link[i]) border[i+1]=1;
    partial_sum(border.begin(),border.end(),border.begin());

    s.pop_back();
    s.erase(s.begin());
    SuffixAutomaton sam(s);
    const auto &edp=sam.edp;

    auto cal=[&](int l,int r) {
        if(l>=n) return 0;
        return border[n-l]-border[n-r-1];
    };

    vector<int> pos(m+1);
    vector<LL> pre(m+1);
    for(int i=1,u=0,len=0;i<=m;i++) {
        int c=t[i-1]-sam.B;
        while(u&&!edp[u].ch[c]) u=edp[u].link,len=edp[u].len;
        if(edp[u].ch[c]) u=edp[u].ch[c],len++;
        pre[i]=pre[i-1]+cal(1,len);
        pos[i]=i-len+1;
    }

    vector<LL> all(m+1);
    for(LL i=1,sum=0;i<=m;i++) {
        sum+=cal(i,i);
        all[i]=all[i-1]+sum;
    }

    while(q--) {
        int l,r;
        cin>>l>>r;
        if(pos[r]<=l) cout<<all[r-l+1]<<endl;
        else {
            int x=l,y=r;
            while(x<y) {
                int mid=(x+y)/2;
                if(pos[mid]<l) x=mid+1;
                else y=mid;
            }
            cout<<pre[r]-pre[x-1]+all[x-l]<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}