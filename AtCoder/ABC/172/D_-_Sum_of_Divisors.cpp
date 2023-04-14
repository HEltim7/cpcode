#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

constexpr int M=1e7+10;
int primes[M],minp[M],idx;
bool isnp[M];

void get_prime(int n=M-1) {
    isnp[1]=minp[1]=1;
    for(int i=2;i<=n;i++) {
        if(!isnp[i]) primes[++idx]=i,minp[i]=i;
        for(int j=1;primes[j]<=n/i;j++) {
            isnp[primes[j]*i]=true;
            minp[primes[j]*i]=primes[j];
            if(i%primes[j]==0) break;
        }
    }
}

LL cal(int val) {
    LL res=1;
    while(val>1) {
        int cnt=0;
        int t=minp[val];
        while(minp[val]==t) val/=t,cnt++;
        res*=cnt+1;
    }
    return res;
}

void solve() {
    int n;
    cin>>n;
    LL ans=1;
    get_prime(n);
    for(int i=2;i<=n;i++) ans+=cal(i)*i;
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}