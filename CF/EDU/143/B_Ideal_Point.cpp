#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=110;
int cnt[N];

void solve() {
    int n,k;
    cin>>n>>k;
    for(int i=0;i<N;i++) cnt[i]=0;
    for(int i=1;i<=n;i++) {
        int l,r;
        cin>>l>>r;
        if(k>=l&&k<=r) {
            cnt[l]++;
            cnt[r+1]--;
        }
    }
    
    int maxx=0;
    for(int i=1;i<=60;i++) cnt[i]+=cnt[i-1];
    for(int i=1;i<=60;i++) if(i!=k) maxx=max(maxx,cnt[i]);
    debug(cnt,1,5,maxx);
    if(cnt[k]>maxx) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}