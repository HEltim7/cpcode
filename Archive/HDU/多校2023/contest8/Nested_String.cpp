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
    string s,t1,t2;
    cin>>t1>>t2>>s;
    int n=s.size();
    auto &&valid=zfunc(t2+"#"+s);
    valid.erase(valid.begin(),valid.begin()+t2.size()+1);
    for(int &x:valid) x=x==t2.size();
    partial_sum(valid.begin(),valid.end(),valid.begin());

    auto &&pre=zfunc(t1+"#"+s);
    pre.erase(pre.begin(),pre.begin()+t1.size()+1);

    reverse(t1.begin(),t1.end());
    reverse(s.begin(),s.end());
    auto &&suf=zfunc(t1+"#"+s);
    suf.erase(suf.begin(),suf.begin()+t1.size()+1);
    reverse(suf.begin(),suf.end());

    LL ans=0;
    for(int l=0,r=l+t1.size()+t2.size()-1;r<n;l++,r++) {
        int y=l+pre[l];
        int x=r-suf[r]-t2.size()+1;
        if(x<=y) ans+=valid[y]-(x?valid[x-1]:0);
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}