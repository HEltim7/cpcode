#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            if(j==1||j==i) cout<<1<<" \n"[j==i];
            else cout<<0<<" \n"[j==i];
        }
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