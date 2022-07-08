#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=4e5+10;
LL pre[N];
LL cnt[N];

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<debug>
#else
#define debug(...)
#endif

void solve() {
    LL n,m;
    cin>>n>>m;
    memset(pre,0,sizeof (LL)*(m*2+1));
    memset(cnt,0,sizeof (LL)*(n+1));
    for(int i=1;i<=m;i++) {
        int in;
        cin>>in;
        cnt[in]++;
    }
    for(int i=1;i<=n;i++) pre[1]++,pre[cnt[i]+1]--;
    for(int i=1;i<=m;i++) pre[i]+=pre[i-1];
    for(int i=1;i<=m;i++) debug(pre[i]);
    debug();
    for(int i=1,last=0;m>0;i++) {
        m-=pre[i];
        m-=last;
        last=n-pre[i]-last;
        if(m<=0) {
            cout<<i<<endl;
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}