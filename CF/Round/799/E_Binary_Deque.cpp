#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
int arr[N];

void solve() {
    int n,s,sum=0;
    cin>>n>>s;
    for(int i=1;i<=n;i++) cin>>arr[i],sum+=arr[i];
    if(sum<s) cout<<-1<<endl;
    else {
        int l=1,r=n,ans=0;
        while(sum>s) sum-=arr[r--];
        for(;;) {
            ans=max(ans,r-l+1);
            sum-=arr[l++];
            while((sum<s||arr[r+1]==0)&&r<n) sum+=arr[++r];
            if(sum<s) break;
        }
        cout<<n-ans<<endl;
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