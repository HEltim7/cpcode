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

void solve() {
    int n,x,y;
    cin>>n>>x>>y;
    vector<LL> ans(10);
    vector<int> p(n+1),t(n+1);
    for(int i=1;i<n;i++) cin>>p[i]>>t[i];

    auto work=[&](LL cur=0) {
        cur+=x;
        for(int i=1;i<n;i++) {
            if(cur%p[i]) cur+=p[i]-cur%p[i];
            cur+=t[i];
        }
        cur+=y;
        return cur;
    };

    using ARR=array<int,8>;
    map<ARR,LL> mp;
    ARR cur={};
    for(int i=0;;i++) {
        for(int j=1;j<=8;j++) cur[j-1]=i%j;
        if(mp.find(cur)!=mp.end()) break;
        mp[cur]=work(i)-i;
    }

    int q;
    cin>>q;
    while(q--) {
        LL in;
        cin>>in;
        for(int j=1;j<=8;j++) cur[j-1]=in%j;
        cout<<mp[cur]+in<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}