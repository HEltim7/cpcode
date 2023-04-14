#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=55;
int arr[N];

void solve() {
    int n;
    cin>>n;

    auto check=[](LL x) {
        return floor(sqrt(x))*floor(sqrt(x))==x;
    };

    auto count=[&](LL x) {
        int res=0;
        for(int i=1;i<=n;i++) res+=check(arr[i]+x);
        return res;
    };

    for(int i=1;i<=n;i++) cin>>arr[i];
    int ans=max(1,count(0));
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            int cur=arr[j]-arr[i];
            for(int k=1;k*k<=cur;k++) {
                if(cur%k==0) {
                    int p=k,q=cur/k,m=(p+q)/2;
                    if(p%2==q%2) {
                        LL x=1LL*m*m-arr[j];
                        if(x>=0) ans=max(ans,count(x));
                    }
                }
            }
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