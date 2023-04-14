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

constexpr int M=1e6+10;
int prime[M],idx;
LL euler[M];
bool isnp[M];

void init(int n) {
    isnp[1]=1;
    for(int i=2;i<=n;i++) {
        if(!isnp[i]) prime[++idx]=i,euler[i]=i-1;
        for(int j=1;prime[j]<=n/i;j++) {
            isnp[prime[j]*i]=true;
            if(i%prime[j]==0) {
                euler[i*prime[j]]=euler[i]*prime[j];
                break;
            }
            else euler[i*prime[j]]=euler[i]*(prime[j]-1);
        }
    }
}

void solve() {
    int n;
    LL m;
    cin>>n>>m;
    int l=1,r=n;
    while(l<r) {
        int mid=l+r+1>>1;
        int pos=n/(mid+1);
        LL tot=euler[pos];
        if(tot>=mid) l=mid;
        else r=mid-1;
    }
    
    debug(l);
    LL cost=0;
    for(int k=l;k>=1;k--) {
        int pos=n/(k+1);
        LL tot=euler[pos];
        LL t=min(tot,m)/k;
        m-=t*k;
        cost+=t*(k+1);
        debug(k,tot,t,t*(k+1));
    }
    cout<<(m<=0?cost:-1)<<endl;
}

int main() {
    init(1e6);
    for(int i=1;i<=1e6;i++) euler[i]+=euler[i-1];
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}