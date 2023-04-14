#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
LL arr[N],pre[N];

void solve() {
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sort(arr+1,arr+1+n);
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+arr[i];
    while(q--) {
        int k,x;
        cin>>k>>x;
        int idx=upper_bound(arr+1,arr+1+n,x)-arr-1;
        cout<<pre[idx]-pre[max(0,idx-k)]<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}