#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
const int N=2e5+10,INF=0x3f3f3f3f;
PII dp[N][2][2];

// #define __DEBUG
#ifdef __DEBUG
#include<debug>
#else
#define debug(...)
#endif

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    s=" "+s;
    debug(s);
    dp[0][0][1]={INF,INF};
    dp[0][1][1]={INF,INF};
    for(int i=1;i<=n;i++) {
        dp[i][0][0]={dp[i-1][0][1].first+(s[i]=='1'),dp[i-1][0][1].second};
        
        int a,b,c,d;
        a=dp[i-1][0][0].first,b=dp[i-1][0][0].second;
        c=dp[i-1][1][0].first,d=dp[i-1][1][0].second;
        if(a==c) dp[i][0][1]={a+(s[i]=='1'),min(b,d+1)};
        else if(a<c) dp[i][0][1]={a+(s[i]=='1'),b};
        else dp[i][0][1]={c+(s[i]=='1'),d+1};
        
        ///

        dp[i][1][0]={dp[i-1][1][1].first+(s[i]=='0'),dp[i-1][1][1].second};
        
        a=dp[i-1][1][0].first,b=dp[i-1][1][0].second;
        c=dp[i-1][0][0].first,d=dp[i-1][0][0].second;
        if(a==c) dp[i][1][1]={a+(s[i]=='0'),min(b,d+1)};
        else if(a<c) dp[i][1][1]={a+(s[i]=='0'),b};
        else dp[i][1][1]={c+(s[i]=='0'),d+1};

        if(i==1) {
            dp[i][0][0].second=1;
            dp[i][0][1].second=1;
            dp[i][1][0].second=1;
            dp[i][1][1].second=1;
        }

        debug(i,dp[i][0][0],dp[i][0][1],dp[i][1][0],dp[i][1][1]);
    }
    // cout<<min(dp[n][0][0],dp[n][1][0])<<endl;
    auto [a,b]=dp[n][0][0];
    auto [c,d]=dp[n][1][0];
    if(a==c) cout<<a<<' '<<min(b,d)<<endl;
    else if(a<c) cout<<a<<' '<<b<<endl;
    else cout<<c<<' '<<d<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}