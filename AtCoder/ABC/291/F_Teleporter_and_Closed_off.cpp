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
constexpr int N=1e5+10,M=12,INF=1e9;
int pre[N],suf[N];
string s[N];

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>s[i];
        s[i]=" "+s[i];
    }

    for(int i=1;i<=n;i++) pre[i]=suf[i]=INF;
    pre[1]=suf[n]=0;
    for(int i=2;i<=n;i++) {
        for(int j=i-1;j>=max(1,i-m);j--) {
            if(s[j][i-j]=='1') pre[i]=min(pre[i],pre[j]+1);
        }
    }
    for(int i=n-1;i>=1;i--) {
        for(int j=i+1;j<=min(n,i+m);j++) {
            if(s[i][j-i]=='1') suf[i]=min(suf[i],suf[j]+1);
        }
    }
    debug(pre,1,n);
    debug(suf,1,n);

    for(int k=2;k<n;k++) {
        int ans=INF;
        for(int i=max(1,k-m+1);i<k;i++) {
            for(int j=k+1;j<=min(n,i+m);j++) {
                if(s[i][j-i]=='1'&&j!=k) {
                    ans=min(ans,pre[i]+suf[j]+1);
                }
            }
        }
        if(ans==INF) cout<<-1<<' ';
        else cout<<ans<<' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}