#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int a,b;
    cin>>a>>b;
    a=abs(a),b=abs(b);
    int ans=min(a,b)*2;
    if(max(a,b)>min(a,b)) ans+=(max(a,b)-min(a,b))*2-1;
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