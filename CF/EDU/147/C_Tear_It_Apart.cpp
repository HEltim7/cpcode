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
constexpr int N=2e5+10;
int dp[N];

void solve() {
    string s;
    cin>>s;
    
    int ans=N;
    for(char c='a';c<='z';c++) {
        int res=0;
        bool flag=0;
        for(int i=0,pre=-2,len=0;i<s.size();i++) {
            if(s[i]!=c) {
                if(i-pre==1) len++;
                else len=1;
                pre=i;
                flag=1;
            }
            else {
                res=max(res,dp[len]);
                len=0;
            }
            if(i+1==s.size()) {
                res=max(res,dp[len]);
                len=0;
            }
        }
        ans=min(ans,res);
    }
    cout<<ans<<endl;
}

int main() {
    for(int i=1;i<N;i++) dp[i]=dp[i/2]+1;
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}