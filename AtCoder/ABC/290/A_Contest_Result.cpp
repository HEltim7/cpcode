#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=110;
int arr[N];

void solve() {
    int n,m;
    cin>>n>>m;
    LL sum=0;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=m;i++) {
        int in;
        cin>>in;
        sum+=arr[in];
    }
    cout<<sum<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}