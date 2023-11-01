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
    int n,k;
    cin>>n>>k;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++) cin>>arr[i];
    if(n==1) {
        cout<<0<<endl;
        return;
    }
    
    auto get_type=[&](int idx) {
        if(arr[idx]==1) return 1;
        if(idx>1&&gcd(arr[idx],arr[idx-1])==1) return 0;
        if(idx<n&&gcd(arr[idx],arr[idx+1])==1) return 0;
        return -1;
    };

    int tot=0,ans=0;
    vector<pair<int,int>> seg,vec;
    for(int i=1;i<=n;i++) {
        int t=get_type(i);
        if(seg.size()&&seg.back().first==t&&gcd(arr[i-1],arr[i])==1)
            seg.back().second++;
        else seg.emplace_back(t,1);
        if(i>1&&gcd(arr[i],arr[i-1])==1) tot++;
    }

    for(int i=0;i<seg.size();i++) {
        auto [t,len]=seg[i];
        if(t==-1) continue;
        if(t==0) {
            if(len>=2) {
                int t=min(k,(len-1)/2);
                ans+=t*2;
                k-=t;
                if(len%2==0) vec.emplace_back(0,1);
            }
        }
        else {
            int bonus=1-(i-1<0)-(i+1>=seg.size());
            vec.emplace_back(bonus,seg[i].second);
        }
    }

    sort(vec.begin(),vec.end(),[](pair<int,int> x,pair<int,int> y) {
        if(x.first!=y.first) return x.first>y.first;
        return x.second<y.second;
    });

    for(auto [bonus,len]:vec) {
        if(k<=0) break;
        int t=min(len,k);
        ans+=t;
        k-=t;
        if(bonus==1&&t==len) ans++;
        if(bonus==-1) ans--;
    }
    cout<<tot-ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}