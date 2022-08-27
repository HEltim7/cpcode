#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...)
#endif

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
constexpr int N=1e5+10;
int a[N],b[N],tmp[N];
vector<PII> segtmp;

bool check(int l,int r,int bit) {
    int cnt=0;
    for(int i=l;i<=r;i++) if(a[i]&(1<<bit)) cnt++;
    for(int i=l;i<=r;i++) if(b[i]&(1<<bit)) cnt++;
    return cnt==r-l+1;
}

void split(int l,int r,int bit) {
    debug(l,r);
    int L=l,R=r;
    for(int i=l;i<=r;i++) 
        if(a[i]&(1<<bit)) tmp[L++]=a[i];
        else tmp[R--]=a[i];
    for(int i=l;i<=r;i++) a[i]=tmp[i];

    if(L-1>=l) segtmp.emplace_back(l,L-1);
    if(r>=L) segtmp.emplace_back(L,r);
    L=l,R=r;
    for(int i=l;i<=r;i++)
        if(b[i]&(1<<bit)) tmp[R--]=b[i];
        else tmp[L++]=b[i];
    for(int i=l;i<=r;i++) b[i]=tmp[i];
}

void solve() {
    int n,ans=0;
    cin>>n;
    vector<PII> seg={{1,n}};
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int k=30;k>=0;k--) {
        bool isok=1;
        for(auto [l,r]:seg) isok=min(isok,check(l,r,k));
        if(isok) {
            for(auto [l,r]:seg) split(l,r,k);
            seg=segtmp;
            debug(segtmp);
            segtmp.clear();
            ans+=1<<k;
            assert(seg.size()<N);
        }
    }
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