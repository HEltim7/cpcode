#include<vector>
#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;

#define endl '\n'
#define lowbit(x) (x&(-x))
using LL=long long;
const int mod=998244353;
const int N=1e3+10,M=5e3+10;
int n,m,k;
LL dp[N][M];

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<debug>
#else
#define debug(...)
#endif

void add(int id,int pos,LL val) {
    while(pos<=m) dp[id][pos]=(dp[id][pos]+val)%mod,pos+=lowbit(pos);
}

LL __query(int id,int pos) {
    LL res=0;
    while(pos) res=(res+dp[id][pos])%mod,pos-=lowbit(pos);
    return res;
}

LL query(int id,int x) {
    if(id==1) return 1;
    LL res=0;
    int l=x-k,r=x+k;
    if(!k) r++;
    debug(l,r);
    if(l>0) res=(res+__query(id-1,l))%mod;
    if(r<=m) res=(res+__query(id-1,m)-__query(id-1,r-1)+mod)%mod;
    assert(res>=0);
    debug(id,x,res);
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=m;j++) {
            // debug(i,j,query(i,j));
            add(i,j,query(i,j));
        }
    cout<<__query(n,m);
    return 0;
}