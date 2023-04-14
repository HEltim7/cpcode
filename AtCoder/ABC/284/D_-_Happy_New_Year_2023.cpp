#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

constexpr int M=3e6+10;
int primes[M],idx;
bool isnp[M];

void get_prime(int n=M-1) {
    isnp[1]=1;
    for(int i=2;i<=n;i++) {
        if(!isnp[i]) primes[++idx]=i;
        for(int j=1;primes[j]<=n/i;j++) {
            isnp[primes[j]*i]=true;
            if(i%primes[j]==0) break;
        }
    }
}

void solve() {
    LL n;
    cin>>n;
    for(int i=1;i<=idx;i++) {
        LL x=primes[i];
        if(n%x==0) {
            LL y2=n/x;
            LL y=sqrt(y2);
            if(y*y==y2) {
                cout<<y<<' '<<x<<endl;
                return;
            }

            if(n%(x*x)==0) {
                cout<<x<<' '<<n/(x*x)<<endl;
                return;
            }
        }
    }
}

int main() {
    get_prime();
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}