#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
int pre[N];

void solve() {
    int n,k;
    cin>>n>>k;
    string in;
    cin>>in;
    for(int i=0;i<n;i++) pre[i+1]=pre[i]+(in[i]=='W');
    int ans=n;
    for(int l=0,r=l+k;r<=n;l++,r++) ans=min(ans,pre[r]-pre[l]);
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