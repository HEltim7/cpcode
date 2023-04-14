#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    bool ans=0;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        if(in==1) ans=1;
    }
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}