#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
int arr[N];

void solve() {
    int n,k;
    cin>>n>>k;
    int ans=0;
    for(int i=1;i<=n;i++) cin>>arr[i];
    if(k==1) {
        cout<<(n-1)/2<<endl;
        return;
    }
    for(int i=1;i<=n;i++) if(i>1&&i<n&&arr[i]>arr[i-1]+arr[i+1]) ans++;
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