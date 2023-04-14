#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    if(n%2==0) {
        cout<<"No"<<endl;
        return;
    }

    cout<<"Yes"<<endl;
    int a1=3*(n+1)/2;
    for(int i=1,j=a1-1;j<=2*n;i++,j++) {
        cout<<i<<' '<<j<<endl;
    }
    for(int i=2*n-a1+3,j=a1-i+1;j<a1-1;i++,j++) {
        cout<<i<<' '<<j<<endl;
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