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

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;

void solve() {
    int l=0,r=0;
    vector<int> mid;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        if(in==-1) l++;
        else if(in==-2) r++;
        else mid.push_back(in);
    }

    if(mid.empty()) {
        cout<<min(m,max(l,r))<<endl;
        return;
    }
    mid.push_back(0),mid.push_back(m+1);
    sort(mid.begin(),mid.end());
    mid.erase(unique(mid.begin(),mid.end()),mid.end());
    
    int ans=mid.size()-2,res=ans;
    vector<int> seg;
    seg.push_back(0);
    for(int i=1;i<mid.size();i++) {
        seg.push_back(mid[i]-mid[i-1]-1);
    }
    seg.push_back(0);
    debug(seg);
    vector<int> pre(seg.size()),suf(seg.size());
    partial_sum(seg.begin(),seg.end(),pre.begin());
    reverse(seg.begin(),seg.end());
    partial_sum(seg.begin(),seg.end(),suf.begin());
    reverse(suf.begin(),suf.end());
    debug(pre,suf);

    for(int i=0;i+1<pre.size();i++) {
        int cur=res+min(l,pre[i])+min(suf[i+1],r);
        ans=max(ans,cur);
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}