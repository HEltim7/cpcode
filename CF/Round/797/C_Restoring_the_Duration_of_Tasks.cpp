#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
int s[N],f[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++) cin>>f[i];
    int cur=s[1];
    for(int i=1;i<=n;i++) {
        cur=max(cur,s[i]);
        cout<<f[i]-cur<<' ';
        cur=f[i];
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