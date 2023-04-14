#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    LL n,ans=0;
    cin>>n;

    while(n>2) {
        ans++;
        if(n%2==0) n-=n/2-1;
        else n-=n/2;
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}