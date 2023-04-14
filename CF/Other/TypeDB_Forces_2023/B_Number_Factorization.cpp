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

constexpr int M=1e6+10;
int prime[M],minp[M],idx;
bool isnp[M];

void get_prime(int n=M-1) {
    isnp[1]=minp[1]=1;
    for(int i=2;i<=n;i++) {
        if(!isnp[i]) prime[++idx]=i,minp[i]=i;
        for(int j=1;prime[j]<=n/i;j++) {
            isnp[prime[j]*i]=true;
            minp[prime[j]*i]=prime[j];
            if(i%prime[j]==0) break;
        }
    }
}

vector<pair<int,int>> get_factor(int val) {
    vector<pair<int,int>> res;
    for(int i=1,t=val;prime[i]*prime[i]<=t&&val>1;i++) {
        int cnt=0;
        while(val%prime[i]==0) cnt++,val/=prime[i];
        if(cnt) res.emplace_back(cnt,prime[i]);
    }
    if(val>1) res.emplace_back(1,val);
    return res;
}

void solve() {
    int n;
    cin>>n;
    LL ans=0;
    auto &&res=get_factor(n);
    sort(res.begin(),res.end(),greater<>());

    while(res.size()) {
        LL sum=1;
        for(auto &[cnt,x]:res) sum*=x,cnt--;
        while(res.size()&&res.back().first<=0) res.pop_back();
        ans+=sum;
    }
    cout<<ans<<endl;
}

int main() {
    get_prime();
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}