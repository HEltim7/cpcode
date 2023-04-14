#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    if(n&1) for(int i=1;i<=n;i++) cout<<1<<" \n"[i==n];
    else if(n==2) cout<<"1 3"<<endl;
    else {
        cout<<"1 3 ";
        for(int i=3;i<=n;i++) cout<<2<<" \n"[i==n];
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