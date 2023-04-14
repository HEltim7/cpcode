#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e3+10;
int arr[N];

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n&&m;i+=3) arr[i]=1,m--;
    int ans=0;
    auto check=[&](int l,int r) {
        if(l>=1&&r<=n) return arr[l]+arr[l+1]+arr[r]>=2;
        return false;
    };
    for(int i=n;i>=1&&m;i--) if(arr[i]==0) arr[i]=1,m--;
    for(int i=2;i<n;i++) ans+=check(i-1,i+1);
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}