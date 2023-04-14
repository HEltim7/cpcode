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
        cout<<-1<<endl;
        return;
    }

    n--;
    cout<<__lg(n)<<endl;
    for(int i=__lg(n);i>=1;i--) {
        if(n>>i&1) cout<<2<<' ';
        else cout<<1<<' ';
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}