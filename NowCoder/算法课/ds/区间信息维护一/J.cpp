#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
int h[N],dif[N];

void solve() {
    int n;
    cin>>n;

    for(int i=1;i<=n;i++) cin>>h[i];
    for(int i=1;i<=n;i++) dif[i]=h[i]-h[i-1];

    int ans=0;
    for(int i=1;i<=n;i++) ans+=dif[i]>0?dif[i]:0;
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}