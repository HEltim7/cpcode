#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    if(n&1) {
        if(n==3) cout<<"NO"<<endl;
        else {
            cout<<"YES"<<endl;
            int t=n/2-1;
            for(int i=1;i<=n;i++) cout<<(i%2==0?-t-1:t)<<" \n"[i==n];
        }
    }
    else {
        cout<<"YES"<<endl;
        for(int i=1,t=1;i<=n;i++,t*=-1) cout<<t<<" \n"[i==n];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}