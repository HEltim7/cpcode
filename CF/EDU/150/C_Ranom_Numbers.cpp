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

constexpr int D=5;
const vector<LL> val={0,1,10,100,1000,10000};

void solve() {
    string s;
    cin>>s;
    int n=s.size();
    
    auto cal=[&]() {
        LL sum=0;
        vector<bool> cnt(D*2);
        for(int i=n;i>=1;i--) {
            int c=s[i-1]-'A'+1;
            if(cnt[c+1]) sum-=val[c];
            else sum+=val[c];
            for(int j=1;j<=c;j++) cnt[j]=1;
        }
        debug(s,sum);
        return sum;
    };

    LL ans=-1e18;
    vector<bool> mark(D*2);

    auto work=[&](char &cur) {
        char bak=cur;
        int c=cur-'A'+1;
        if(mark[c]) return;
        mark[c]=1;
        for(int j=0;j<D;j++) {
            cur=char('A'+j);
            ans=max(ans,cal());
        }
        cur=bak;
    };
    
    for(int i=n;i>=1;i--) work(s[i-1]);
    mark=vector<bool>(D*2);
    for(int i=1;i<=n;i++) work(s[i-1]);

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