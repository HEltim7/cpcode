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
int a[N],b[N],pa[N],pb[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],pa[a[i]]=i;
    for(int i=1;i<=n;i++) cin>>b[i],pb[b[i]]=i;
    
    auto cal=[](LL len) { return len*(len+1)/2; };
    LL ans=
        cal(min(pa[1],pb[1])-1)+
        cal(max(pa[1],pb[1])-min(pa[1],pb[1])-1)+
        cal(n-max(pa[1],pb[1]));
    ans++;
    
    int l=min(pa[1],pb[1]);
    int r=max(pa[1],pb[1]);
    for(int i=2;i<=n;i++) {
        int L=min(pa[i],pb[i]);
        int R=max(pa[i],pb[i]);
        if(pa[i]>=l&&pa[i]<=r||pb[i]>=l&&pb[i]<=r) {
            l=min(l,L);
            r=max(r,R);
            continue;
        }
        debug(i,l,r,ans);
        int lenl=l,lenr=n-r+1;
        if(pa[i]<l) lenl=min(lenl,l-pa[i]);
        if(pb[i]<l) lenl=min(lenl,l-pb[i]);
        if(pa[i]>r) lenr=min(lenr,pa[i]-r);
        if(pb[i]>r) lenr=min(lenr,pb[i]-r);
        debug(lenl,lenr);
        ans+=1LL*lenl*lenr;
        l=min(l,L);
        r=max(r,R);
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}