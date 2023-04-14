#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    bool ans=1;
    int t=n/k,cnt=0;
    for(int i=1;i<=m;i++) {
        int in;
        cin>>in;
        if(in-t>1) ans=0;
        else if(in-t==1) cnt++;
    }
    if(cnt>n-t*k) ans=0;
    cout<<(ans?"YES":"NO")<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}