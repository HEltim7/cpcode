#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,m;
    cin>>n>>m;
    if(m<n) cout<<"No"<<endl;
    else if(n&1) {
        cout<<"Yes"<<endl;
        for(int i=1;i<n;i++) cout<<1<<' ';
        cout<<m-(n-1)<<endl;
    }
    else {
        if(m&1) cout<<"No"<<endl;
        else {
            cout<<"Yes"<<endl;
            for(int i=1;i<=n-2;i++) cout<<1<<' ';
            int t=m-(n-2);
            cout<<t/2<<' '<<t/2<<endl;
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