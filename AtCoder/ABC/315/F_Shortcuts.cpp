#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <iomanip>
#include <limits>
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
using LD=long double;
constexpr int N=1e4+10,M=70;
LD dp[N][M];
int x[N],y[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];

    auto dis=[&](int i,int j) {
        LL a=x[i]-x[j];
        LL b=y[i]-y[j];
        return sqrtl(a*a+b*b);
    };

    for(int i=2;i<=n;i++) {
        for(int k=0;k<M;k++) dp[i][k]=numeric_limits<LD>().infinity();
        for(int j=i-1,d=0;j>=1&&i-j<M;j--,d++) {
            for(int k=0;k<M;k++) {
                if(k-d>=0) dp[i][k]=min(dp[i][k],dp[j][k-d]+dis(i,j));
            }
        }
    }

    cout<<fixed<<setprecision(20);
    LD p=0,ans=numeric_limits<LD>().infinity();
    for(int k=0;k<M;k++) {
        ans=min(ans,dp[n][k]+p);
        if(k==0) p++;
        else p*=2;
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}