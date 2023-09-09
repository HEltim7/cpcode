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
    int n,m;
    cin>>n>>m;
    vector<LL> len(n+1);
    for(int i=1;i<=n;i++) cin>>len[i];
    LL l=*max_element(len.begin(),len.end());
    LL r=accumulate(len.begin(),len.end(),0LL)+n-1;
    auto check=[&](LL mid) {
        int cnt=1;
        LL cur=0;
        for(int i=1;i<=n;i++) {
            if(cur) cur++;
            cur+=len[i];
            if(cur>mid) {
                cur=len[i];
                cnt++;
            }
        }
        return cnt<=m;
    };
    while(l<r) {
        LL mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}