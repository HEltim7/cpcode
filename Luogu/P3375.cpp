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

    KMPAutomaton(const S &s=S{}) { build(s); }
};

void solve() {
    string s,t;
    cin>>t>>s;
    KMPAutomaton<> kmp(s);
    auto &&v=kmp.match(t);
    for(int x:v) cout<<x+2-s.size()<<endl;
    for(int i=0;i<s.size();i++) cout<<kmp.link[i]+1<<' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}