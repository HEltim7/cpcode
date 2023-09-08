#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;

constexpr int M=1e7+10;
int prime[M],idx;
bool isnp[M];

void get_prime(int n=M-1) {
    isnp[1]=1;
    for(int i=2;i<=n;i++) {
        if(!isnp[i]) prime[++idx]=i;
        for(int j=1;prime[j]<=n/i;j++) {
            isnp[prime[j]*i]=true;
            if(i%prime[j]==0) break;
        }
    }
}

void solve() {
    int l,r;
    cin>>l>>r;
    l=max(l,4);
    for(int i=l;i<=r;i++) {
        if(isnp[i]) {
            for(int a=2,b=i-a;a<=b;a++,b--) {
                if(gcd(a,b)>1) {
                    cout<<a<<' '<<b<<endl;
                    return;
                }
            }
        }
    }
    cout<<-1<<endl;
}

int main() {
    get_prime();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}