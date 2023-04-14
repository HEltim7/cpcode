#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
int x[3],y[3];

void solve() {
    for(int i=0;i<3;i++) cin>>x[i]>>y[i];
    auto check=[&](int a,int b) {
        return x[a]==x[b]||y[a]==y[b];
    };
    if(
        check(0,1)&&check(0,2)||
        check(1,0)&&check(1,2)||
        check(2,0)&&check(2,1)
    ) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}