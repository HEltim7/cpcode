#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
int arr[N];

void solve() {
    int n,maxx=0,ans=0,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i],maxx=max(maxx,arr[i]);
    for(int i=1;i<=n;i++) if(arr[i]==maxx) cnt++;
    for(int i=n,val=0;i>=1;i--) {
        if(arr[i]==maxx) break;
        else if(arr[i]>val) ans++,val=arr[i];
    }
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