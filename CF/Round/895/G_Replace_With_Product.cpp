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
    int n;
    cin>>n;
    vector<LL> a(n+1);
    vector<int> pos;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        if(a[i]>1) pos.emplace_back(i);
    }

    if(pos.empty()) {
        cout<<1<<' '<<1<<endl;
        return;
    }

    LL prod=1;
    for(int i=1;i<=n;i++) {
        prod*=a[i];
        if(prod>int(1e6)) {
            cout<<pos.front()<<' '<<pos.back()<<endl;
            return;
        }
    }

    auto pre=a;
    partial_sum(a.begin(),a.end(),pre.begin());

    int l=0,r=0;
    for(int i=0,maxx=0;i<pos.size();i++) {
        for(int j=i,cur=1;j<pos.size();j++) {
            cur*=a[pos[j]];
            int res=pre[n]-(pre[pos[j]]-pre[pos[i]-1])+cur;
            if(res>maxx) {
                l=pos[i],r=pos[j];
                maxx=res;
            }
        }
    }
    assert(l);
    cout<<l<<' '<<r<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}