#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=110;
int arr[N];

void solve() {
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=2;i<=n;i++) {
        if(arr[i]%2==arr[i-1]%2) ans++;
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