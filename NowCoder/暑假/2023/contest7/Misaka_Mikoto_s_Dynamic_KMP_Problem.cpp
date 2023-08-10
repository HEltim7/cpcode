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

    void build(const S &s) {
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

    void clear() {
        s.clear();
        link.clear();
    }
};

void solve() {
    int n,q;
    LL b,p;
    cin>>n>>q>>b>>p;
    KMPAutomaton<vector<LL>> kmp;

    vector<LL> s;
    for(int i=1;i<=n;i++) {
        LL in;
        cin>>in;
        s.emplace_back(in);
    }

    LL z=0,preb=1,ans=0;
    while(q--) {
        int op;
        cin>>op;
        if(op==1) {
            LL x,c;
            cin>>x>>c;
            x=(x^z)%n+1;
            s[x-1]=c^z;
        }
        else {
            preb=preb*b%p;
            int m;
            cin>>m;
            vector<LL> t(m);
            for(LL &x:t) cin>>x,x^=z;
            if(m<n) z=0;
            else {
                kmp.clear();
                kmp.build(s);
                LL x=kmp.count(t);
                LL y=kmp.link.back()+1;
                z=x*y;
                ans=(ans+z%p*preb)%p;
            }
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}