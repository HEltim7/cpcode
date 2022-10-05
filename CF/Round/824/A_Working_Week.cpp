#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    n-=4;
    int x=n/3;
    int ans=0;
    for(int i=-3;i<=6;i++) {
        int a=x+i;
        int b=n-a;
        if(a>0&&b>0&&b>a)
            ans=max(ans,min(b-a,a-1));
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