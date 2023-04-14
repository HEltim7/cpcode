#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

constexpr int M=1e6+10;
int prime[M],minp[M],idx;
bool isnp[M];

void get_prime(int n=M-1) {
    isnp[1]=minp[1]=1;
    for(int i=2;i<=n;i++) {
        if(!isnp[i]) prime[++idx]=i,minp[i]=i;
        for(int j=1;prime[j]<=n/i;j++) {
            isnp[prime[j]*i]=true;
            minp[prime[j]*i]=prime[j];
            if(i%prime[j]==0) break;
        }
    }
}

void solve() {
    int x;
    cin>>x;
    x--;
    if(x%2==0) {
        if(x==2) cout<<4<<endl;
        else if(x==4) cout<<-1<<endl;
        else if(x==6) cout<<8<<endl;
        else {
            for(int i=1;i<=idx;i++) {
                int t=x-prime[i];
                if(!isnp[t]&&t!=i) {
                    cout<<1LL*prime[i]*t<<endl;
                    return;
                }
            }
        }
    }
    else {
        if(!isnp[x]) cout<<1LL*x*x<<endl;
        else cout<<1LL*2*(x-2)<<endl;
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