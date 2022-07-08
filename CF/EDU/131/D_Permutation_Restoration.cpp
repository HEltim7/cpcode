#include<vector>
#include<iostream>
#include<algorithm>
#include<tuple>
#include<map>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
using TIII=tuple<int,int,int>;
const int N=5e5+10;
int arr[N];
int ans[N];

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<debug>
#else
#define debug(...)
#endif

void solve() {
    int n;
    cin>>n;
    vector<TIII> seg;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        int l=1,r=n;
        while(l<r) {
            int mid=l+r>>1;
            if(i/mid<=arr[i]) r=mid;
            else l=mid+1;
        }
        int L=l;
        l=1,r=n;
        while(l<r) {
            int mid=l+r+1>>1;
            if(i/mid>=arr[i]) l=mid;
            else r=mid-1;
        }
        int R=l;
        seg.push_back({L,R,i});
    }
    sort(seg.begin(),seg.end());
    debug(seg);
    multimap<int,int> mp;
    for(int i=1,j=0;i<=n;i++) {
        for(;j<n;j++) {
            debug(j);
            auto [l,r,id]=seg[j];
            if(l<=i) mp.emplace(r,id);
            else break;
        }
        debug(mp);
        ans[mp.begin()->second]=i;
        mp.erase(mp.begin());
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}