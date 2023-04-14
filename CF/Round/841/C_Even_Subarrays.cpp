#include <map>
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
vector<int> num;
constexpr int N=4e5+10;
int cnt[N*2];

void solve() {
    int n;
    cin>>n;
    LL ans=1LL*n*(n+1)/2;
    vector<int> tmp;
    for(int i=1,pre=0;i<=n;i++) {
        int in;
        cin>>in;
        pre^=in;
        for(auto x:num) ans-=cnt[x^pre];
        cnt[pre]++;
        tmp.push_back(pre);
    }
    for(auto x:tmp) cnt[x]--;
    cout<<ans<<endl;
}

int main() {
    cnt[0]=1;
    for(int i=0;i*i<N;i++) num.push_back(i*i);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}