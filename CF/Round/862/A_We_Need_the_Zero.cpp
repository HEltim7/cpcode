#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    int xsum=0,in;
    for(int i=1;i<=n;i++) cin>>in,xsum^=in;
    if(n%2==0&&xsum) cout<<-1<<endl;
    else cout<<xsum<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}