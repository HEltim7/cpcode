#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    LL n;
    cin>>n;
    LL ans=0;
    while(n) {
        if(n&1) {
            bool flag=0;
            for(LL i=2;i*i<=n;i++) {
                if(n%i==0) {
                    n-=i;
                    flag=1;
                    ans++;
                    break;
                }
            }
            if(!flag) ans++,n=0;
        }
        else {
            ans+=n/2;
            n=0;
        }
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}