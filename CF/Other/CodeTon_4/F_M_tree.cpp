#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int arr[N];

void solve() {
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++) cin>>arr[i];
    int cnt=(n-1)/(m-1);
    while(q--) {
        int idx,nw;
        cin>>idx>>nw;

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