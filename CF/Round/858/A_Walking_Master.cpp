#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(d>=b&&(c-a)<=(d-b)) {
        int ans=d-b;
        a+=(d-b);
        ans+=a-c;
        cout<<ans<<endl;
    }
    else cout<<-1<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}