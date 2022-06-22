#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
LL arr[N];

void solve() {
    int n;
    cin>>n;
    LL pos=0,neg=0;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=n;i>=1;i--) arr[i]-=arr[i-1];
    for(int i=2;i<=n;i++) 
        if(arr[i]<0) neg-=arr[i];
        else pos+=arr[i];
    arr[1]-=neg;
    LL ans=abs(arr[1])+pos+neg;
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