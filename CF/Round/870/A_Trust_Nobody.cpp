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
constexpr int N=110;
int arr[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sort(arr+1,arr+1+n);
    if(arr[n]==0) {
        cout<<0<<endl;
        return;
    }
    for(int i=1;i<=n;i++) {
        if(i<n&&arr[i+1]==arr[i]) continue;
        if(n-i>=arr[i]&&(i<n&&arr[i+1]>n-i)) {
            cout<<n-i<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}