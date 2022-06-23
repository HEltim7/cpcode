#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=110;
int arr[N];

void solve() {
    int n;
    cin>>n;
    int ans=n-1;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++)
        for(int k=1;k<n;k++) {
            for(int j=-200;j<=200;j++) {
                int res=n-1;
                for(int l=i-k,cur=arr[i]-j;l>=1&&abs(cur)<=100;l-=k,cur-=j)
                    if(arr[l]==cur) res--;
                for(int r=i+k,cur=arr[i]+j;r<=n&&abs(cur)<=100;r+=k,cur+=j)
                    if(arr[r]==cur) res--;
                ans=min(ans,res);
            }
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