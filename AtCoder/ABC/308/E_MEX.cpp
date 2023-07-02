#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
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
constexpr int N=2e5+10;
int arr[N];
char s[N];
LL dp[N][2][10];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++) cin>>s[i];

    LL ans=0;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<2;j++) {
            for(int k=0;k<8;k++) {
                dp[i][j][k]=dp[i-1][j][k];
            }
        }
        if(s[i]=='M') {
            dp[i][0][1<<arr[i]]++;
        }
        else if(s[i]=='E') {
            for(int k=0;k<8;k++) {
                dp[i][1][k|(1<<arr[i])]+=dp[i-1][0][k];
            }
        }
        else {
            for(int k=0;k<8;k++) {
                int cur=k|(1<<arr[i]);
                for(int b=0;b<4;b++) {
                    if(!(cur>>b&1)) {
                        ans+=dp[i-1][1][k]*b;
                        break;
                    }
                }
            }
        }
    }
    debug(dp[3][1],1,7);

    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}