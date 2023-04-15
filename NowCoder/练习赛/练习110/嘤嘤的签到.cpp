#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    s=" "+s;

    LL ans=0;
    for(int i=1,pre1=0,pre4=0;i<=n;i++) {
        if(s[i]=='1') pre1=i;
        else if(s[i]=='4') pre4=i;
        ans+=i-min(pre1,pre4);
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}