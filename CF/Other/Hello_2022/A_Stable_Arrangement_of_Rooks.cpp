#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,k;
    cin>>n>>k;
    if(k>(n+1)/2) {
        cout<<"-1"<<endl;
        return;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++)
            if(k&&(i&1)&&i==j) cout<<'R',k--;
            else cout<<'.';
        cout<<endl;
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