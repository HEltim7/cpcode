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
constexpr int N=2e5+10;

void solve() {
    int n,m;
    cin>>n>>m;
    multiset<LL> st;
    vector<LL> can,op;
    LL sum=0,ans=0;
    for(int i=1;i<=n;i++) {
        int x,y;
        cin>>x>>y;
        if(x==0) st.emplace(y);
        else if(x==1) can.emplace_back(y);
        else op.emplace_back(y);
    }
    sort(can.begin(),can.end(),greater<>());
    sort(op.begin(),op.end(),greater<>());
    partial_sum(op.begin(),op.end(),op.begin());

    while(st.size()>m) st.erase(st.begin());
    for(LL x:st) sum+=x;
    ans=sum;

    for(int i=0,j=0;i<op.size()&&j<can.size();i++) {
        LL cur=op[i];
        while(j<can.size()&&j<cur&&i+1+j+1<=m) {
            while(i+1+1+st.size()>m) {
                sum-=*st.begin();
                st.erase(st.begin());
            }
            st.insert(can[j]);
            sum+=can[j++];
            ans=max(ans,sum);
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}