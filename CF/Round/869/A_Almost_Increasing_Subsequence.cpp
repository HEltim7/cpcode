#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int arr[N];
bool inc[N];
int pre[N];

void solve() {
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++) {
        if(i==n||arr[i+1]>arr[i]||arr[i]>arr[i-1]) inc[i]=1;
    }
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+inc[i];
    while(q--) {
        int l,r;
        cin>>l>>r;
        if(l==r) cout<<1<<endl;
        else {
            int ans=max(pre[r-1]-pre[l],0)+2;
            cout<<ans<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}