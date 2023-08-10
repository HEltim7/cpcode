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

vector<int> zfunc(const string &s) {
    int n=s.size();
    vector<int> z(n);
    for(int i=1,l=0,r=0;i<n;i++) {
        if(i<=r) z[i]=min(z[i-l],r-i+1);
        while(i+z[i]<n&&s[i+z[i]]==s[z[i]]) z[i]++;
        if(i+z[i]-1>r) l=i,r=i+z[i]-1;
    }
    return z;
}

void solve() {
    auto get=[&](string &s) {
        auto &&z=zfunc(s);
        int n=s.size();
        string cur{s.front()};
        for(int i=1;i<n;i++) {
            if(n%i==0&&i+z[i]==n) return cur;
            cur.push_back(s[i]);
        }
        return cur;
    };

    int n;
    cin>>n;
    vector<int> ans(n+1);
    set<int> st;
    auto vec=vector(n+1,vector<pair<int,int>>());
    map<string,int> mp;
    int idx=0;

    for(int i=1;i<=n;i++) {
        string s;
        cin>>s;
        int x=s.size();
        s=get(s);
        int y=s.size();
        if(mp.find(s)==mp.end()) mp[s]=++idx;
        vec[mp[s]].emplace_back(i,x/y);
    }

    for(int i=1;i<=idx;i++) {
        set<int> st;
        map<int,pair<int,int>> last;
        for(auto [id,x]:vec[i]) {
            int t=x,cnt=1;
            auto it=last.find(x);
            if(it!=last.end()) tie(x,cnt)=it->second;
            else it=last.emplace(x,pair{x,cnt}).first;

            while(st.find(x)!=st.end()) x+=t,cnt++;
            st.insert(x);
            ans[id]=cnt;
            it->second={x,cnt};
        }
    }

    for(int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}