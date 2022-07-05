#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e5+10,mod=1e9+7;
int arr[N],pos[N];
LL cnt[N];
bool mark[N];

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<debug>
#else
#define debug(...)
#endif

void solve() {
    int n;
    cin>>n;
    memset(mark,0,sizeof (bool)*(n+1));
    for(int i=1;i<=n;i++) cin>>arr[i],pos[arr[i]]=i;
    int idx=1;
    cnt[0]=1;
    mark[0]=1;
    debug(arr,1,n,pos,1,n);
    for(int i=1,l=pos[0],r=pos[0];i<n;i++) {
        if(mark[i]) cnt[i]=idx;
        else {
            mark[i]=1;
            while(pos[i]>r) mark[arr[++r]]=1,idx++;
            while(pos[i]<l) mark[arr[--l]]=1,idx++;
            debug(i,l,r);
            cnt[i]=i+1;
        }
    }
    debug(cnt,0,n-1);
    LL ans=1;
    for(int i=0;i<n;i++) ans=ans*(cnt[i]-i)%mod;
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