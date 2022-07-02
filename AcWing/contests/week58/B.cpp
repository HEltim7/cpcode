#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
int arr[N];

void solve() {
    int n;
    cin>>n;
    int ans=1;
    for(int i=1;i<=n;i++) cin>>arr[i];
    int res=1;
    for(int i=2;i<=n;i++) {
        if(arr[i]>arr[i-1]*2) res=1;
        else res++;
        ans=max(ans,res);
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}