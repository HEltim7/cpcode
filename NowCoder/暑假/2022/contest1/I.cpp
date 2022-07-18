#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <cassert>
using namespace std;

#define endl '\n'
using LL=long long;
const int W=7,N=34*4,mod=1e9+7;
LL dp[W+10][N+10];
LL ans[W+10];

LL qpow(LL a,LL b) {
    LL res=1;
    while(b) {
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

void init() {
    for(int i=0;i<W;i++) {
        memset(dp,0,sizeof dp);
        dp[i][N-13]=1;
        for(int j=i;j<W;j++) {
            for(int k=N;k>=(13-2*j)*3;k--) {
                LL p=(13-2*j)*3*qpow(k,mod-2)%mod;
                LL unp=(1-p+mod)%mod;
                dp[j+1][k-1]=(dp[j+1][k-1]+dp[j][k]*p%mod)%mod;
                dp[j][k-1]=(dp[j][k-1]+dp[j][k]*unp%mod)%mod;
            }
        }
        for(int j=0;N-13-j>=0;j++) ans[i]=(ans[i]+dp[W][j]*(N-13-j)%mod)%mod;
    }
}

void solve(int id) {
    map<string,int> mp;
    string in;
    cin>>in;
    for(int i=0;i<in.size();i+=2) {
        string cur;
        cur=cur+in[i]+in[i+1];
        auto it=mp.find(cur);
        if(it==mp.end()) mp.emplace(cur,1);
        else it->second++;
    }
    int p=0;
    for(auto [a,b]:mp) if(b==2) p++;
    cout<<"Case #"<<id<<": ";
    cout<<ans[p]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    init();
    int t;
    cin>>t;
    for(int i=1;i<=t;i++) solve(i);
    return 0;
}